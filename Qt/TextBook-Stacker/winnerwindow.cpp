#include "winnerwindow.h"
#include <QFontDatabase>
#include <QLabel>
#include <QPushButton>

winnerwindow::winnerwindow(QString pname, int pscore) : player_name(pname), score_value(pscore) {
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //add in imported font from resources
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //get the correct font name
    QFont f(family, 40);

    setFixedSize(1300,800); //set size of window
    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    QLabel *title = new QLabel("Congrats, " + player_name + "!\nYou won!\nYour score is " + QString::number(score_value));
    title->setFont(f);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { border:none; color : white;}");

    QPushButton *main_menu = new QPushButton("Exit to Main");
    main_menu->setFont(f);
    main_menu->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 2px; border-color: white;}");

    //connect(main_menu, SIGNAL(clicked()), this, SLOT(returntomain()));
    connect(main_menu, SIGNAL(clicked()), this, SLOT(pressedmain()));

    QPushButton *leaderboard = new QPushButton("Leaderboard");
    leaderboard->setFont(f);
    leaderboard->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 2px; border-color: white;}");

    connect(leaderboard, SIGNAL(clicked()), this, SLOT(pressedLboard()));

    layout = new QGridLayout();
    layout->addWidget(title, -1, 0, 0, -1);
    layout->addWidget(main_menu, 4, 0, 1, -1, Qt::AlignCenter);
    layout->addWidget(leaderboard, 5, 0, 1, -1, Qt::AlignCenter);


    layout->setContentsMargins( 100, 50, 100, 50);

    this->setLayout(layout);

    setWindowTitle("Loser Window"); //changes window title

    show();
}

void winnerwindow::pressedmain(){
    emit returntomain(); //emit pressedmain signal
}

void winnerwindow::pressedLboard() {
    emit gotoLboard(player_name, score_value);
}

