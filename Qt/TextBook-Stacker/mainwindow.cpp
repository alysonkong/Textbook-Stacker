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




//    QPixmap bkgnd("");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
//    QPalette palette;
//    //palette.setBrush(QPalette::Background, Qt::red);
//    this->setPalette(palette);

     pic_label = new QPushButton(); //this isn't really a background
     QPixmap pixmap(":/bkgnd/pixil-frame-0.png");
     QIcon ButtonIcon(pixmap);
     pic_label->setIcon(ButtonIcon);
     pic_label->setIconSize(pixmap.rect().size());



    //setFixedSize(400,400);
    QLabel *gametitle = new QLabel("Textbook Stacker");
    QFont f( "Arial", 30, QFont::Bold); //sets the font of the title
    gametitle->setFont(f);
    gametitle->setAlignment(Qt::AlignCenter);
    gametitle->setStyleSheet("QLabel { "

                                "color : black; "
                                "border: 2px solid yellow; "
                                "border-radius: 4px;}");

   // setStyleSheet("background-color : green");

    ui->setupUi(this);
    singleplayer = new QPushButton("Single Player");
    singleplayer->setStyleSheet("QPushButton { color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    multiplayer = new QPushButton("Multiplayer");
    multiplayer->setStyleSheet("QPushButton { color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    leaderboard = new QPushButton("Leaderboard");
    leaderboard->setStyleSheet("QPushButton { color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    helpbutton = new QPushButton("Help");
    helpbutton->setStyleSheet("QPushButton { color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    music = new QPushButton("Music");
    music->setStyleSheet("QPushButton { color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");

    QDockWidget *dock = new QDockWidget(this);
    dock->setWidget(music);

    buttonslayout = new QVBoxLayout;
    buttonslayout->addWidget(pic_label);
    buttonslayout->addWidget(gametitle, Qt::AlignCenter);
    buttonslayout->addWidget(singleplayer);
    buttonslayout->addWidget(multiplayer);
    buttonslayout->addWidget(leaderboard);
    buttonslayout->addWidget(helpbutton);

    QWidget *buttons = new QWidget;
    buttons->setLayout(buttonslayout);
    setCentralWidget(buttons);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

}

MainWindow::~MainWindow()
{
    delete ui;
}


