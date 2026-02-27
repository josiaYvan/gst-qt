#include "Player.h"
#include <QDebug>

VideoPlayer::VideoPlayer(QWidget *videoWidget, QObject *parent)
    : QObject(parent),
    m_videoWidget(videoWidget),
    m_pipeline(nullptr)
{
    gst_init(nullptr, nullptr);

    // playbin simplifie tout
    m_pipeline = gst_element_factory_make("playbin", "player");

    if (!m_pipeline) {
        qCritical() << "Impossible de créer playbin";
        return;
    }

    // Bus
    GstBus *bus = gst_element_get_bus(m_pipeline);
    gst_bus_add_watch(bus, busCallback, this);
    gst_object_unref(bus);
}

VideoPlayer::~VideoPlayer()
{
    if (m_pipeline) {
        gst_element_set_state(m_pipeline, GST_STATE_NULL);
        gst_object_unref(m_pipeline);
    }
}

void VideoPlayer::setFile(const QString &filePath)
{
    QString uri = "file:///" + filePath;
    g_object_set(G_OBJECT(m_pipeline), "uri", uri.toUtf8().constData(), NULL);
}

void VideoPlayer::play()
{
    gst_element_set_state(m_pipeline, GST_STATE_PLAYING);

    // Attacher la vidéo à ton widget Qt
    WId winId = m_videoWidget->winId();
    gst_video_overlay_set_window_handle(
        GST_VIDEO_OVERLAY(m_pipeline),
        (guintptr)winId
        );
}

void VideoPlayer::pause()
{
    gst_element_set_state(m_pipeline, GST_STATE_PAUSED);
}

void VideoPlayer::stop()
{
    gst_element_set_state(m_pipeline, GST_STATE_READY);
}

gboolean VideoPlayer::busCallback(GstBus *bus, GstMessage *msg, gpointer data)
{
    VideoPlayer *player = static_cast<VideoPlayer *>(data);
    player->handleMessage(msg);
    return TRUE;
}

void VideoPlayer::handleMessage(GstMessage *msg)
{
    switch (GST_MESSAGE_TYPE(msg)) {

    case GST_MESSAGE_EOS:
        qDebug() << "Fin de lecture";
        stop();
        break;

    case GST_MESSAGE_ERROR:
    {
        GError *err;
        gchar *debug;
        gst_message_parse_error(msg, &err, &debug);
        qCritical() << "Erreur:" << err->message;
        g_error_free(err);
        g_free(debug);
        break;
    }

    default:
        break;
    }
}
