#include "loserwindow.h"
#include <QFontDatabase>
#include <QLabel>
#include <QPushButton>

/**
 * @brief loserwindow::loserwindow creates the window, displaying the user's final score
 * @param pn the player's name
 * @param pscore the player's final score
 */
loserwindow::loserwindow(QString pn, int pscore) : player_name(pn), score_value(pscore) {

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //add in imported font from resources
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //get the correct font name
    QFont f(family, 40);

    setFixedSize(1300,800); //set size of window
    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back); //set palette as the background image
    this->setAutoFillBackground(true);
    this->setPalette(palette); //set the background image palette to cover the entire window

    QLabel *title = new QLabel("You Lost! Your score is " + QString::number(score_value)); //displays user's final score
    title->setFont(f); //sets special font
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { border:none; color : white;}"); //adjusts label's style

    QPixmap losspic(":/spritesheets/lostkid.png"); //create pixmap with lost kid meme
    losspic = losspic.scaled(680,453,Qt::IgnoreAspectRatio); //resized the icon graphics
    QLabel* lost = new QLabel;
    lost->setPixmap(losspic); //sets label to be the lost kid picture

    QPushButton *main_menu = new QPushButton("Exit to Main"); //create button so user can return to mainwindow
    main_menu->setFont(f); //set special font and adjust display format
    main_menu->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 2px; border-color: white;}");

    //connect the signal from clicking the button so user returns to the main screen
    connect(main_menu, SIGNAL(clicked()), this, SIGNAL(pressedmain()));

    QPushButton *leaderboard = new QPushButton("Leaderboard"); //create button so user can go to leaderboard
    leaderboard->setFont(f); //set special font and adjust display format
    leaderboard->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 2px; border-color: white;}");
    //connect signal from clicking button to display leaderboard
    connect(leaderboard, SIGNAL(clicked()), this, SLOT(pressedLboard()));

    layout = new QGridLayout();
    layout->addWidget(title, 0, 0, 1, -1); //add message with user's final score to layout
    layout->addWidget(lost, 1,0,1,-1, Qt::AlignCenter); //add picture of lost kid
    layout->addWidget(main_menu, 2, 0, 1, -1, Qt::AlignCenter); //add return to main button
    layout->addWidget(leaderboard, 3, 0, 1, -1, Qt::AlignCenter); //add go to leaderboard button

    //set margins to use around layout
    layout->setContentsMargins( 100, 50, 100, 50);

    this->setLayout(layout);

    setWindowTitle("Loser Window"); //changes window title

    show(); //displays window

    //create loser window sad sound
    loser_sound = new QMediaPlayer();
    loser_sound->setMedia(QUrl("qrc:/music/loserwindow.mp3"));
    loser_sound->play(); //play sound
}

/**
 * @brief loserwindow::returntomain sends out signal to mainwindow to exit loser window and display mainwindow instead
 */
void loserwindow::returntomain(){
    emit pressedmain(); //emit pressedmain signal

}


/**
 * @brief loserwindow::pressedLboard sends out signal to exit loser window and go to leaderboard
 */
void loserwindow::pressedLboard(){
    emit gotolboard(player_name,score_value); //sends signal with player name and score
}

