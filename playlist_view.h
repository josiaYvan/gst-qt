#pragma once
#include <QMenu>
#include <QListView>
#include <QStandardItemModel>
#include "mediaitem.h"

class PlaylistView : public QListView
{
    Q_OBJECT
public:
    explicit PlaylistView(QWidget *parent = nullptr);

    void addVideo(MediaItem *item);
    void removeMediaByPath(const QString &path);
    QStringList allVideos() const;
    QStandardItem* addLoadingVideo(const QString &file);
    void updateVideoItem(QStandardItem *stdItem, const MediaItem &item);

signals:
    void videoDoubleClicked(const QString &file);
    void videoSelected(const QString &file);
    void playlistReordered();
    void filesDropped(QStringList newFiles);
    void requestRemoveMedia(int row);
    void requestMoveMedia(int fromRow, int toRow);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    QStandardItemModel *m_model;
    void setupScrollBarStyle();
    void onContextMenu(const QPoint &pos);
};
