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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    //creates new font
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family, 40);


//    QPixmap bkgnd("");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
//    QPalette palette;
//    //palette.setBrush(QPalette::Background, Qt::red);
//    this->setPalette(palette);

//     pic_label = new QPushButton(); //this isn't really a background
//     QPixmap pixmap(":/bkgnd/pixil-frame-0.png");
//     QIcon ButtonIcon(pixmap);
//     pic_label->setIcon(ButtonIcon);
//     pic_label->setIconSize(pixmap.rect().size());



    setFixedSize(600,400);
    QLabel *gametitle = new QLabel("Textbook Stacker");
    gametitle->setFont(f);
    gametitle->setAlignment(Qt::AlignCenter);
    gametitle->setStyleSheet("QLabel { "
                                "color : black; "
                                "border: 2px solid yellow; "
                                "border-radius: 4px;}");

   // setStyleSheet("background-color : green");

    ui->setupUi(this);
    singleplayer = new QPushButton("Single Player");
    singleplayer->setFont(f);
    singleplayer->setStyleSheet("QPushButton { font-size: 26px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    multiplayer = new QPushButton("Multiplayer");
    multiplayer->setFont(f);
    multiplayer->setStyleSheet("QPushButton { font-size: 26px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    leaderboard = new QPushButton("Leaderboard");
    leaderboard->setFont(f);
    leaderboard->setStyleSheet("QPushButton { font-size: 26px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");


    helpbutton = new QPushButton("Help");
    helpbutton->setFont(f);
    helpbutton->setStyleSheet("QPushButton { font-size: 26px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    music = new QPushButton("Music");
    music->setFont(f);
    music->setStyleSheet("QPushButton { font-size: 14px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

//    QDockWidget *dock = new QDockWidget(this);
//    dock->setWidget(music);


    swindows = new QStackedWidget();
    lboard = new Leaderboardwindow::leaderboard();
    //swindows->addWidget(this);


    widgets = new QWidget();
    buttonslayout = new QVBoxLayout;
    //buttonslayout->addWidget(pic_label);
    buttonslayout->addWidget(gametitle, Qt::AlignCenter);
    buttonslayout->addWidget(singleplayer);
    buttonslayout->addWidget(multiplayer);
    buttonslayout->addWidget(leaderboard);
    buttonslayout->addWidget(helpbutton);
    widgets->setLayout(buttonslayout);


    swindows->addWidget(widgets);
    swindows->addWidget(lboard);


    widget2 = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(swindows);
    widget2->setLayout(layout);
    setCentralWidget(widget2);


    connect(leaderboard,SIGNAL(clicked()) , this, SLOT(lboarddisplay()));
    connect(lboard, SIGNAL(pressedmain()), this, SLOT(maindisplay()));

}

void  MainWindow::lboarddisplay(){
   // swindows->setCurrentIndex(swindows->indexOf(lboard));
    swindows->setCurrentWidget(lboard);
}


void MainWindow::maindisplay(){
    swindows->setCurrentWidget(widget2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


