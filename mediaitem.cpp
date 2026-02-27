#include "mediaitem.h"
#include <QFileInfo>

MediaItem::MediaItem()
    : m_duration(0),
    m_fileSize(0),
    m_status(Ready)
{}

MediaItem::MediaItem(const QString &filePath)
    : m_filePath(filePath),
    m_duration(0),
    m_status(Ready)
{
    QFileInfo info(filePath);
    m_fileName = info.fileName();
    m_fileSize = info.size();
}

QString MediaItem::filePath() const
{
    return m_filePath;
}

QString MediaItem::fileName() const
{
    return m_fileName;
}

qint64 MediaItem::duration() const
{
    return m_duration;
}

qint64 MediaItem::fileSize() const
{
    return m_fileSize / 1024; // en KiloOctets
}

MediaItem::Status MediaItem::status() const
{
    return m_status;
}

void MediaItem::setStatus(Status status)
{
    m_status = status;
}

QString MediaItem::thumbnailPath() const
{
    return m_thumbnailPath;
}

qint64 MediaItem::bitrate() const
{
    return m_bitrate;
}

int MediaItem::width() const
{
    return m_width;
}

int MediaItem::height() const
{
    return m_height;
}

QString MediaItem::resolution() const
{
    return QString("%1x%2").arg(m_width).arg(m_height);
}

QString MediaItem::videoCodec() const
{
    return m_videoCodec;
}

double MediaItem::fps() const
{
    return m_fps;
}

QString MediaItem::audioCodec()  const
{
    return m_audioCodec;
}

int MediaItem::audioChannels() const
{
    return m_audioChannels;
}

int MediaItem::sampleRate() const
{
    return m_sampleRate;

}

void MediaItem::extractThumbnail() {
    if (m_filePath.isEmpty())
        return;

    QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/EmiaTV_thumbs";
    QDir().mkpath(tempDir);

    m_thumbnailPath = tempDir + "/" + QFileInfo(m_filePath).completeBaseName() + ".png";

    QProcess process;
    process.start("ffmpeg",
                  {"-y", "-ss", "00:00:01", "-i", m_filePath, "-frames:v", "1", m_thumbnailPath});

    if (!process.waitForFinished(-1)) { // ← attendre la fin
        qDebug() << "FFmpeg failed to finish!";
        return;
    }

    if (!QFile::exists(m_thumbnailPath)) {
        qDebug() << "Thumbnail was not created!";
    }
}
void MediaItem::extractMetadata()
{
    if (m_filePath.isEmpty()) {
        qDebug() << "extractMetadata: file path is empty!";
        return;
    }

    qDebug() << "========== EXTRACT METADATA ==========";
    qDebug() << "File:" << m_filePath;

    QProcess process;

    process.start("ffprobe", {
                                 "-v", "error",
                                 "-show_entries",
                                 "format=duration,bit_rate,size:stream=index,codec_type,codec_name,width,height,r_frame_rate,channels,sample_rate",
                                 "-of", "default=noprint_wrappers=1",
                                 m_filePath
                             });

    if (!process.waitForFinished(-1)) {
        qDebug() << "FFPROBE failed!";
        return;
    }

    QString output = process.readAllStandardOutput();
    qDebug().noquote() << output;

    QStringList lines = output.split("\n", Qt::SkipEmptyParts);

    for (const QString &line : lines)
    {
        if (line.startsWith("duration="))
            m_duration = line.section("=", 1).toDouble();

        else if (line.startsWith("bit_rate="))
            m_bitrate = line.section("=", 1).toLongLong();

        else if (line.startsWith("size="))
            m_fileSize = line.section("=", 1).toLongLong();

        else if (line.startsWith("width="))
            m_width = line.section("=", 1).toInt();

        else if (line.startsWith("height="))
            m_height = line.section("=", 1).toInt();

        else if (line.startsWith("codec_name=")) {
            QString codec = line.section("=", 1);
            if (m_videoCodec.isEmpty())
                m_videoCodec = codec;
            else
                m_audioCodec = codec;
        }

        else if (line.startsWith("r_frame_rate=")) {
            QString fpsStr = line.section("=", 1);
            QStringList parts = fpsStr.split("/");
            if (parts.size() == 2)
                m_fps = parts[0].toDouble() / parts[1].toDouble();
        }

        else if (line.startsWith("channels="))
            m_audioChannels = line.section("=", 1).toInt();

        else if (line.startsWith("sample_rate="))
            m_sampleRate = line.section("=", 1).toInt();
    }

    qDebug() << "---------- FINAL VALUES ----------";
    qDebug() << "Duration:" << m_duration << "sec";
    qDebug() << "Resolution:" << m_width << "x" << m_height;
    qDebug() << "FPS:" << m_fps;
    qDebug() << "Video Codec:" << m_videoCodec;
    qDebug() << "Audio Codec:" << m_audioCodec;
    qDebug() << "Audio Channels:" << m_audioChannels;
    qDebug() << "Sample Rate:" << m_sampleRate;
    qDebug() << "Bitrate:" << m_bitrate;
    qDebug() << "File Size (MB):" << (m_fileSize / 1024.0 / 1024.0);
    qDebug() << "===================================";
}

QString MediaItem::formattedDuration() const
{
    if (m_duration <= 0)
        return "00:00:00:00";

    // Supposons que m_duration est en secondes (et fraction de seconde).
    qint64 totalMilliseconds = static_cast<qint64>(m_duration * 1000);
    qint64 hrs  = totalMilliseconds / 3600000;
    qint64 mins = (totalMilliseconds % 3600000) / 60000;
    qint64 secs = (totalMilliseconds % 60000) / 1000;
    qint64 millis = totalMilliseconds % 1000 / 10; // Convertir en centi-secondes pour 2 chiffres

    return QString("%1:%2:%3:%4")
        .arg(hrs, 2, 10, QChar('0'))
        .arg(mins, 2, 10, QChar('0'))
        .arg(secs, 2, 10, QChar('0'))
        .arg(millis, 2, 10, QChar('0'));
}
