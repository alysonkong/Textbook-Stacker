#include "helpwindow.h"

namespace HelpWindow{

//add pics, maybe screenshots
helpwindow::helpwindow() {
    title = new QLabel("Instructions:");
    returntomain = new QPushButton("Return to main");
    layout = new QVBoxLayout;
    instructions = new QLabel("The object of this game is to move the avatar left and right to catch the falling textbooks. \n"
                              "The user can use left and right arrow keys, or the 'A' key to go left and the 'D' key to go right. \n"
                              "There will be a list displaying which types of books and how many of each need to be caught. \n"
                              "Avoid catching the wrong textbook and getting any 'Fs'!! Good luck");

    layout->addWidget(title);
    layout->addWidget(returntomain);
    layout->addWidget(instructions);
    setLayout(layout);
    connect(returntomain, SIGNAL(clicked()), this, SLOT(returntomain()));

    show();

    //index = ??;
}


void helpwindow::return_to_main() {
    emit pressed_main(1);
}


}

