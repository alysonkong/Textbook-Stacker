#include "singlewindow.h"
#include <QGraphicsView>
#include "sprite.h"
#include <QGridLayout>
#include <QPixmap>
#include <QFontDatabase>
#include "BookStack.h"

/**
 * @brief singlewindow::singlewindow constructor implementation for singlewindow
 * @param name1 the one parameter that this constructor takes (the player's name)
 */
singlewindow::singlewindow(QString const & name1) : lives(3)
{
    spritesheet = new QPixmap(":/spritesheets/moreoverworld.png"); //creates the spritesheet as a pixmap with a custom image

    //QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1
    mc = new avatar(name1, spritesheet, 32, 48, 4, 4, 112, 5, 2, 4); //creates an avatar that the player will control
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
    exit->setFont(f);
    exit->setStyleSheet("QPushButton { font-size: 24px; color : white; background-color: black; border-style: outset;"
                          "border-width: 2px; border-color: solid yellow;}");
    connect(exit, SIGNAL(clicked()), this, SLOT(returntomain())); //makes it so clicking this button will return to the main window

    QLabel* p1_name = new QLabel(name1); //creates new label for the player's name
    p1_name->setFont(f); //sets the font of this text to the font we chose earlier


    r = new Recipe::Recipe();
    pscore = new QLabel(QString::number(mc->getscore()));
    pscore->setFont(f);

    livesnum = new QLabel("Lives \n" + QString::number(lives));
    livesnum->setFont(f);


    view = new GameView(mc); //creates new gameview object
    layout = new QGridLayout(); //creates new gridlayout

    //sstack = new SideStack();

    /**
      adds the widgets we created earlier to the gridlayout
      **/

    layout->addWidget(r,0,0,2,2, Qt::AlignTop);
   // layout->addWidget(sstack, 1,0,3,2,Qt::AlignBottom);
    layout->addWidget(view,0,2,-1,1);
    layout->addWidget(p1_name,0,3,1,2, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(livesnum, 1,3,1,1, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(pscore, 2,3,1,2, Qt::AlignLeft);
    layout->addWidget(exit, 3,3,4,2, Qt::AlignCenter);

    this->setLayout(layout); //sets window's layout to the gridlayout

    connect(view, SIGNAL(booktypetowindow(int)), r, SLOT(book_caught(int)));
    connect(r, SIGNAL(updatescore(int)), mc, SLOT(updatepscore()));
    connect(r, SIGNAL(updatescore(int)), this, SLOT(updatescorelabel()));
    connect(r, SIGNAL(updatescore(int)), mc, SLOT(addbooks(int)));

    connect(r, SIGNAL(round_complete(int)), mc, SLOT(deletestack()));
    connect(r, SIGNAL(round_complete(int)), view, SLOT(stopbookdrop()));
    connect(r, SIGNAL(round_complete(int)), this, SLOT(roundupdate()));
    //connect(r, SIGNAL(round_complete(int)), this, SIGNAL(roundcomplete(int)));
    connect(r, SIGNAL(wrong_book()), this, SLOT(deductlife()));
    //connect(r, SIGNAL(round_complete()), view, SLOT(increase_speed(int)));
    //connect(view, SIGNAL(new_round()), this, SLOT(newrecipe()));
    connect(this, SIGNAL(change_timer(int)), view, SLOT(increase_speed(int)));


    show(); //shows the singlewindow
}



void singlewindow::deductlife(){
    --lives;
//    if (lives == 2) {
//            livesnum->removeWidget(heart3);
//            delete heart3;
//        }

//        if (lives == 1) {
//            livesnum->removeWidget(heart2);
//            delete heart2;
//        }

    if(lives == 0){ //if player has no lives
        livesnum->setText("Lives \n 0");
        emit finalscore(mc->getscore());
        emit pname_score(mc->getname(), mc->getscore());

    }
    livesnum->setText("Lives \n" + QString::number(lives)) ;

}



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
    emit pressedmain(); //emit pressedmain signal

}

void singlewindow::updatescorelabel(){
    //int temp = 4;
    pscore->setText(QString::number(mc->getscore()));
    pscore->repaint();
}

void singlewindow::roundupdate(){
    ++round_number;
    if(round_number <4){
         emit roundcomplete(round_number);
    }
    else{
        emit gamewon();
    }
   //view->increase_speed(round_number);
}

void singlewindow::newround(){
    //view->increase_speed(round_number);
    pscore->setText(QString::number(mc->getscore()));
    emit change_timer(round_number);

}
//qlabel the lives
//size_t lives;
//in constructor connect(lives, zerolives(), singlewindow, emittomainwindow_
//connect(singlewindow, emittomain, main/this, changeindex(loserwindow);



