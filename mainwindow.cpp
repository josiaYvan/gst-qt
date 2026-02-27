#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new VideoPlayer(ui->videoWidget, this);

    player->setFile("C:/Users/crakn/Videos/Ilay alim-bavaka tao Gestemane ｜ Miora Volanandrasana - Jessy Andersen.mp4");
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
