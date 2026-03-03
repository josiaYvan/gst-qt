#include "mainwindow.h"
#include "ui_mainwindow.h"*

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , settings(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Emia TV");

    playlist = new PlaylistManager(this);

    // CRUCIAL: Choisir le type de source ici
    // player = new VideoPlayer(VideoPlayer::SourceType::Camera, this);  // CAMÉRA
    player = new VideoPlayer(VideoPlayer::SourceType::File, this); // FICHIER

    // Pour fichier seulement :
    player->setFile("C:/Users/crakn/Videos/Ilay alim-bavaka tao Gestemane ｜ Miora Volanandrasana - Jessy Andersen.mp4");

    player->addVideoWidget(ui->video_preview);
    player->addVideoWidget(ui->video_live);
    player->addVideoWidget(ui->video_test);
    player->play();

    // Playlist setup (reste identique)
    playlistView = new PlaylistView(this);
    ui->layout_playlist->addWidget(playlistView);

    connect(playlistView, &PlaylistView::filesDropped, this, &MainWindow::handleFilesDropped);
    connect(playlistView, &PlaylistView::playlistReordered, this, &MainWindow::handleReorderPlaylist);

    // NOUVEAU: Boutons pour switcher (à connecter dans Qt Designer)
    connect(ui->btn_find_video_devices, &QPushButton::clicked, [this]() {
        stopCurrentPlayer();
        player = new VideoPlayer(VideoPlayer::SourceType::Camera, this);
        player->addVideoWidget(ui->video_preview);
        player->addVideoWidget(ui->video_live);
        player->addVideoWidget(ui->video_test);
        player->play();
        ui->statusbar->showMessage("Caméra activée", 3000);
    });

    connect(ui->btn_add_direct, &QPushButton::clicked, [this]() {
        stopCurrentPlayer();
        player = new VideoPlayer(VideoPlayer::SourceType::File, this);
        player->setFile("C:/Users/crakn/Videos/Ilay alim-bavaka tao Gestemane ｜ Miora Volanandrasana - Jessy Andersen.mp4");
        player->addVideoWidget(ui->video_preview);
        player->addVideoWidget(ui->video_live);
        player->addVideoWidget(ui->video_test);
        player->play();
        ui->statusbar->showMessage("Fichier activé", 3000);
    });
}

void MainWindow::stopCurrentPlayer()
{
    if (player) {
        player->stop();
        player->deleteLater();
        player = nullptr;
    }
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

void MainWindow::handleReorderPlaylist() {
    QStringList newOrder = playlistView->allVideos();
    playlist->reorder(newOrder);
}
