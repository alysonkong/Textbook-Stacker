

#include "Lboardwindow.h"
#include<QFontDatabase>
#include<QPixmap>


namespace Leaderboardwindow{
    /**
     * @brief leaderboard::leaderboard() constructor, vector namelists as empty
     */
    leaderboard::leaderboard() : namelists() {

        int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont f(family, 40);



        QPixmap back(":/bkgnd/textbookbkgndclear.png");
        back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
        QPalette palette;
        palette.setBrush(QPalette::Background, back);
        this->setAutoFillBackground(true);
        this->setPalette(palette);


        layout = new QVBoxLayout;


        lboard = new QLabel("Leaderboard");
        lboard->setFont(f);
        layout->addWidget(lboard, -1, Qt::AlignHCenter);


        namelists.push_back(leaderboard::leaders(QString::fromStdString("Abigail"), 200));
        namelists.push_back(leaderboard::leaders(QString::fromStdString("Brian"), 150));
        namelists.push_back(leaderboard::leaders(QString::fromStdString("Caesar"), 100));
        namelists.push_back(leaderboard::leaders(QString::fromStdString("Doris"), 50));
        namelists.push_back(leaderboard::leaders(QString::fromStdString("Eric"), 25));

        size_t count =0;
        for(auto i: namelists){
            QLabel *name = new QLabel(namelists[count].namescore());
            name->setFont(f);
            name->setStyleSheet("QLabel { font: 40pt;}");
            count++;
            layout->addWidget(name, -1, Qt::AlignCenter);

        }


        returnmain = new QPushButton("Return to main");
        returnmain->setFont(f);
        returnmain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                                  "border-width: 2px; border-color: solid yellow;}");


        layout->addWidget(returnmain, -1, Qt::AlignHCenter);
        layout->setAlignment(this, Qt::AlignHCenter);

        setLayout(layout);
        connect(returnmain, SIGNAL(clicked()), this, SLOT(returntomain()));

    }

    /**
     * @brief leaderboard::returntomain slot connects leaderboard back to main window
     */
    void leaderboard::returntomain(){
        emit pressedmain(1);

    }

    //not relevant yet
    void leaderboard::getplayerscore(){

    }


}
