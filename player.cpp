#include "Player.h"
#include <QDebug>
#include <QOperatingSystemVersion>

VideoPlayer::VideoPlayer(SourceType type, QObject *parent)
    : QObject(parent)
    , m_type(type)
    , m_isPlaying(false)
{
    gst_init(nullptr, nullptr);

    pipeline = gst_pipeline_new("video-pipeline");

    if (m_type == SourceType::File) {
        source = gst_element_factory_make("filesrc", "source");
    } else {
#ifdef Q_OS_WIN
        source = gst_element_factory_make("ksvideosrc", "source");
        g_object_set(source, "device-index", 0, nullptr);
#else
        source = gst_element_factory_make("v4l2src", "source");
        g_object_set(source, "device", "/dev/video0", nullptr);
#endif
    }

    decodebin = gst_element_factory_make("decodebin", "decoder");
    tee = gst_element_factory_make("tee", "tee");

    if (!pipeline || !source || !decodebin || !tee) {
        qCritical() << "Erreur création éléments GStreamer";
        return;
    }

    gst_bin_add_many(GST_BIN(pipeline), source, decodebin, tee, NULL);
    gst_element_link(source, decodebin);

    // CORRECTION: Fonctions statiques avec gpointer(this)
    g_signal_connect(decodebin, "pad-added",
                     G_CALLBACK(onPadAddedFile), this);

    GstBus *bus = gst_element_get_bus(pipeline);
    gst_bus_add_watch(bus, busCallback, this);
    gst_object_unref(bus);
}

// FONCTION STATIQUE pour pads fichier
void VideoPlayer::onPadAddedFile(GstElement *src, GstPad *pad, gpointer data)
{
    VideoPlayer *player = static_cast<VideoPlayer*>(data);

    GstCaps *caps = gst_pad_get_current_caps(pad);
    if (!caps) return;

    GstStructure *structure = gst_caps_get_structure(caps, 0);
    const gchar *name = gst_structure_get_name(structure);

    if (g_str_has_prefix(name, "video/")) {
        GstPad *sinkPad = gst_element_get_static_pad(player->tee, "sink");
        if (sinkPad) {
            gst_pad_link(pad, sinkPad);
            gst_object_unref(sinkPad);
        }
    } else if (g_str_has_prefix(name, "audio/")) {
        GstElement *queue = gst_element_factory_make("queue", NULL);
        GstElement *convert = gst_element_factory_make("audioconvert", NULL);
        GstElement *resample = gst_element_factory_make("audioresample", NULL);
        GstElement *audioSink = gst_element_factory_make("autoaudiosink", NULL);

        gst_bin_add_many(GST_BIN(player->pipeline), queue, convert, resample, audioSink, NULL);
        gst_element_link_many(queue, convert, resample, audioSink, NULL);

        GstPad *sinkPad = gst_element_get_static_pad(queue, "sink");
        gst_pad_link(pad, sinkPad);
        gst_object_unref(sinkPad);

        gst_element_sync_state_with_parent(queue);
        gst_element_sync_state_with_parent(convert);
        gst_element_sync_state_with_parent(resample);
        gst_element_sync_state_with_parent(audioSink);
    }

    gst_caps_unref(caps);
}

VideoPlayer::~VideoPlayer()
{
    stop();
    if (pipeline) gst_object_unref(pipeline);
}

void VideoPlayer::setFile(const QString &filePath)
{
    if (m_type != SourceType::File) {
        qWarning() << "setFile() appelé sur une source caméra - ignoré";
        return;
    }
    g_object_set(source, "location", filePath.toUtf8().constData(), NULL);
}

void VideoPlayer::addVideoWidget(QWidget *widget)
{
    GstElement *queue = gst_element_factory_make("queue", NULL);
    GstElement *convert = gst_element_factory_make("videoconvert", NULL);
    GstElement *sink = gst_element_factory_make("d3d11videosink", NULL);

    if (!queue || !convert || !sink) {
        qCritical() << "Erreur création éléments vidéo";
        return;
    }

    gst_bin_add_many(GST_BIN(pipeline), queue, convert, sink, NULL);
    gst_element_link_many(queue, convert, sink, NULL);

    GstPad *teePad = gst_element_request_pad_simple(tee, "src_%u");
    GstPad *queuePad = gst_element_get_static_pad(queue, "sink");

    if (teePad && queuePad) {
        gst_pad_link(teePad, queuePad);
        gst_object_unref(queuePad);
    }
    if (teePad) gst_object_unref(teePad);

    gst_element_sync_state_with_parent(queue);
    gst_element_sync_state_with_parent(convert);
    gst_element_sync_state_with_parent(sink);

    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(sink), (guintptr)widget->winId());
}

void VideoPlayer::play()
{
    if (!m_isPlaying && pipeline) {
        GstStateChangeReturn ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
        if (ret == GST_STATE_CHANGE_FAILURE) {
            qCritical() << "Impossible de lancer la lecture";
        } else {
            m_isPlaying = true;
        }
    }
}

void VideoPlayer::stop()
{
    if (m_isPlaying && pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        m_isPlaying = false;
    }
}

void VideoPlayer::pause()
{
    if (m_isPlaying && pipeline) {
        gst_element_set_state(pipeline, GST_STATE_PAUSED);
        m_isPlaying = false;
    } else if (pipeline) {
        play();
    }
}

gboolean VideoPlayer::busCallback(GstBus *, GstMessage *msg, gpointer data)
{
    static_cast<VideoPlayer*>(data)->handleMessage(msg);
    return TRUE;
}

void VideoPlayer::handleMessage(GstMessage *msg)
{
    switch (GST_MESSAGE_TYPE(msg)) {
    case GST_MESSAGE_EOS:
        qDebug() << "Fin vidéo";
        stop();
        break;
    case GST_MESSAGE_ERROR:
    {
        GError *err;
        gchar *dbg;
        gst_message_parse_error(msg, &err, &dbg);
        qCritical() << "Erreur GStreamer:" << (err ? err->message : "Erreur inconnue");
        if (err) g_error_free(err);
        if (dbg) g_free(dbg);
        stop();
        break;
    }
    default:
        break;
    }
}
