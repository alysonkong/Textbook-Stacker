#include "winnerwindow.h"
#include <QFontDatabase>
#include <QLabel>
#include <QPushButton>

/**
 * @brief winnerwindow::winnerwindow constructs the window to display when user wins game, displaying user's final score
 * @param name the player's name
 * @param pscore the player's final score
 */
winnerwindow::winnerwindow(const QString& name, int pscore) : player_name(name), score_value(pscore) {

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //add in imported font from resources
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //get the correct font name
    QFont f(family, 40);

    setFixedSize(1300,800); //set size of window
    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back); //set palette as background image
    this->setAutoFillBackground(true);
    this->setPalette(palette); //sets background image palette to cover entire window

    QLabel *title = new QLabel("Congrats, " + player_name + "\nYou won!\nYour score is " + QString::number(score_value)); //displays user's final score
    title->setFont(f); //sets special font
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { border:none; color : white;}"); //adjust's label's style

    QPixmap winningpic(":/spritesheets/winningmeme.png"); //create pixmap for winning kid meme
    winningpic = winningpic.scaled(961*0.6,718*0.6,Qt::IgnoreAspectRatio); //resized the icon graphics
    QLabel* success = new QLabel;
    success->setPixmap(winningpic); //sets label to winning kid picture

    QPushButton *main_menu = new QPushButton("Exit to Main"); //create button to return to mainwindow
    main_menu->setFont(f); //sets font and adjusts display format
    main_menu->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 2px; border-color: white;}");

    //connect signal from clicking button to return to main screen
    connect(main_menu, SIGNAL(clicked()), this, SLOT(pressedmain()));

    QPushButton *leaderboard = new QPushButton("Leaderboard"); //create button to go to leaderboard
    leaderboard->setFont(f); //set font and adjust display format
    leaderboard->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 2px; border-color: white;}");

    //connects signal from clicking button to display leaderboard
    connect(leaderboard, SIGNAL(clicked()), this, SLOT(pressedLboard()));

    layout = new QGridLayout();
    layout->addWidget(title, 0, 0, 1, -1); //add winning message with final score to display
    layout->addWidget(success, 1,0,1,-1, Qt::AlignCenter); //adds success kid picture to display
    layout->addWidget(main_menu, 4, 0, 1, 1, Qt::AlignCenter); //adds return to main button to display
    layout->addWidget(leaderboard, 4, 1, 1, 1, Qt::AlignCenter); //adds leaderboard button to display

    //set margins to use around layout
    layout->setContentsMargins( 100, 50, 100, 50);

    this->setLayout(layout);

    setWindowTitle("Winner Window"); //changes window title

    show(); //displays window

    //create winner happy sound
    winning_sound = new QMediaPlayer();
    winning_sound->setMedia(QUrl("qrc:/music/winning.mp3"));
    winning_sound->play(); //play sound
}


/**
 * @brief winnerwindow::pressedmain sends out signal to exit winner window and return to main screen
 */
void winnerwindow::pressedmain(){
    emit returntomain(); //emit pressedmain signal
}


/**
 * @brief winnerwindow::pressedLboard sends out signal to exit winner window and display leaderboard
 */
void winnerwindow::pressedLboard() {
    emit gotoLboard(player_name, score_value); //sends signal with player name and score
}


