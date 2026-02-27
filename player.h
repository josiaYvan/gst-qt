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
    explicit VideoPlayer(QObject *parent = nullptr);
    ~VideoPlayer();

    void setFile(const QString &filePath);
    void addVideoWidget(QWidget *widget);
    void play();
    void stop();

private:
    static gboolean busCallback(GstBus *bus, GstMessage *msg, gpointer data);
    void handleMessage(GstMessage *msg);

private:
    GstElement *pipeline;
    GstElement *source;
    GstElement *decodebin;
    GstElement *tee;
};

#endif
