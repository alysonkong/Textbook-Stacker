

#include "Lboardwindow.h"

namespace Leaderboardwindow{
    leaderboard::leaderboard() : namelists() {
        names = new QLabel("names");
        lboard = new QLabel("lboard");
        returnmain = new QPushButton("Return to main");
        layout = new QVBoxLayout;

        layout->addWidget(names);
        layout->addWidget(lboard);
        layout->addWidget(returnmain);
        setLayout(layout);
        connect(returnmain, SIGNAL(clicked()), this, SLOT(returntomain()));
        index = 1;
    }

    void leaderboard::returntomain(){
        emit pressedmain(1);

    }

    void leaderboard::pressedmain(int index){
        setCurrentIndex(index);
    }

}
