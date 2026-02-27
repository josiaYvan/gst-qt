#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H

#include <QObject>
#include <QList>
#include "MediaItem.h"

class PlaylistManager : public QObject
{
    Q_OBJECT
public:
    explicit PlaylistManager(QObject *parent = nullptr);

    int size() const;
    bool isEmpty() const;
    int currentIndex() const;

    void clear();
    void addMedia(const QString &filePath);
    void removeMediaByPath(const QString &filePath);
    void setCurrentIndex(int index);
    void reorder(const QStringList &newOrder);
    void moveMedia(int from, int to);  // ✅ NOUVEAU

    MediaItem current() const;
    MediaItem next();      // Avance et retourne
    MediaItem previous();  // Recule et retourne
    MediaItem nextFile() const;   // Peek next SANS avancer
    MediaItem previousFile() const; // Peek previous SANS reculer
    MediaItem getAt(int index) const;
    int getIndex(const QString &file) const;

    void setLoop(bool enabled);
    void setAutoClean(bool enabled);
    bool isLoop() const { return m_isLoop; }
    bool isAutoClean() const { return m_isAutoClean; }
    int count() const { return size(); }  // ✅ ALIAS pour MainWindow

signals:
    void mediaRemoved(const QString &filePath);
    void currentIndexChanged(int index);
    void playlistChanged();  // ✅ NOUVEAU

private:
    void updateStatuses();   // ✅ Helper interne

    QList<MediaItem> mPlaylist;
    int mCurrentIndex = -1;
    bool m_isLoop = false;
    bool m_isAutoClean = true;
};

#endif // PLAYLIST_MANAGER_H
