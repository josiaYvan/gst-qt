#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settings(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Emia TV");

    playlist = new PlaylistManager(this);
    player = new VideoPlayer(this);
    player->setFile("C:/Users/crakn/Videos/Ilay alim-bavaka tao Gestemane ｜ Miora Volanandrasana - Jessy Andersen.mp4");

    // Première vue
    player->addVideoWidget(ui->video_preview);

    player->play();

    // -------PL VIEW--------------
    playlistView = new PlaylistView(this);
    ui->layout_playlist->addWidget(playlistView);

    connect(playlistView, &PlaylistView::filesDropped, this, &MainWindow::handleFilesDropped);

}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

void MainWindow::on_btn_setting_clicked()
{
    if (settings) {
        settings->raise();
        return;
    }

    settings = new Settings(this);
    settings->setAttribute(Qt::WA_DeleteOnClose, true);
    connect(settings, &QObject::destroyed, this, [this]() { settings = nullptr; });

    settings->show();
}


void MainWindow::handleFilesDropped(const QStringList &files)
{
    for (const QString &file : files) {
        processFile(file);
    }
}

void MainWindow::processFile(const QString &file)
{
    playlist->addMedia(file);
    QStandardItem *loadingItem = playlistView->addLoadingVideo(file);
    analyzeFileAsync(file, loadingItem);
}

void MainWindow::analyzeFileAsync(const QString &file, QStandardItem *loadingItem)
{
    QFuture<void> future = QtConcurrent::run([=]() {
        MediaItem item(file);
        item.extractMetadata();
        item.extractThumbnail();

        QMetaObject::invokeMethod(this, [=]() {
            playlistView->updateVideoItem(loadingItem, item);
        }, Qt::QueuedConnection);
    });
}
