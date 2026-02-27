#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <QString>
#include <QProcess>
#include <QDebug>
#include <QStandardPaths>
#include <QFileInfo>
#include <QProcess>
#include <QString>
#include <QRegularExpression>
#include <QDir>


class MediaItem
{
public:
    enum Status {
        Ready,
        OnAir,
        Played
    };

    MediaItem();
    MediaItem(const QString &filePath);

    int width() const;
    int height() const;
    double fps() const;
    Status status() const;
    int sampleRate() const;
    qint64 bitrate() const;
    qint64 duration() const;
    qint64 fileSize() const;
    QString filePath() const;
    QString fileName() const;
    int audioChannels() const;
    QString resolution() const;
    QString videoCodec() const;
    QString audioCodec() const;
    QString thumbnailPath() const;
    QString formattedDuration() const;

    void setStatus(Status status);
    void extractMetadata();
    void extractThumbnail();

private:
    QString m_filePath;
    QString m_fileName;
    qint64 m_fileSize;
    Status m_status;
    QString m_thumbnailPath;
    qint64 m_duration = 0;
    qint64 m_bitrate = 0;
    int m_width = 0;
    int m_height = 0;
    QString m_videoCodec;
    double m_fps = 0;
    QString m_audioCodec;
    int m_audioChannels = 0;
    int m_sampleRate = 0;



};

#endif
