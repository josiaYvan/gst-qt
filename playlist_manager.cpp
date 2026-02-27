#include "playlist_manager.h"
#include <QDebug>

PlaylistManager::PlaylistManager(QObject *parent)
    : QObject(parent)
{
    qDebug() << "[PLAYLIST] Manager initialized";
}

int PlaylistManager::size() const
{
    return mPlaylist.size();
}

bool PlaylistManager::isEmpty() const
{
    return mPlaylist.isEmpty();
}

int PlaylistManager::currentIndex() const
{
    return mCurrentIndex;
}

void PlaylistManager::clear()
{
    if (mPlaylist.isEmpty()) return;

    qDebug() << "[PLAYLIST] Clearing" << mPlaylist.size() << "items";
    mPlaylist.clear();
    mCurrentIndex = -1;
    emit playlistChanged();
}

void PlaylistManager::addMedia(const QString &filePath)
{
    if (filePath.isEmpty()) {
        qWarning() << "[PLAYLIST] Cannot add empty file path";
        return;
    }

    MediaItem item(filePath);
    mPlaylist.append(item);

    if (mCurrentIndex == -1) {
        mCurrentIndex = 0;
        emit currentIndexChanged(0);
    }

    qDebug() << "[PLAYLIST] Added:" << filePath << "- total:" << mPlaylist.size();
    emit playlistChanged();
}

void PlaylistManager::removeMediaByPath(const QString &filePath)
{
    int idx = getIndex(filePath);
    if (idx < 0) {
        qWarning() << "[PLAYLIST] File not found:" << filePath;
        return;
    }

    qDebug() << "[PLAYLIST] Removing:" << filePath << "at index" << idx;
    mPlaylist.removeAt(idx);

    // ✅ FIX : Gestion index robuste
    if (mPlaylist.isEmpty()) {
        mCurrentIndex = -1;
    } else if (mCurrentIndex > idx) {
        mCurrentIndex--;  // Décalage
    } else if (mCurrentIndex >= mPlaylist.size()) {
        mCurrentIndex = mPlaylist.size() - 1;
    }

    emit mediaRemoved(filePath);
    emit playlistChanged();
}

void PlaylistManager::moveMedia(int from, int to)
{
    if (from < 0 || from >= mPlaylist.size() ||
        to < 0 || to >= mPlaylist.size() || from == to) {
        qWarning() << "[PLAYLIST] Invalid move:" << from << "->" << to;
        return;
    }

    qDebug() << "[PLAYLIST] Moving" << from << "to" << to;
    mPlaylist.move(from, to);

    // Ajuste currentIndex si nécessaire
    if (mCurrentIndex == from) {
        mCurrentIndex = to;
    } else if (mCurrentIndex > from && mCurrentIndex <= to) {
        mCurrentIndex--;
    } else if (mCurrentIndex < from && mCurrentIndex >= to) {
        mCurrentIndex++;
    }

    emit currentIndexChanged(mCurrentIndex);
    emit playlistChanged();
}

MediaItem PlaylistManager::current() const
{
    if (mCurrentIndex >= 0 && mCurrentIndex < mPlaylist.size())
        return mPlaylist[mCurrentIndex];
    return MediaItem();
}

MediaItem PlaylistManager::next()
{
    if (mPlaylist.isEmpty()) {
        qDebug() << "[PLAYLIST] next() - empty";
        return MediaItem();
    }

    // ✅ FIX : Logique boucle améliorée
    if (mCurrentIndex + 1 >= mPlaylist.size()) {
        if (m_isLoop) {
            mCurrentIndex = 0;
        } else {
            qDebug() << "[PLAYLIST] End of playlist reached";
            return MediaItem();
        }
    } else {
        mCurrentIndex++;
    }

    updateStatuses();
    emit currentIndexChanged(mCurrentIndex);
    qDebug() << "[PLAYLIST] Next -> index" << mCurrentIndex;

    return current();
}

MediaItem PlaylistManager::previous()
{
    if (mPlaylist.isEmpty())
        return MediaItem();

    if (mCurrentIndex - 1 < 0) {
        if (m_isLoop) {
            mCurrentIndex = mPlaylist.size() - 1;
        } else {
            return MediaItem();
        }
    } else {
        mCurrentIndex--;
    }

    updateStatuses();
    emit currentIndexChanged(mCurrentIndex);
    return current();
}

MediaItem PlaylistManager::nextFile() const
{
    if (mPlaylist.isEmpty())
        return MediaItem();

    int nextIndex = mCurrentIndex + 1;
    if (nextIndex >= mPlaylist.size()) {
        if (m_isLoop)
            nextIndex = 0;
        else
            return MediaItem();
    }

    return mPlaylist[nextIndex];
}

MediaItem PlaylistManager::previousFile() const
{
    if (mPlaylist.isEmpty())
        return MediaItem();

    int prevIndex = mCurrentIndex - 1;
    if (prevIndex < 0) {
        if (m_isLoop)
            prevIndex = mPlaylist.size() - 1;
        else
            return MediaItem();
    }

    return mPlaylist[prevIndex];
}

MediaItem PlaylistManager::getAt(int index) const
{
    if (index >= 0 && index < mPlaylist.size())
        return mPlaylist[index];

    qWarning() << "[PLAYLIST] Invalid index:" << index;
    return mPlaylist.isEmpty() ? MediaItem() : mPlaylist[0];
}

int PlaylistManager::getIndex(const QString &file) const
{
    for (int i = 0; i < mPlaylist.size(); ++i) {
        if (mPlaylist[i].filePath() == file)
            return i;
    }
    return -1;
}

void PlaylistManager::setCurrentIndex(int index)
{
    if (index >= 0 && index < mPlaylist.size() && mCurrentIndex != index) {
        mCurrentIndex = index;
        updateStatuses();
        emit currentIndexChanged(index);
        qDebug() << "[PLAYLIST] Current index set to" << index;
    }
}

void PlaylistManager::reorder(const QStringList &newOrder)
{
    QList<MediaItem> newPlaylist;
    for (const QString &file : newOrder) {
        int idx = getIndex(file);
        if (idx != -1) {
            newPlaylist.append(mPlaylist[idx]);
        }
    }

    if (newPlaylist.size() != mPlaylist.size()) {
        qWarning() << "[PLAYLIST] Reorder incomplete:" << newPlaylist.size() << "/" << mPlaylist.size();
    }

    mPlaylist = newPlaylist;

    // Ajuste currentIndex
    if (mCurrentIndex >= mPlaylist.size()) {
        mCurrentIndex = mPlaylist.isEmpty() ? -1 : 0;
    }

    emit currentIndexChanged(mCurrentIndex);
    emit playlistChanged();
}

void PlaylistManager::setLoop(bool enabled)
{
    if (m_isLoop != enabled) {
        m_isLoop = enabled;
        qDebug() << "[PLAYLIST] Loop:" << (enabled ? "ON" : "OFF");
        emit playlistChanged();
    }
}

void PlaylistManager::setAutoClean(bool enabled)
{
    m_isAutoClean = enabled;
    qDebug() << "[PLAYLIST] AutoClean:" << (enabled ? "ON" : "OFF");
}

void PlaylistManager::updateStatuses()
{
    for (int i = 0; i < mPlaylist.size(); ++i) {
        mPlaylist[i].setStatus(i == mCurrentIndex ? MediaItem::OnAir : MediaItem::Ready);
    }
}
