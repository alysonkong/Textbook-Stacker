

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
        f = QFont(family, 40);



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


//        namelists.push_back(leaderboard::leaders(QString::fromStdString("Abigail"), 200));
//        namelists.push_back(leaderboard::leaders(QString::fromStdString("Brian"), 150));
//        namelists.push_back(leaderboard::leaders(QString::fromStdString("Caesar"), 100));
//        namelists.push_back(leaderboard::leaders(QString::fromStdString("Doris"), 50));
//        namelists.push_back(leaderboard::leaders(QString::fromStdString("Eric"), 25));

//        size_t count =0;
//        for(auto i: namelists){
//            QLabel *name = new QLabel(namelists[count].namescore());
//            name->setFont(f);
//            name->setStyleSheet("QLabel { font: 40pt;}");
//            count++;
//            layout->addWidget(name, -1, Qt::AlignCenter);

//        }

        QLabel* emptylist = new QLabel("No Leaders Yet!");
        emptylist->setFont(f);

        layout->addWidget(emptylist, -1, Qt::AlignHCenter);



        returnmain = new QPushButton("Return to main");
        returnmain->setFont(f);
        returnmain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                                  "border-width: 2px; border-color: solid yellow;}");


        layout->addWidget(returnmain,-1, Qt::AlignHCenter);
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

//    void leaderboard::getplayerscore(const QString& name_, int n){
//        //layout->removeWidget(emptylist);
//        //emptylist->deleteLater();
//       // delete emptylist;
//        //updatedisplay();

//       // setLayout(layout);
//       // update();
//        leaders player(name_, n);

//        if(namelists.size()>0){
//            for(auto i = 0; i < namelists.size(); i++){
//                if(player.getscore() > namelists[i].getscore()){
//                    namelists.insert(i, player);
//                    break;
//                }
//            }
//        }
//        else{
//            namelists.push_back(player);
//        }

//        //updatedisplay();
//    }

    void leaderboard::updatedisplay(const QString & name_, int n){
        leaders player(name_, n);
        bool change = false;
        if(namelists.size()>0){
            for(auto i = 0; i < namelists.size(); i++){
                if(player.getscore() > namelists[i].getscore()){
                    namelists.insert(i, player);
                    change = true;
                    break;
                }

            }
            if(!change){
                namelists.push_back(player);
            }

        }
        else{
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
        layout->addWidget(lboard, -1, Qt::AlignHCenter);

        int count = 0;
        if(namelists.size()>0){
            for(auto i: namelists){
                ++count;
                if(count <=5){
                    QLabel* temp = new QLabel(i.namescore());
                    temp->setFont(f);
                    layout->addWidget(temp,-1, Qt::AlignHCenter);
                }
                else{
                    break;
                }
            }
            update();
        }

        returnmain = new QPushButton("Return to main");
        returnmain->setFont(f);
        returnmain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                                  "border-width: 2px; padding: 6px; border-color: solid yellow;}");


        layout->addWidget(returnmain,-1, Qt::AlignHCenter);
        connect(returnmain, SIGNAL(clicked()), this, SLOT(returntomain()));

        setLayout(layout);
    }

}

//        if(labellist.size()>0){
//            QLabel* temp;
//            for(auto i =0; i< labellist.size(); ++i){

//                temp = labellist.takeAt(i);
//                layout->removeWidget(temp);

//                //temp->deleteLater();
//                delete temp;

//            }
//            //update();
//        }
