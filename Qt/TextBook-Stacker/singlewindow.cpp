#include "singlewindow.h"
#include <QGraphicsView>
#include "sprite.h"
#include <QGridLayout>
#include <QPixmap>
#include <QFontDatabase>

/**
 * @brief singlewindow::singlewindow constructor implementation for singlewindow
 * @param name1 the one parameter that this constructor takes (the player's name)
 */
singlewindow::singlewindow(QString const & name1) : lives(3) //gives player 3 lives to start
{
    spritesheet = new QPixmap(":/spritesheets/avataredited.png"); //creates the spritesheet as a pixmap with a custom image

    mc = new avatar(name1, spritesheet, 32, 48, 4, 4, 112, 48*4+2, 2, 4); //creates an avatar that the player will control
    mc->setPos(100,100); //sets position of this avatar
    mc->setSpeed(20); //sets speed of the avatar

    back = QPixmap(":/bkgnd/textbookbkgndclear.png"); //chooses custom picture for the background
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette; //defines a QPalette
    palette.setBrush(QPalette::Background, back); //sets the brush for the background and the custom background image
    this->setAutoFillBackground(true); //fills the entire background
    this->setPalette(palette); //sets the palette to the palette we created

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //selects the font we want to use (Bubble font)
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //selects the font family we want using the font we chose earlier
    QFont f(family, 20); //selects the specific font we want using the id and family

    exit = new QPushButton("Exit"); //creates new button with the label "exit
    exit->setFont(f); //sets font
    exit->setStyleSheet("QPushButton { font-size: 24px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; min-width: 7em; padding: 6px; border-color: solid yellow;}"); //adjusts layout of Exit button
    connect(exit, SIGNAL(clicked()), this, SLOT(returntomain())); //makes it so clicking this button will return to the main window

    QLabel* p1_name = new QLabel(name1); //creates new label for the player's name
    p1_name->setFont(f); //sets the font of this text to the font we chose earlier
    p1_name->setStyleSheet("QLabel { font: 33pt;}"); //adjusts layout of player name label


    r = new Recipe::Recipe(); //creates new recipe

    QLabel *scorelabel = new QLabel("Score:"); //creates title label for score
    scorelabel->setFont(f);
    scorelabel->setStyleSheet("QLabel { font: 30pt;");

    pscore = new QLabel(QString::number(mc->getscore())); //creates score label and sets it to the player's score
    pscore->setFont(f);

    livesnum = new QHBoxLayout; //creates layout for lives hearts

    //creates 3 heart labels to represent the 3 lives:
    heart1 = new QLabel;
    QPixmap heart_pixmap = QPixmap(":/icons/heart.png");
    heart_pixmap = heart_pixmap.scaledToWidth(50);
    heart1->setPixmap(heart_pixmap);
    heart2 = new QLabel;
    heart2->setPixmap(heart_pixmap);
    heart3 = new QLabel;
    heart3->setPixmap(heart_pixmap);

    //adds hearts to layout:
    livesnum->addWidget(heart1);
    livesnum->addWidget(heart2);
    livesnum->addWidget(heart3);

    //implements music button to turn game music on and off:
    QPixmap musicpix(":/icons/music.png");
    musicpix = musicpix.scaled(100,100,Qt::IgnoreAspectRatio); //resized the icon graphics
    music_button = new QPushButton();
    QIcon ButtonIcon(musicpix);
    music_button->setIcon(ButtonIcon); //change pushbutton visual into the imported icon
    music_button->setIconSize(musicpix.rect().size());
    music_button->setStyleSheet("QPushButton { border:none;}");
    connect(music_button, SIGNAL(clicked()), this, SLOT(playpause_music()));


    view = new GameView(mc); //creates new gameview object
    layout = new QGridLayout(); //creates new gridlayout


    /**
      adds the widgets we created earlier to the gridlayout
      **/

    layout->addWidget(r,0,0,-1,2, Qt::AlignTop);
    layout->addWidget(view,0,2,-1,1);
    layout->addWidget(p1_name,0,3,1,2, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(scorelabel, 1,3,1,2, Qt::AlignBottom|Qt::AlignLeft);
    layout->addLayout(livesnum, 2,3,1,2, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(pscore, 3,3,1,2, Qt::AlignLeft);
    layout->addWidget(exit, 4,3,5,2, Qt::AlignLeft);
    layout->addWidget(music_button, 10,3,1,2, Qt::AlignRight);

    this->setLayout(layout); //sets window's layout to the gridlayout

    connect(view, SIGNAL(booktypetowindow(int)), r, SLOT(book_caught(int))); //passes booktype to recipe to be evaluated

    connect(r, SIGNAL(updatescore(int)), mc, SLOT(updatepscore())); //recipe updates avatar's score if book is correct
    connect(r, SIGNAL(updatescore(int)), this, SLOT(updatescorelabel())); //recipe updates the score label if book is correct
    connect(r, SIGNAL(updatescore(int)), mc, SLOT(addbooks(int))); //adds books to avatar's book stack
    connect(r, SIGNAL(round_complete(int)), mc, SLOT(deletestack())); //starts new stack once round is over
    connect(r, SIGNAL(round_complete(int)), this, SLOT(roundupdate())); //updates round number
    connect(r, SIGNAL(wrong_book()), this, SLOT(deductlife())); //deducts life when wrong book is caught
    connect(this, SIGNAL(change_timer(int)), view, SLOT(increase_speed(int))); //increases speed of falling books when timer is changed


    show(); //shows the singlewindow
}


/**
 * @brief deducts a life when the wrong book or a bomb is caught
 */
void singlewindow::deductlife(){
    --lives;

//for each life a heart is lost:
        if (lives == 2) {
            livesnum->removeWidget(heart3);
            delete heart3;
            heart3 = nullptr;
        }

        if (lives == 1) {
            livesnum->removeWidget(heart2);
            delete heart2;
            heart2 = nullptr;
        }

        if(lives == 0){ //if player has no lives
            livesnum->removeWidget(heart1);
            delete heart1;
            heart1 = nullptr;
            view->stopbookdrop();
            emit finalscore(mc->getname(),mc->getscore()); //score and player name are emitted to be caught by loserwindow
            emit pname_score(mc->getname(), mc->getscore());

        }


}

/**
 * @brief turns music on or off
 */
void singlewindow::playpause_music() {
    emit change_music();
}

/**
 * @brief increases round number and makes books fall faster
 */
void singlewindow::newrecipe(){
    ++round_number;
    emit change_timer(round_number);
}


/**
 * @brief singlewindow::~singlewindow destructor for singlewindow
 */
singlewindow::~singlewindow()
{
    delete spritesheet; //deletes the spritesheet so we don't have memory leaks
}

/**
 * @brief singlewindow::returntomain slot that emits a signal signaling we want to go back to the main window
 */
void singlewindow::returntomain(){
    view->stopbookdrop();
    emit pressedmain(); //emit pressedmain signal

}

/**
 * @brief singlewindow::updatescorelabel updates score label
 */
void singlewindow::updatescorelabel(){
    pscore->setText(QString::number(mc->getscore()));
    pscore->repaint();
}

/**
 * @brief singlewindow::roundupdate calls round window or winner window to be shown once round is completed
 */
void singlewindow::roundupdate(){
    ++round_number;
    if(round_number < 5){ //4 rounds total
        view->stopbookdrop();
         emit roundcomplete(round_number);
    }
    else{
        view->stopbookdrop();
        emit gamewon(mc->getname(), mc->getscore());
    }

}

/**
 * @brief singlewindow::newround sets score label and calls book fall timer change
 */
void singlewindow::newround(){
    pscore->setText(QString::number(mc->getscore()));
    emit change_timer(round_number);

}
