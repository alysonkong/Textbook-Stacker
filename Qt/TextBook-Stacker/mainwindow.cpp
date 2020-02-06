#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
     //ui(new Ui::MainWindow)
{
    setFixedSize(400,400);
    QLabel *gametitle = new QLabel("Textbook Stacker");
    QFont f( "Arial", 30, QFont::Bold);
    gametitle->setFont(f);
    gametitle->setAlignment(Qt::AlignCenter);
    gametitle->setStyleSheet("QLabel { "
                                 "background-color : black; "
                                "color : white; "
                                "border: 2px solid yellow; "
                                "border-radius: 4px;}");

    setStyleSheet("background-color : green");

    //ui->setupUi(this);
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
    //delete ui;
}


