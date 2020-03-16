

#include "Lboardwindow.h"
#include<QFontDatabase>
#include<QPixmap>


namespace Leaderboardwindow{
    /**
     * @brief leaderboard::leaderboard() constructor, list namelists as empty
     */
    leaderboard::leaderboard() : namelists() {

        int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        f = QFont(family, 40); //sets the font to be used in other functions of leaderboard window as well


        //sets the background of the leaderboard
        QPixmap back(":/bkgnd/textbookbkgndclear.png");
        back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
        QPalette palette;
        palette.setBrush(QPalette::Background, back);
        this->setAutoFillBackground(true);
        this->setPalette(palette);


        layout = new QGridLayout; //sets up a gridlayout and add widgets to it

        lboard = new QLabel("Leaderboard");
        lboard->setFont(f);
        layout->addWidget(lboard, 0,0,1,-1, Qt::AlignHCenter);
        lboard->setStyleSheet("QLabel { color: white;}");


        QLabel* emptylist = new QLabel("No Leaders Yet!");
        emptylist->setFont(f);
        layout->addWidget(emptylist, 1,0,3,-1, Qt::AlignHCenter);


        returnmain = new QPushButton("Return to main");
        returnmain->setFont(f);
        returnmain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                                  "border-width: 2px; padding: 6px; border-color: solid yellow;}");
        connect(returnmain, SIGNAL(clicked()), this, SLOT(returntomain())); //if returnmain is clicked signal is emitted to mainwindow


        layout->addWidget(returnmain, 4,0,2,-1, Qt::AlignHCenter);
        layout->setAlignment(this, Qt::AlignHCenter);

        setLayout(layout);


    }

    /**
     * @brief leaderboard::returntomain slot connects leaderboard back to main window
     */
    void leaderboard::returntomain(){
        emit pressedmain(1);

    }

    /**
     * @brief leaderboard::updatedisplay is called when player loses the game or wins the game
     * @param name_ player name
     * @param n player score
     */
    void leaderboard::updatedisplay(const QString & name_, int n){
        leaders player(name_, n); //constructs a leader object
        bool change = false; //see if player's score is higher than any of the current scores
        if(namelists.size()>0){ //if the list is greater than 0
            for(auto i = 0; i < namelists.size(); i++){ //go through the list of scores
                if(player.getscore() > namelists[i].getscore()){ //if player score is greater than the current index score
                    namelists.insert(i, player); //insert player at that position
                    change = true;
                    break;
                }

            }
            if(!change){ //if player score is lower than all the current scores, push it to the back
                namelists.push_back(player);
            }

        }
        else{ //if list is 0, add player to list
            namelists.push_back(player);
        }


        QLayoutItem* item;
        while ( ( item = layout->takeAt( 0 ) ) != NULL )// go through all the widgets in the layout and delete them
        {
            delete item->widget();
            delete item;
        }


        lboard = new QLabel("Leaderboard");
        lboard->setFont(f);
        layout->addWidget(lboard, 0,0,1,-1, Qt::AlignHCenter);


        int count = 0;
        if(namelists.size()>0){ //if it's not an empty namelist
            for(auto i: namelists){ //iterate through each leader
                ++count;
                if(count <=5){ //don't want the number of labels displayed to be greater than 5
                    QLabel* temp = new QLabel(i.namescore()); //create a label out of the player name and score
                    temp->setFont(f);
                    layout->addWidget(temp,count,0,1,-1, Qt::AlignHCenter);
                }
                else{ //if number of labels exceed number of elements in list, don't add new labels
                    break;
                }
            }
            update();
        }

        returnmain = new QPushButton("Return to main");
        returnmain->setFont(f);
        returnmain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                                  "border-width: 2px; padding: 6px; border-color: solid yellow;}");


        layout->addWidget(returnmain, 7,0,2,-1, Qt::AlignHCenter);
        connect(returnmain, SIGNAL(clicked()), this, SLOT(returntomain()));

        setLayout(layout);
    }

}

