#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new VideoPlayer(this);
    player->setFile("C:/Users/crakn/Videos/Ilay alim-bavaka tao Gestemane ｜ Miora Volanandrasana - Jessy Andersen.mp4");

    // Première vue
    player->addVideoWidget(ui->videoWidget);

    player->play();

    // Bouton pour ajouter une nouvelle fenêtre
    connect(ui->btnAddView, &QPushButton::clicked, this, [=]() {

        QWidget *newWindow = new QWidget;
        newWindow->resize(800, 450);
        newWindow->show();

        player->addVideoWidget(newWindow);
    });

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

