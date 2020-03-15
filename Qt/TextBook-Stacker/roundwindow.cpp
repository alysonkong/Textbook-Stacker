#include "roundwindow.h"
#include <QFontDatabase>
#include <QPushButton>

//roundwindow::roundwindow(QWidget *parent) : QWidget(parent)
//{

//}


roundwindow::roundwindow(int n): round(n){
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //add in imported font from resources
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //get the correct font name
    QFont f(family, 40);

    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    roundtext = new QLabel("Congrats! \n You Passed Round " + QString::number(round));
    roundtext->setFont(f);
    roundtext->setAlignment(Qt::AlignCenter);
    roundtext->setStyleSheet("QLabel { border:none; color : white;}");

    QPushButton *main_menu = new QPushButton("Exit to Main");
    main_menu->setFont(f);
    main_menu->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 5px; border-color: white;}");

    connect(main_menu, SIGNAL(clicked()), this, SIGNAL(returntomain()));

    QPushButton *nextround = new QPushButton("Next round");
    nextround->setFont(f);
    nextround->setStyleSheet("QPushButton { font-size: 24px; color : black; background-color: white; border-style: outset;"
                             "border-width: 5px; border-color: white;}");

    connect(nextround, SIGNAL(clicked()), this, SIGNAL(nextround()));

    QPixmap successpic(":/spritesheets/successbaby.png");
    successpic = successpic.scaled(1024*0.3,1088*0.3,Qt::IgnoreAspectRatio); //resized the icon graphics
    QLabel* success = new QLabel;
    success->setPixmap(successpic);

    layout = new QGridLayout();
    layout->addWidget(roundtext, 0, 0, 1, -1, Qt::AlignCenter);
    layout->addWidget(success, 1,0, 1, -1, Qt::AlignCenter);
    layout->addWidget(main_menu, 2, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(nextround, 2, 1, 1, 2, Qt::AlignCenter);

    setLayout(layout);
    setWindowTitle("Loser Window");
    show();

    newround_sound = new QMediaPlayer();
    newround_sound->setMedia(QUrl("qrc:/music/winning.mp3"));
    newround_sound->play();
//    if (newround_sound->state() == QMediaPlayer::PlayingState) {
//        newround_sound->setPosition(0);
//    }
//    else if (newround_sound->state() == QMediaPlayer::StoppedState) {
//        newround_sound->play();
//    }

}
