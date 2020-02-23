/**
@file mainwindow.cpp
@author Alyson Kong
@brief This file contains the implementations of our main window
Pic 10C, UCLA
02/7/2020
"I pledge that I have neither given nor received unauthorized assistance on this assignment."
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFrame>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow), singlewindow(new Ui::singlewindow1)
{
    ui->setupUi(this);
    single = new QDialog();
    singlewindow->setupUi(single);
    //creates new font
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family, 40);


    QPixmap bkgnd(":/bkgnd/textbookbkgnd.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    song = new QMediaPlayer();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/music/Blazer Rail.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    song->setPlaylist(playlist);
    song->play();


    setFixedSize(950,650);
    QLabel *gametitle = new QLabel("Textbook Stacker");
    gametitle->setFont(f);
    gametitle->setAlignment(Qt::AlignCenter);
    gametitle->setStyleSheet("QLabel { border:none;}");


    singleplayer = new QPushButton(" Single Player ");
    singleplayer->setFont(f);
    singleplayer->setStyleSheet("QPushButton { font-size: 24px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    multiplayer = new QPushButton(" Multiplayer ");
    multiplayer->setFont(f);
    multiplayer->setStyleSheet("QPushButton { font-size: 24px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    leaderboard = new QPushButton(" Leaderboard ");
    leaderboard->setFont(f);
    leaderboard->setStyleSheet("QPushButton { font-size: 24px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");


    helpbutton = new QPushButton(" Help ");
    helpbutton->setFont(f);
    helpbutton->setStyleSheet("QPushButton { font-size: 24px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    QPixmap musicpic(":/icons/music.png");
    musicpic = musicpic.scaled(100,100,Qt::IgnoreAspectRatio);
    music_icon = new QPushButton(); //this isn't really a background
    QIcon ButtonIcon(musicpic);
    music_icon->setIcon(ButtonIcon);
    music_icon->setIconSize(musicpic.rect().size());
    music_icon->setStyleSheet("QPushButton { border:none;}");


    connect(music_icon,SIGNAL(clicked()), this, SLOT(musiconoff()));

//    QDockWidget *dock = new QDockWidget(this);
//    dock->setWidget(music);


    swindows = new QStackedWidget();
    lboard = new Leaderboardwindow::leaderboard();
   // singlewindow = new Ui::singlewindow1();

    //swindows->addWidget(this);

    QFrame* frame = new QFrame;
    frame->setStyleSheet( "QFrame{ border: 10px ; border-radius: 10px;}" );
    //frame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
   // frame.setFrameShape(QFrame.StyledPanel)
    //frame.setLineWidth(0.6)
    widgets = new QWidget();
    buttonslayout = new QGridLayout();
    //buttonslayout->addWidget(pic_label);


    buttonslayout->addWidget(gametitle, 0, 0, 1, -1);
    buttonslayout->addWidget(singleplayer, 1, 0, 1, -1, Qt::AlignCenter);
   // frame->resize( 200, 200 );
  //  buttonslayout->addWidget(frame);
    buttonslayout->addWidget(multiplayer, 2, 0, 1, -1, Qt::AlignCenter);
    buttonslayout->addWidget(leaderboard, 3, 0, 1,-1, Qt::AlignCenter);
    buttonslayout->addWidget(helpbutton, 4, 0, 1, -1, Qt::AlignCenter);
   // buttonslayout->addWidget(music);
   // buttonslayout->addWidget(frame, 5,2,1,1);
   // buttonslayout->addWidget(music_icon, 5,5,1,1);




    buttonslayout->setContentsMargins( 200, 100, 200, 100);
    widgets->setLayout(buttonslayout);
   // widgets->setStyleSheet("QWidget {border: 100 px}");
    QWidget * test = new QWidget();
    QGridLayout * trial = new QGridLayout();
    trial->addWidget(widgets);
    trial->addWidget(music_icon, 1, 0, Qt::AlignRight);
    test->setLayout(trial);

    swindows->addWidget(test);
    swindows->addWidget(lboard);
    swindows->addWidget(single);

    setCentralWidget(swindows);


    connect(leaderboard,SIGNAL(clicked()) , this, SLOT(lboarddisplay()));
    connect(singleplayer, SIGNAL(clicked()) , this, SLOT(splayerdisplay()));
    connect(lboard, SIGNAL(pressedmain(int)), this, SLOT(maindisplay()));
   // connect(single, SIGNAL(on_pushButton_clicked()), this, SLOT(maindisplay()));


    show();
}


void MainWindow::musiconoff(){
    if(song->state()==2){ //2 indicates paused state
        song->play();
    }
    else{
        song->pause();
    }
}

void  MainWindow::lboarddisplay(){
    swindows->setCurrentIndex(1);
    //swindows->setCurrentWidget(lboard);
}


void  MainWindow::splayerdisplay(){
    swindows->setCurrentIndex(2);
    //swindows->setCurrentWidget(lboard);
}

void MainWindow::maindisplay(){
    swindows->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


