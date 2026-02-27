#include "playlist_view.h"
#include "playlist_delegate.h"
#include <QScrollBar>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QDebug>

PlaylistView::PlaylistView(QWidget *parent)
    : QListView(parent)
{
    m_model = new QStandardItemModel(this);
    setModel(m_model);
    setItemDelegate(new PlaylistDelegate(this));
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Drag & drop interne
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::InternalMove);

    setupScrollBarStyle();

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &PlaylistView::customContextMenuRequested, this, &PlaylistView::onContextMenu);

    // Double-clic → videoSelected
    connect(this, &QListView::doubleClicked, this, [=](const QModelIndex &index){
        if (!index.isValid()) return;
        QString filePath = index.data(Qt::UserRole + 1).toString();
        if (!filePath.isEmpty())
            emit videoDoubleClicked(filePath);
    });

    connect(this, &QListView::clicked, this, [=](const QModelIndex &index){
        if (!index.isValid()) return;
        QString filePath = index.data(Qt::UserRole + 1).toString();
        if (!filePath.isEmpty())
            emit videoSelected(filePath);
    });
}

void PlaylistView::addVideo(MediaItem *item)
{
    if (!item) return;
    item->extractMetadata();
    item->extractThumbnail();

    QStandardItem *stdItem = new QStandardItem(item->fileName());
    stdItem->setData(item->fileName(), Qt::DisplayRole);
    stdItem->setData(item->filePath(), Qt::UserRole + 1);
    stdItem->setData(item->status() == MediaItem::Ready ? "READY" : "ON AIR", Qt::UserRole + 5);
    stdItem->setData(item->resolution(), Qt::UserRole + 7);
    stdItem->setData(item->fps(), Qt::UserRole + 8);
    stdItem->setData(item->videoCodec(), Qt::UserRole + 9);
    stdItem->setData(item->audioCodec(), Qt::UserRole + 10);
    stdItem->setData(item->audioChannels(), Qt::UserRole + 11);
    stdItem->setData(item->fileSize(), Qt::UserRole + 12);

    QPixmap thumb(item->thumbnailPath());
    stdItem->setData(thumb, Qt::UserRole + 6);

    // Duration
    stdItem->setData(QString("%1").arg(item->formattedDuration()), Qt::UserRole + 4);

    m_model->appendRow(stdItem);
}

QStandardItem* PlaylistView::addLoadingVideo(const QString &file)
{
    QStandardItem *item = new QStandardItem(QFileInfo(file).fileName());
    item->setData(file, Qt::UserRole + 1);
    item->setData("LOADING", Qt::UserRole + 5);
    m_model->appendRow(item);
    return item;
}

QStringList PlaylistView::allVideos() const
{
    QStringList list;
    for (int i = 0; i < m_model->rowCount(); ++i)
        list.append(m_model->item(i)->data(Qt::UserRole + 1).toString());
    return list;
}

void PlaylistView::updateVideoItem(QStandardItem *stdItem, const MediaItem &item)
{
    if (!stdItem) return;

    stdItem->setData(item.resolution(), Qt::UserRole + 7);
    stdItem->setData(item.fileSize(), Qt::UserRole + 12);
    stdItem->setData(item.formattedDuration(), Qt::UserRole + 4);

    QPixmap thumb(item.thumbnailPath());
    stdItem->setData(thumb, Qt::UserRole + 6);

    stdItem->setData("READY", Qt::UserRole + 5);
}

void PlaylistView::removeMediaByPath(const QString &path)
{
    auto model = qobject_cast<QStandardItemModel*>(this->model());
    if (!model) return;

    for (int i = 0; i < model->rowCount(); ++i) {
        QStandardItem *item = model->item(i);
        if (item->data(Qt::UserRole + 1).toString() == path) {
            model->removeRow(i);
            break;
        }
    }
}

void PlaylistView::setupScrollBarStyle()
{
    verticalScrollBar()->setStyleSheet(R"(
        QScrollBar:vertical { background: transparent; width: 6px; margin: 0px; }
        QScrollBar::handle:vertical { background: rgba(90,90,90,180); min-height: 20px; border-radius:3px; }
        QScrollBar::handle:vertical:hover { background: rgba(136,136,136,200); }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height:0px; }
        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background:none; }
    )");

    horizontalScrollBar()->setStyleSheet(R"(
        QScrollBar:horizontal { background: transparent; height: 6px; margin:0px; }
        QScrollBar::handle:horizontal { background: rgba(90,90,90,180); min-width:20px; border-radius:3px; }
        QScrollBar::handle:horizontal:hover { background: rgba(136,136,136,200); }
        QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { width:0px; }
        QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal { background:none; }
    )");
}

// --- Drag & Drop externe / interne ---
void PlaylistView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
    else
        QListView::dragEnterEvent(event); // drag interne
}

void PlaylistView::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

void PlaylistView::dropEvent(QDropEvent *event)
{
    // --- Drop externe (fichiers) ---
    if (event->mimeData()->hasUrls()) {
        QStringList newFiles;
        for (const QUrl &url : event->mimeData()->urls()) {
            QString filePath = url.toLocalFile();
            QString ext = QFileInfo(filePath).suffix().toLower();
            if (ext == "mp4" || ext == "mkv" || ext == "avi" || ext == "mov")
                newFiles.append(filePath);
        }
        if (!newFiles.isEmpty())
            emit filesDropped(newFiles);

        event->acceptProposedAction();
        return; // ne pas traiter comme drag interne
    }

    // --- Drag interne (réordonner items) ---
    QModelIndex sourceIndex = currentIndex();
    if (!sourceIndex.isValid()) {
        QListView::dropEvent(event);
        emit playlistReordered();
        return;
    }

    // Déterminer la ligne cible
    QModelIndex targetIndex = indexAt(event->position().toPoint());
    int targetRow;
    if (!targetIndex.isValid()) {
        if (event->position().y() < visualRect(m_model->index(0,0)).top())
            targetRow = 0;
        else
            targetRow = m_model->rowCount();
    } else {
        QRect rect = visualRect(targetIndex);
        int midY = rect.top() + rect.height() / 2;
        targetRow = targetIndex.row();
        if (event->position().y() > midY)
            targetRow += 1;
    }

    // Ne rien faire si la source = cible
    if (sourceIndex.row() == targetRow || sourceIndex.row() == targetRow - 1) {
        event->ignore();
        return;
    }

    // --- Déplacer proprement ---
    m_model->layoutAboutToBeChanged();
    QList<QStandardItem*> items = m_model->takeRow(sourceIndex.row()); // retire l’item source
    if (targetRow > m_model->rowCount()) targetRow = m_model->rowCount(); // sécurité
    m_model->insertRow(targetRow, items); // insère à la nouvelle position
    m_model->layoutChanged();

    event->acceptProposedAction();
    emit playlistReordered();
}

void PlaylistView::onContextMenu(const QPoint &pos)
{
    QModelIndex index = indexAt(pos);
    if (!index.isValid()) return;

    QMenu menu(this);
    QAction *removeAction = menu.addAction("Supprimer");
    QAction *moveUpAction = menu.addAction("Remonter");
    QAction *moveDownAction = menu.addAction("Descendre");

    QAction *selectedAction = menu.exec(viewport()->mapToGlobal(pos));
    if (!selectedAction) return;

    int row = index.row();

    if (selectedAction == removeAction) {
        emit requestRemoveMedia(row);
    } else if (selectedAction == moveUpAction) {
        if (row > 0) emit requestMoveMedia(row, row - 1);
    } else if (selectedAction == moveDownAction) {
        if (row < m_model->rowCount() - 1) emit requestMoveMedia(row, row + 1);
    }
}
