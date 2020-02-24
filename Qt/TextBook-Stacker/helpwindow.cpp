#include "helpwindow.h"
#include<QFontDatabase>
#include<QPixmap>

namespace HelpWindow{

//add pics, maybe screenshots
helpwindow::helpwindow() {


    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(ffamily, 40);

    QPixmap bkgd(":/bkgnd/textbookbkgndclear.png");
    bkgd = bkgd.scaled(this->size(), Qt::IgnoreAspectRatio); //sets background image to be the size of the window
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgd);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    layout = new QVBoxLayout;
    title = new QLabel("Instructions:");
    title->setFont(f);
    layout->addWidget(title, -1, Qt::AlignHCenter);

    instructions = new QLabel("The object of this game is to move the avatar left and right to catch the falling textbooks. \n"
                              "The user can use left and right arrow keys, or the 'A' key to go left and the 'D' key to go right. \n"
                              "There will be a list displaying which types of books and how many of each need to be caught. \n"
                              "Avoid catching the wrong textbook and getting any 'Fs'!! Good luck");
    instructions->setFont(f);
    instructions->setStyleSheet("QLabel { font-size: 20 px;}");
    layout->addWidget(instructions, -1, Qt::AlignCenter);


    returntomain = new QPushButton("Return to main");
    returntomain->setFont(f);
    returntomain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                              "border-width: 2px; border-color: solid yellow;}");
    layout->addWidget(returntomain, -1, Qt::AlignHCenter);
    layout->setAlignment(this, Qt::AlignHCenter);


    setLayout(layout);
    connect(returntomain, SIGNAL(clicked()), this, SLOT(returntomain()));

    //show();

    //index = ??;
}


void helpwindow::return_to_main() {
    emit pressed_main(1);
}


}

