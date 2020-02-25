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


/**
Constructor for mainwindow containing the layout, stacked widget, background, fonts
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{


    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //add in imported font from resources
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //get the correct font name
    QFont f(family, 40);


    setFixedSize(1300,800); //set size of window
    QPixmap bkgnd(":/bkgnd/textbookbkgnd.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    song = new QMediaPlayer();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/music/Blazer Rail.wav")); //set sound to imported media file from resources
    playlist->setPlaybackMode(QMediaPlaylist::Loop); //play the song on a loop
    song->setPlaylist(playlist);
    song->play();



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
    musicpic = musicpic.scaled(100,100,Qt::IgnoreAspectRatio); //resized the icon graphics
    music_icon = new QPushButton();
    QIcon ButtonIcon(musicpic);
    music_icon->setIcon(ButtonIcon); //change pushbutton visual into the imported icon
    music_icon->setIconSize(musicpic.rect().size());
    music_icon->setStyleSheet("QPushButton { border:none;}");


    connect(music_icon,SIGNAL(clicked()), this, SLOT(musiconoff())); //clicking the music icon will turn music on or off

    //setting up stacked windows and the rest of the windows
    swindows = new QStackedWidget();
    lboard = new Leaderboardwindow::leaderboard();
    hwindow = new HelpWindow::helpwindow();
    namewindow = new nameinputwindow();
    twonameswindow = new twonamesinput();

    widgets = new QWidget(); //widgets contains the game title and buttons excluding music icon
    buttonslayout = new QGridLayout();
    buttonslayout->addWidget(gametitle, 0, 0, 1, -1);
    buttonslayout->addWidget(singleplayer, 1, 0, 1, -1, Qt::AlignCenter);
    buttonslayout->addWidget(multiplayer, 2, 0, 1, -1, Qt::AlignCenter);
    buttonslayout->addWidget(leaderboard, 3, 0, 1,-1, Qt::AlignCenter);
    buttonslayout->addWidget(helpbutton, 4, 0, 1, -1, Qt::AlignCenter);

    buttonslayout->setContentsMargins( 200, 100, 200, 100);
    widgets->setLayout(buttonslayout);

    QWidget * main = new QWidget(); //main is the homepage
    QGridLayout * mainlayout = new QGridLayout();
    mainlayout->addWidget(widgets);
    mainlayout->addWidget(music_icon, 1, 0, Qt::AlignRight);
    main->setLayout(mainlayout);

    swindows->addWidget(main);
    swindows->addWidget(lboard);
    swindows->addWidget(hwindow);
    swindows->addWidget(namewindow);
    swindows->addWidget(twonameswindow);

    connect(leaderboard,SIGNAL(clicked()) , this, SLOT(lboarddisplay())); //clicking leaderboard button set current stackedwidget to lboard
    connect(singleplayer, SIGNAL(clicked()) , this, SLOT(namewindowdisplay())); //clicking singleplayer button set current stackedwidget to lboard
    connect(multiplayer, SIGNAL(clicked()), this, SLOT(twonamesdisplay())); //clicking multiplayer button set current stackedwidget to lboard
    connect(lboard, SIGNAL(pressedmain(int)), this, SLOT(maindisplay())); //connecting lboard back to main
    connect(hwindow, SIGNAL(pressed_main(int)), this, SLOT(maindisplay())); //connecting helpwindow back to main
    connect(helpbutton, SIGNAL(clicked()), this, SLOT(hwindowdisplay())); //clicking helpbutton button set current stackedwidget to helpbutton
    connect(namewindow, SIGNAL(playername(QString)), this, SLOT(getname(QString))); //set up singleplayer window by getting nameinput window's edits
    connect(twonameswindow, SIGNAL(playernames(QString, QString)), this, SLOT(getnames(QString, QString))); //set up multiplayer window by getting twonameiput's edits

    setCentralWidget(swindows); //sets the stacked widget inside the mainwindow
    setWindowTitle("TextBook Stacker"); //changes window title

}

/**
 * @brief MainWindow::getname takes the QString user input from namewindow to create singleplayer window
 * @param n player name
 */
void MainWindow::getname(QString n){
    single_window = new singlewindow(n); //sets up singlewindow using the user input names
    swindows->addWidget(single_window);
    connect(single_window, SIGNAL(pressedmain()), this, SLOT(maindisplay()));
    connect(namewindow, SIGNAL(single_windowindex()), this, SLOT(splayerdisplay()));
}

/**
 * @brief MainWindow::getnames takes the QString user inputs from twonameswindow to create multiplayer window
 * @param n1 first player name
 * @param n2 second player name
 */
void MainWindow::getnames(QString n1, QString n2){
    gwindow = new gamewindow(n1, n2); //sets up gamewindow using the user input names
    swindows->addWidget(gwindow);
    connect(gwindow, SIGNAL(pressedmain()), this, SLOT(maindisplay()));
    connect(twonameswindow, SIGNAL(gamewindowindex()), this, SLOT(mplayerdisplay()));
}



/**
 * @brief MainWindow::musiconoff turns QMediaPlayer on or off
 */
void MainWindow::musiconoff(){
    if(song->state()==2){ //2 indicates paused state
        song->play();
    }
    else{
        song->pause();
    }
}

/**
 * @brief MainWindow::lboarddisplay set stackedwidget to leaderboard
 */
void  MainWindow::lboarddisplay(){
    swindows->setCurrentIndex(1);
    swindows->setCurrentWidget(lboard);
}

/**
 * @brief MainWindow::splayerdisplay set stackedwidget to singleplayer
 */
void  MainWindow::splayerdisplay(){
    swindows->setCurrentIndex(2);
    swindows->setCurrentWidget(single_window);
}

/**
 * @brief MainWindow::mplayerdisplay set stackedwidget to multiplayer
 */
void  MainWindow::mplayerdisplay(){
    swindows->setCurrentWidget(gwindow);
    //swindows->setCurrentWidget(lboard);
}

/**
 * @brief MainWindow::maindisplay set stackedwidget to homepage
 */
void MainWindow::maindisplay(){
    swindows->setCurrentIndex(0);
}

/**
 * @brief MainWindow::hwindowdisplay set stackedwidget to helpwindow
 */
void MainWindow::hwindowdisplay(){
    swindows->setCurrentIndex(2);
}

/**
 * @brief MainWindow::namewindowdisplay set stackedwidget to user input namewindow display
 */
void MainWindow::namewindowdisplay(){
    swindows->setCurrentIndex(3);
}

/**
 * @brief MainWindow::twonamesdisplay set stackedwidget to two user inputs isplay
 */
void MainWindow::twonamesdisplay(){
    swindows->setCurrentIndex(4);
}





