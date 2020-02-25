#include "helpwindow.h"
#include<QFontDatabase>
#include<QPixmap>

namespace HelpWindow{

//add pics, maybe screenshots
helpwindow::helpwindow() {

    //to display message with bubble font
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(ffamily, 40);

    //add background
    QPixmap bkgd(":/bkgnd/textbookbkgndclear.png");
    bkgd = bkgd.scaled(this->size(), Qt::IgnoreAspectRatio); //sets background image to be the size of the window
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgd);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //format title of window
    layout = new QVBoxLayout;
    title = new QLabel("Instructions:");
    title->setFont(f);
    layout->addWidget(title, -1, Qt::AlignHCenter); //add title to window layout


    //format instructions
    instructions = new QLabel("The object of this game is to move the avatar left and right \n"
                              "to catch the falling textbooks. The user can move horizontally \n"
                              "using either the left and right arrow keys or 'A' to go left \n"
                              "and 'D' to go right. There will be a list displaying which types \n"
                              "of books and how many of each need to be caught. Avoid catching \n"
                              "the wrong textbook and getting any 'Fs'!! Good luck");
    instructions->setFont(f);
    instructions->setStyleSheet("QLabel { font: 18pt;}");
    layout->addWidget(instructions, -1, Qt::AlignCenter); //add instructions to window layout


    //create button to return to the main screen
    returntomain = new QPushButton("Return to main");
    returntomain->setFont(f);
    returntomain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                              "border-width: 2px; border-color: solid yellow;}");
    layout->addWidget(returntomain, -1, Qt::AlignHCenter);
    layout->setAlignment(this, Qt::AlignHCenter);

    //set layout as the help window's layout
    setLayout(layout);
    connect(returntomain, SIGNAL(clicked()), this, SLOT(return_to_main())); //when returntomain button is pushed, mainwindow is displayed

    //show();
    //index
}


void helpwindow::return_to_main() {
    emit pressed_main(1);
}


}

