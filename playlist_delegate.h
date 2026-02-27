#ifndef PLAYLIST_DELEGATE_H
#define PLAYLIST_DELEGATE_H

#include <QStyledItemDelegate>

class PlaylistDelegate : public QStyledItemDelegate
{
public:
    explicit PlaylistDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
};

#endif
