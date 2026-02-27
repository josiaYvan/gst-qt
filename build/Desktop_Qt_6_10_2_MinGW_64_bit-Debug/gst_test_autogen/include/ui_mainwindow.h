/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_28;
    QWidget *widget_15;
    QLabel *label_14;
    QLabel *ongoing_title;
    QGroupBox *video_live;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_16;
    QWidget *widget_18;
    QVBoxLayout *verticalLayout_32;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_10;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_4;
    QLabel *played_time_label;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_11;
    QWidget *widget_14;
    QVBoxLayout *verticalLayout;
    QLabel *current_time_label;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_12;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_3;
    QLabel *remaining_time_label;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *publish_live;
    QCheckBox *open_preview;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_29;
    QWidget *widget_16;
    QLabel *label_15;
    QLabel *next_title;
    QGroupBox *video_preview;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_13;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_19;
    QVBoxLayout *verticalLayout_7;
    QLabel *remaining_time_label_2;
    QWidget *widget_20;
    QCheckBox *loop_checkbox;
    QCheckBox *autoCleanPlaylist;
    QPushButton *btn_setting;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *layout_timeline;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *widget;
    QWidget *widget_13;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layout_playlist;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_31;
    QFrame *preview_control;
    QVBoxLayout *verticalLayout_30;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_current_time;
    QSlider *horizontalSlider_duration;
    QLabel *label_total_time;
    QFrame *frame_15;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_seekb;
    QPushButton *pushButton_playpause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_seekf;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_volume;
    QSlider *horizontalSlider_volume;
    QWidget *playout_control;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_17;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_take_next;
    QPushButton *btn_take_selected;
    QPushButton *btn_take_live;
    QPushButton *btn_blackOut;
    QWidget *widget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1528, 1059);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
"color: rgb(208, 208, 208);\n"
"border-radius: 5px;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_10 = new QVBoxLayout(centralwidget);
        verticalLayout_10->setObjectName("verticalLayout_10");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(1080, 230));
        frame_2->setMaximumSize(QSize(16777215, 230));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 41, 41);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_5 = new QWidget(frame_2);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(290, 164));
        widget_5->setMaximumSize(QSize(290, 16777215));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
""));
        verticalLayout_28 = new QVBoxLayout(widget_5);
        verticalLayout_28->setObjectName("verticalLayout_28");
        verticalLayout_28->setContentsMargins(4, 4, 4, 4);
        widget_15 = new QWidget(widget_5);
        widget_15->setObjectName("widget_15");
        widget_15->setMaximumSize(QSize(16777215, 20));
        label_14 = new QLabel(widget_15);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 0, 41, 20));
        label_14->setMinimumSize(QSize(0, 0));
        label_14->setMaximumSize(QSize(16777215, 20));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(82, 116, 25);"));
        ongoing_title = new QLabel(widget_15);
        ongoing_title->setObjectName("ongoing_title");
        ongoing_title->setGeometry(QRect(50, 0, 221, 20));
        ongoing_title->setMinimumSize(QSize(0, 20));
        ongoing_title->setMaximumSize(QSize(221, 20));

        verticalLayout_28->addWidget(widget_15);

        video_live = new QGroupBox(widget_5);
        video_live->setObjectName("video_live");
        video_live->setMinimumSize(QSize(282, 180));
        video_live->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);border-radius: 3px;"));

        verticalLayout_28->addWidget(video_live);


        horizontalLayout->addWidget(widget_5);

        frame_7 = new QFrame(frame_2);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(600, 0));
        frame_7->setMaximumSize(QSize(16777215, 200));
        frame_7->setAutoFillBackground(false);
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 38, 38);"));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_16 = new QVBoxLayout(frame_7);
        verticalLayout_16->setObjectName("verticalLayout_16");
        widget_18 = new QWidget(frame_7);
        widget_18->setObjectName("widget_18");
        widget_18->setMaximumSize(QSize(16777215, 16777215));
        widget_18->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 21, 21);"));
        verticalLayout_32 = new QVBoxLayout(widget_18);
        verticalLayout_32->setObjectName("verticalLayout_32");
        widget_8 = new QWidget(widget_18);
        widget_8->setObjectName("widget_8");
        widget_8->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        label_10 = new QLabel(widget_8);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(16777215, 20));

        verticalLayout_17->addWidget(label_10);

        widget_11 = new QWidget(widget_8);
        widget_11->setObjectName("widget_11");
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 21, 21);"));
        verticalLayout_4 = new QVBoxLayout(widget_11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        played_time_label = new QLabel(widget_11);
        played_time_label->setObjectName("played_time_label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Digital Dismay")});
        font.setPointSize(22);
        played_time_label->setFont(font);
        played_time_label->setStyleSheet(QString::fromUtf8("color: rgb(82, 116, 25);"));
        played_time_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(played_time_label);


        verticalLayout_17->addWidget(widget_11);


        horizontalLayout_8->addLayout(verticalLayout_17);

        widget_10 = new QWidget(widget_8);
        widget_10->setObjectName("widget_10");
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
""));
        verticalLayout_5 = new QVBoxLayout(widget_10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(-1, 9, -1, -1);
        label_11 = new QLabel(widget_10);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_18->addWidget(label_11);

        widget_14 = new QWidget(widget_10);
        widget_14->setObjectName("widget_14");
        widget_14->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
""));
        verticalLayout = new QVBoxLayout(widget_14);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, -1, 20, -1);
        current_time_label = new QLabel(widget_14);
        current_time_label->setObjectName("current_time_label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Digital Dismay")});
        font1.setPointSize(40);
        current_time_label->setFont(font1);
        current_time_label->setStyleSheet(QString::fromUtf8("color: rgb(69, 146, 161);"));
        current_time_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(current_time_label);


        verticalLayout_18->addWidget(widget_14);


        verticalLayout_5->addLayout(verticalLayout_18);


        horizontalLayout_8->addWidget(widget_10);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        label_12 = new QLabel(widget_8);
        label_12->setObjectName("label_12");
        label_12->setMaximumSize(QSize(16777215, 20));
        label_12->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_19->addWidget(label_12);

        widget_12 = new QWidget(widget_8);
        widget_12->setObjectName("widget_12");
        widget_12->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 21, 21);"));
        verticalLayout_3 = new QVBoxLayout(widget_12);
        verticalLayout_3->setObjectName("verticalLayout_3");
        remaining_time_label = new QLabel(widget_12);
        remaining_time_label->setObjectName("remaining_time_label");
        remaining_time_label->setFont(font);
        remaining_time_label->setStyleSheet(QString::fromUtf8("color: rgb(106, 106, 106);"));
        remaining_time_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(remaining_time_label);


        verticalLayout_19->addWidget(widget_12);


        horizontalLayout_8->addLayout(verticalLayout_19);


        verticalLayout_32->addWidget(widget_8);


        verticalLayout_16->addWidget(widget_18);

        widget_7 = new QWidget(frame_7);
        widget_7->setObjectName("widget_7");
        widget_7->setMaximumSize(QSize(16777215, 50));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
""));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        publish_live = new QCheckBox(widget_7);
        publish_live->setObjectName("publish_live");

        horizontalLayout_5->addWidget(publish_live);

        open_preview = new QCheckBox(widget_7);
        open_preview->setObjectName("open_preview");
        open_preview->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        horizontalLayout_5->addWidget(open_preview);


        verticalLayout_16->addWidget(widget_7);


        horizontalLayout->addWidget(frame_7);

        widget_6 = new QWidget(frame_2);
        widget_6->setObjectName("widget_6");
        widget_6->setMinimumSize(QSize(290, 0));
        widget_6->setMaximumSize(QSize(290, 16777215));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
""));
        verticalLayout_29 = new QVBoxLayout(widget_6);
        verticalLayout_29->setSpacing(4);
        verticalLayout_29->setObjectName("verticalLayout_29");
        verticalLayout_29->setContentsMargins(4, 4, 4, 4);
        widget_16 = new QWidget(widget_6);
        widget_16->setObjectName("widget_16");
        widget_16->setMaximumSize(QSize(16777215, 20));
        label_15 = new QLabel(widget_16);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 0, 41, 20));
        label_15->setMinimumSize(QSize(0, 0));
        label_15->setMaximumSize(QSize(16777215, 20));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(82, 116, 25);"));
        next_title = new QLabel(widget_16);
        next_title->setObjectName("next_title");
        next_title->setGeometry(QRect(40, 0, 221, 20));
        next_title->setMinimumSize(QSize(0, 0));
        next_title->setMaximumSize(QSize(221, 20));

        verticalLayout_29->addWidget(widget_16);

        video_preview = new QGroupBox(widget_6);
        video_preview->setObjectName("video_preview");
        video_preview->setMinimumSize(QSize(282, 180));
        video_preview->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);border-radius: 3px;"));

        verticalLayout_29->addWidget(video_preview);


        horizontalLayout->addWidget(widget_6);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(0, 0));
        label_13->setMaximumSize(QSize(16777215, 65));
        label_13->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_20->addWidget(label_13);

        widget_9 = new QWidget(frame_2);
        widget_9->setObjectName("widget_9");
        widget_9->setMaximumSize(QSize(290, 200));
        verticalLayout_8 = new QVBoxLayout(widget_9);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(-1, 0, -1, -1);
        widget_19 = new QWidget(widget_9);
        widget_19->setObjectName("widget_19");
        widget_19->setMaximumSize(QSize(16777215, 16777215));
        widget_19->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 31, 31);\n"
""));
        verticalLayout_7 = new QVBoxLayout(widget_19);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(9, 0, 9, 0);
        remaining_time_label_2 = new QLabel(widget_19);
        remaining_time_label_2->setObjectName("remaining_time_label_2");
        remaining_time_label_2->setMaximumSize(QSize(16777215, 60));
        remaining_time_label_2->setFont(font);
        remaining_time_label_2->setStyleSheet(QString::fromUtf8("color: rgb(106, 106, 106);"));
        remaining_time_label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(remaining_time_label_2);


        verticalLayout_8->addWidget(widget_19);

        widget_20 = new QWidget(widget_9);
        widget_20->setObjectName("widget_20");
        widget_20->setMaximumSize(QSize(16777215, 150));
        loop_checkbox = new QCheckBox(widget_20);
        loop_checkbox->setObjectName("loop_checkbox");
        loop_checkbox->setGeometry(QRect(9, 11, 91, 16));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        loop_checkbox->setFont(font2);
        loop_checkbox->setAutoFillBackground(false);
        autoCleanPlaylist = new QCheckBox(widget_20);
        autoCleanPlaylist->setObjectName("autoCleanPlaylist");
        autoCleanPlaylist->setGeometry(QRect(9, 35, 94, 16));
        btn_setting = new QPushButton(widget_20);
        btn_setting->setObjectName("btn_setting");
        btn_setting->setGeometry(QRect(200, 20, 30, 30));
        btn_setting->setMinimumSize(QSize(30, 30));
        btn_setting->setAutoFillBackground(false);
        btn_setting->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-color: rgb(57, 57, 57);color: rgb(173, 173, 173);"));

        verticalLayout_8->addWidget(widget_20);


        verticalLayout_20->addWidget(widget_9);


        horizontalLayout->addLayout(verticalLayout_20);


        verticalLayout_10->addWidget(frame_2);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(0, 90));
        widget_4->setMaximumSize(QSize(16777215, 90));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 41, 41);"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        layout_timeline = new QHBoxLayout();
        layout_timeline->setObjectName("layout_timeline");

        horizontalLayout_4->addLayout(layout_timeline);


        verticalLayout_10->addWidget(widget_4);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Orientation::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(250, 0));
        widget->setMaximumSize(QSize(300, 16777215));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 41, 41);"));
        splitter->addWidget(widget);
        widget_13 = new QWidget(splitter);
        widget_13->setObjectName("widget_13");
        widget_13->setMinimumSize(QSize(600, 0));
        widget_13->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 41, 41);"));
        verticalLayout_2 = new QVBoxLayout(widget_13);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        layout_playlist = new QVBoxLayout();
        layout_playlist->setObjectName("layout_playlist");

        verticalLayout_2->addLayout(layout_playlist);

        splitter->addWidget(widget_13);
        widget_3 = new QWidget(splitter);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(600, 0));
        widget_3->setMaximumSize(QSize(900, 16777215));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 41, 41);"));
        verticalLayout_31 = new QVBoxLayout(widget_3);
        verticalLayout_31->setObjectName("verticalLayout_31");
        preview_control = new QFrame(widget_3);
        preview_control->setObjectName("preview_control");
        preview_control->setMinimumSize(QSize(0, 120));
        preview_control->setMaximumSize(QSize(16777215, 120));
        preview_control->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        preview_control->setFrameShape(QFrame::Shape::StyledPanel);
        preview_control->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_30 = new QVBoxLayout(preview_control);
        verticalLayout_30->setObjectName("verticalLayout_30");
        frame_14 = new QFrame(preview_control);
        frame_14->setObjectName("frame_14");
        frame_14->setMinimumSize(QSize(0, 40));
        frame_14->setMaximumSize(QSize(16777215, 40));
        frame_14->setFrameShape(QFrame::Shape::StyledPanel);
        frame_14->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_14 = new QHBoxLayout(frame_14);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_current_time = new QLabel(frame_14);
        label_current_time->setObjectName("label_current_time");
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        label_current_time->setFont(font3);

        horizontalLayout_14->addWidget(label_current_time);

        horizontalSlider_duration = new QSlider(frame_14);
        horizontalSlider_duration->setObjectName("horizontalSlider_duration");
        horizontalSlider_duration->setStyleSheet(QString::fromUtf8("color: rgb(69, 146, 161);"));
        horizontalSlider_duration->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_14->addWidget(horizontalSlider_duration);

        label_total_time = new QLabel(frame_14);
        label_total_time->setObjectName("label_total_time");
        label_total_time->setFont(font3);

        horizontalLayout_14->addWidget(label_total_time);


        verticalLayout_30->addWidget(frame_14);

        frame_15 = new QFrame(preview_control);
        frame_15->setObjectName("frame_15");
        frame_15->setMinimumSize(QSize(100, 60));
        frame_15->setMaximumSize(QSize(16777215, 60));
        frame_15->setFrameShape(QFrame::Shape::StyledPanel);
        frame_15->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame_15);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        pushButton_seekb = new QPushButton(frame_15);
        pushButton_seekb->setObjectName("pushButton_seekb");
        pushButton_seekb->setMinimumSize(QSize(30, 30));
        pushButton_seekb->setAutoFillBackground(false);
        pushButton_seekb->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-color: rgb(57, 57, 57);color: rgb(173, 173, 173);"));

        horizontalLayout_15->addWidget(pushButton_seekb);

        pushButton_playpause = new QPushButton(frame_15);
        pushButton_playpause->setObjectName("pushButton_playpause");
        pushButton_playpause->setMinimumSize(QSize(30, 30));
        pushButton_playpause->setAutoFillBackground(false);
        pushButton_playpause->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-color: rgb(57, 57, 57);color: rgb(173, 173, 173);"));

        horizontalLayout_15->addWidget(pushButton_playpause);

        pushButton_stop = new QPushButton(frame_15);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setMinimumSize(QSize(30, 30));
        pushButton_stop->setAutoFillBackground(false);
        pushButton_stop->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-color: rgb(57, 57, 57);color: rgb(173, 173, 173);"));

        horizontalLayout_15->addWidget(pushButton_stop);

        pushButton_seekf = new QPushButton(frame_15);
        pushButton_seekf->setObjectName("pushButton_seekf");
        pushButton_seekf->setMinimumSize(QSize(30, 30));
        pushButton_seekf->setAutoFillBackground(false);
        pushButton_seekf->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-color: rgb(57, 57, 57);\n"
"color: rgb(173, 173, 173);"));

        horizontalLayout_15->addWidget(pushButton_seekf);

        horizontalSpacer_12 = new QSpacerItem(60, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_12);

        pushButton_volume = new QPushButton(frame_15);
        pushButton_volume->setObjectName("pushButton_volume");
        pushButton_volume->setMinimumSize(QSize(30, 30));
        pushButton_volume->setAutoFillBackground(false);
        pushButton_volume->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"border-color: rgb(57, 57, 57);color: rgb(173, 173, 173);"));

        horizontalLayout_15->addWidget(pushButton_volume);

        horizontalSlider_volume = new QSlider(frame_15);
        horizontalSlider_volume->setObjectName("horizontalSlider_volume");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider_volume->sizePolicy().hasHeightForWidth());
        horizontalSlider_volume->setSizePolicy(sizePolicy1);
        horizontalSlider_volume->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_15->addWidget(horizontalSlider_volume);


        verticalLayout_30->addWidget(frame_15);


        verticalLayout_31->addWidget(preview_control);

        playout_control = new QWidget(widget_3);
        playout_control->setObjectName("playout_control");
        playout_control->setMaximumSize(QSize(16777215, 50));
        verticalLayout_6 = new QVBoxLayout(playout_control);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_17 = new QWidget(playout_control);
        widget_17->setObjectName("widget_17");
        widget_17->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(widget_17);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btn_take_next = new QPushButton(widget_17);
        btn_take_next->setObjectName("btn_take_next");
        btn_take_next->setMinimumSize(QSize(0, 30));
        btn_take_next->setAutoFillBackground(false);
        btn_take_next->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"        background-color: #515151;\n"
"        color: white;\n"
"        border-radius: 4px;\n"
"        padding: 4px 12px;\n"
"    }\n"
"    QPushButton:disabled {\n"
"        background-color: #353535;\n"
"        color: #666666;\n"
"    }"));

        horizontalLayout_2->addWidget(btn_take_next);

        btn_take_selected = new QPushButton(widget_17);
        btn_take_selected->setObjectName("btn_take_selected");
        btn_take_selected->setMinimumSize(QSize(0, 30));
        btn_take_selected->setAutoFillBackground(false);
        btn_take_selected->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"        background-color: #515151;\n"
"        color: white;\n"
"        border-radius: 4px;\n"
"        padding: 4px 12px;\n"
"    }\n"
"    QPushButton:disabled {\n"
"        background-color: #353535;\n"
"        color: #666666;\n"
"    }"));

        horizontalLayout_2->addWidget(btn_take_selected);

        btn_take_live = new QPushButton(widget_17);
        btn_take_live->setObjectName("btn_take_live");
        btn_take_live->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setBold(true);
        btn_take_live->setFont(font4);
        btn_take_live->setAutoFillBackground(false);
        btn_take_live->setStyleSheet(QString::fromUtf8("border-color: rgb(57, 57, 57);\n"
"background-color: rgb(199, 29, 32);"));

        horizontalLayout_2->addWidget(btn_take_live);

        btn_blackOut = new QPushButton(widget_17);
        btn_blackOut->setObjectName("btn_blackOut");
        btn_blackOut->setMinimumSize(QSize(0, 30));
        btn_blackOut->setFont(font4);
        btn_blackOut->setAutoFillBackground(false);
        btn_blackOut->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);\n"
"border-color: rgb(57, 57, 57);\n"
"color: rgb(99, 99, 99);"));

        horizontalLayout_2->addWidget(btn_blackOut);


        verticalLayout_6->addWidget(widget_17);


        verticalLayout_31->addWidget(playout_control);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");

        verticalLayout_31->addWidget(widget_2);

        splitter->addWidget(widget_3);
        splitter_2->addWidget(splitter);

        verticalLayout_10->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1528, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "ON AIR", nullptr));
        ongoing_title->setText(QCoreApplication::translate("MainWindow", "LIVE", nullptr));
        video_live->setTitle(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Played", nullptr));
        played_time_label->setText(QCoreApplication::translate("MainWindow", "00:00:00:00", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Current Time", nullptr));
        current_time_label->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Remaining", nullptr));
        remaining_time_label->setText(QCoreApplication::translate("MainWindow", "00:00:00:00", nullptr));
        publish_live->setText(QCoreApplication::translate("MainWindow", "Publish", nullptr));
        open_preview->setText(QCoreApplication::translate("MainWindow", "Open preview", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        next_title->setText(QCoreApplication::translate("MainWindow", "Jingle", nullptr));
        video_preview->setTitle(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Remaining time to playlist end", nullptr));
        remaining_time_label_2->setText(QCoreApplication::translate("MainWindow", "00:00:00:00", nullptr));
        loop_checkbox->setText(QCoreApplication::translate("MainWindow", "Loop playlist", nullptr));
        autoCleanPlaylist->setText(QCoreApplication::translate("MainWindow", "Clean playlist", nullptr));
        btn_setting->setText(QString());
        label_current_time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_total_time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pushButton_seekb->setText(QString());
        pushButton_playpause->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_seekf->setText(QString());
        pushButton_volume->setText(QString());
        horizontalSlider_volume->setAccessibleIdentifier(QCoreApplication::translate("MainWindow", "color: rgb(69, 146, 161);", nullptr));
        btn_take_next->setText(QCoreApplication::translate("MainWindow", "TAKE NEXT", nullptr));
        btn_take_selected->setText(QCoreApplication::translate("MainWindow", "TAKE SELECTED", nullptr));
        btn_take_live->setText(QCoreApplication::translate("MainWindow", "TAKE LIVE", nullptr));
        btn_blackOut->setText(QCoreApplication::translate("MainWindow", "BLACK OUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
