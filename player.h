#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QWidget>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

class VideoPlayer : public QObject
{
    Q_OBJECT
public:
    explicit VideoPlayer(QWidget *videoWidget, QObject *parent = nullptr);
    ~VideoPlayer();

    void setFile(const QString &filePath);
    void play();
    void pause();
    void stop();

private:
    static gboolean busCallback(GstBus *bus, GstMessage *msg, gpointer data);
    void handleMessage(GstMessage *msg);

private:
    QWidget *m_videoWidget;
    GstElement *m_pipeline;
};

#endif
