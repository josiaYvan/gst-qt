#ifndef PLAYLIST_MANAGER_H
#define PLAYLIST_MANAGER_H

#include <QObject>

class PlaylistManager : public QObject
{
    Q_OBJECT
public:
    explicit PlaylistManager(QObject *parent = nullptr);

signals:
};

#endif // PLAYLIST_MANAGER_H
