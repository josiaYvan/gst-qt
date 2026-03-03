#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

class VideoPlayer : public QObject
{
    Q_OBJECT
public:
    enum class SourceType { File, Camera };

    explicit VideoPlayer(SourceType type = SourceType::File, QObject *parent = nullptr);
    ~VideoPlayer();

    void setFile(const QString &filePath);
    void addVideoWidget(QWidget *widget);
    void play();
    void stop();
    void pause();

private slots:
    void handleMessage(GstMessage *msg);

private:
    static gboolean busCallback(GstBus *bus, GstMessage *msg, gpointer data);
    static void onPadAddedFile(GstElement *src, GstPad *pad, gpointer data);
    static void onPadAddedCam(GstElement *src, GstPad *pad, gpointer data);

    GstElement *pipeline;
    GstElement *source;
    GstElement *decodebin;
    GstElement *tee;

    SourceType m_type;
    bool m_isPlaying;
};

#endif // PLAYER_H
