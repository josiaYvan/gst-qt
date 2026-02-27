#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTime>
#include <QTimer>
#include <QtConcurrent>
#include <QMainWindow>
#include <QPushButton>
#include <QStandardItem>
#include "Player.h"
#include "settings.h"
#include "playlist_view.h"
#include "playlist_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_setting_clicked();

private:
    Ui::MainWindow *ui;
    Settings *settings;
    VideoPlayer *player;
    PlaylistView *playlistView;
    PlaylistManager *playlist;

    void handleFilesDropped(const QStringList &files);
    void processFile(const QString &file);
    void analyzeFileAsync(const QString &file, QStandardItem *loadingItem);
};
#endif // MAINWINDOW_H
