#include "Player.h"
#include <QDebug>

VideoPlayer::VideoPlayer(QObject *parent)
    : QObject(parent)
{
    gst_init(nullptr, nullptr);

    pipeline = gst_pipeline_new("video-pipeline");

    source = gst_element_factory_make("filesrc", "source");
    decodebin = gst_element_factory_make("decodebin", "decoder");
    tee = gst_element_factory_make("tee", "tee");

    gst_bin_add_many(GST_BIN(pipeline), source, decodebin, tee, NULL);
    gst_element_link(source, decodebin);

    // Quand decodebin crée un pad dynamique
    g_signal_connect(decodebin, "pad-added", G_CALLBACK(+[](
                                                             GstElement *src, GstPad *pad, gpointer data)
                                                        {
                                                            VideoPlayer *player = static_cast<VideoPlayer*>(data);

                                                            GstCaps *caps = gst_pad_get_current_caps(pad);
                                                            const gchar *name = gst_structure_get_name(gst_caps_get_structure(caps, 0));

                                                            if (g_str_has_prefix(name, "video/")) {

                                                                GstPad *sinkPad = gst_element_get_static_pad(player->tee, "sink");
                                                                gst_pad_link(pad, sinkPad);
                                                                gst_object_unref(sinkPad);

                                                            } else if (g_str_has_prefix(name, "audio/")) {

                                                                GstElement *queue = gst_element_factory_make("queue", NULL);
                                                                GstElement *convert = gst_element_factory_make("audioconvert", NULL);
                                                                GstElement *resample = gst_element_factory_make("audioresample", NULL);
                                                                GstElement *audioSink = gst_element_factory_make("autoaudiosink", NULL);

                                                                gst_bin_add_many(GST_BIN(player->pipeline),
                                                                                 queue, convert, resample, audioSink, NULL);

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

                                                        }), this);

    GstBus *bus = gst_element_get_bus(pipeline);
    gst_bus_add_watch(bus, busCallback, this);
    gst_object_unref(bus);
}

VideoPlayer::~VideoPlayer()
{
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
}

void VideoPlayer::setFile(const QString &filePath)
{
    g_object_set(source, "location", filePath.toUtf8().constData(), NULL);
}

void VideoPlayer::addVideoWidget(QWidget *widget)
{
    GstElement *queue = gst_element_factory_make("queue", NULL);
    GstElement *convert = gst_element_factory_make("videoconvert", NULL);
    GstElement *sink = gst_element_factory_make("d3d11videosink", NULL);

    gst_bin_add_many(GST_BIN(pipeline), queue, convert, sink, NULL);
    gst_element_link_many(queue, convert, sink, NULL);

    // relier tee → queue
    GstPad *teePad = gst_element_request_pad_simple(tee, "src_%u");
    GstPad *queuePad = gst_element_get_static_pad(queue, "sink");
    gst_pad_link(teePad, queuePad);

    gst_object_unref(queuePad);

    gst_element_sync_state_with_parent(queue);
    gst_element_sync_state_with_parent(convert);
    gst_element_sync_state_with_parent(sink);

    // Attacher au widget Qt
    gst_video_overlay_set_window_handle(
        GST_VIDEO_OVERLAY(sink),
        (guintptr)widget->winId()
        );
}

void VideoPlayer::play()
{
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
}

void VideoPlayer::stop()
{
    gst_element_set_state(pipeline, GST_STATE_NULL);
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
        qCritical() << err->message;
        g_error_free(err);
        g_free(dbg);
        break;
    }
    default:
        break;
    }
}
