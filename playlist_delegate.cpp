#include "playlist_delegate.h"
#include <QPainter>
#include <QApplication>

PlaylistDelegate::PlaylistDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void PlaylistDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    painter->save();

    // --- Espace entre items (padding est de 2px) ---
    QRect rect = option.rect.adjusted(0, 1, 0, -1);

    // --- Couleur de fond alternée ---
    QColor bgColor = (index.row() % 2 == 0) ? QColor(42, 42, 42) : QColor(31, 31, 31);
    painter->fillRect(rect, bgColor);

    // --- Barre de statut ---
    QString status = index.data(Qt::UserRole + 5).toString();
    QColor barColor = Qt::gray;
    if (status == "ON AIR") barColor = Qt::red;
    else if (status == "READY") barColor = QColor(0, 200, 0);
    else if (status == "ERROR") barColor = Qt::darkRed;
    painter->fillRect(QRect(rect.left(), rect.top(), 6, rect.height()), barColor);

    // --- Miniature ---
    QPixmap thumb = index.data(Qt::UserRole + 6).value<QPixmap>();
    QRect thumbRect(rect.left() + 10, rect.top(), 80, rect.height());
    if (!thumb.isNull())
        painter->drawPixmap(thumbRect, thumb.scaled(thumbRect.size(),
                                                    Qt::KeepAspectRatioByExpanding,
                                                    Qt::SmoothTransformation));

    int xOffset = thumbRect.right() + 10;
    // Calculer la largeur totale de l'élément
    int totalWidth = rect.width();

    // Largeurs pour les colonnes
    int titleWidth = totalWidth / 2;          // 50% pour le titre
    int otherColumnsWidth = totalWidth / 2;   // 50% restant pour les trois autres colonnes

    // Largeur pour chaque colonne des 3 autres (début, fin, durée)
    int colWidth = otherColumnsWidth / 3; // Répartition égale entre les 3 autres colonnes

    // Position des colonnes
    int colTitle = xOffset; // Position du titre
    int colStart = colTitle + titleWidth; // Colonne de début décalée à droite
    int colEnd = colStart + colWidth; // Colonne de fin à droite de colStart
    int colDuration = colEnd + colWidth; // Colonne de durée à droite de colEnd
    // --- Dessiner les bordures pour la sélection et le survol ---
    if (option.state & QStyle::State_Selected) {
        painter->setPen(QColor(0, 204, 204, 90)); // Couleur de bordure turquoise pour la sélection
        painter->drawRect(rect); // Dessine un rectangle autour de l'élément sélectionné
    } else if (option.state & QStyle::State_MouseOver) {
        painter->setPen(QColor(0, 204, 204, 50)); // Couleur de bordure adoucie pour le survol
        painter->drawRect(rect); // Dessi   ne un rectangle autour de l'élément survolé
    }

    // --- Titre ---
    painter->setPen(QColor(180, 180, 180));
    QFont titleFont = QApplication::font();
    titleFont.setPointSize(10);
    painter->setFont(titleFont);
    painter->drawText(QRect(colTitle, rect.top() + 5, 200, 20), Qt::AlignLeft, index.data(Qt::DisplayRole).toString());

    // --- Métadonnées (optionnel) ---
    painter->setPen(QColor(100, 100, 100));
    QFont metaFont = QApplication::font();
    metaFont.setPointSize(9);
    painter->setFont(metaFont);

    QString resolution = index.data(Qt::UserRole + 7).toString();
    double fileSizeMB = index.data(Qt::UserRole + 12).toDouble();
    QString line1 = resolution + "  -  " + QString::number(fileSizeMB, 'f', 1) + " KB";
    painter->drawText(QRect(colTitle, rect.top() + 25, 200, 16),
                      Qt::AlignCenter | Qt::AlignLeft,
                      line1);

    // --- Colonnes Start / End ---
    painter->setPen(QColor(180, 180, 180));
    QString startTime = index.data(Qt::UserRole + 2).toString();
    QString endTime = index.data(Qt::UserRole + 3).toString();
    QString duration = index.data(Qt::UserRole + 4).toString();

    int yLine = rect.top() + 18; // Ligne sous metadata

    // Afficher l'heure de début (aligné au centre)
    painter->drawText(QRect(colStart, yLine, 60, 16),
                      Qt::AlignCenter,
                      startTime + " Times");

    // Afficher l'heure de fin (aligné au centre)
    painter->drawText(QRect(colEnd, yLine, 60, 16),
                      Qt::AlignCenter,
                      endTime + " Times");

    // Afficher la durée (aligné à droite)
    painter->drawText(QRect(colDuration, yLine, 60, 16),
                      Qt::AlignRight | Qt::AlignVCenter,
                      duration);

    painter->restore();
}

QSize PlaylistDelegate::sizeHint(const QStyleOptionViewItem &,
                                 const QModelIndex &) const
{
    int itemHeight = 55; // Hauteur augmentée
    int spacing = 2;     // Espacement vertical
    return QSize(100, itemHeight + spacing);
}
