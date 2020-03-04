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
singlewindow::singlewindow(QString const & name1) : lives(3)
{
    spritesheet = new QPixmap(":/spritesheets/moreoverworld.png"); //creates the spritesheet as a pixmap with a custom image

    //QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1
    mc = new avatar(name1, spritesheet, 32, 48, 4, 4, 112, 5, 2, 4); //creates an avatar that the player will control
    mc->setPos(100,100); //sets position of this avatar
    mc->setSpeed(20); //sets speed of the avatar

    QPixmap back(":/bkgnd/textbookbkgndclear.png"); //chooses custom picture for the background
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette; //defines a QPalette
    palette.setBrush(QPalette::Background, back); //sets the brush for the background and the custom background image
    this->setAutoFillBackground(true); //fills the entire background
    this->setPalette(palette); //sets the palette to the palette we created

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //selects the font we want to use (Bubble font)
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //selects the font family we want using the font we chose earlier
    QFont f(family, 20); //selects the specific font we want using the id and family

    exit = new QPushButton("Exit"); //creates new button with the label "exit
    connect(exit, SIGNAL(clicked()), this, SLOT(returntomain())); //makes it so clicking this button will return to the main window

    QLabel* p1_name = new QLabel(name1); //creates new label for the player's name
    p1_name->setFont(f); //sets the font of this text to the font we chose earlier


    Recipe::Recipe* r;
    QWidget* recipe_display = r.display_recipe();

   // m = new books(1); //creates new books object

    pscore = new QLabel(QString::number(mc->getscore()));
    pscore->setFont(f);

    livesnum = new QLabel("Lives \n" + lives);
    livesnum->setFont(f);


//    timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(dropobject()));
//    connect(timer, SIGNAL(timeout()), view, SLOT(bookdrop(books*)));
//    timer->start(3000);


    view = new GameView(mc, m); //creates new gameview object
    QGridLayout *layout = new QGridLayout(); //creates new gridlayout

    /**
      adds the widgets we created earlier to the gridlayout
      **/

    layout->addWidget(recipe_display,0,0,2,2, Qt::AlignTop);
    layout->addWidget(view,0,2,-1,1);
    layout->addWidget(p1_name,0,3,1,2, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(lives, 1,3,1,1, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(pscore, 2,3,1,2, Qt::AlignLeft);
    layout->addWidget(exit, 3,3,4,2, Qt::AlignCenter);

    this->setLayout(layout); //sets window's layout to the gridlayout
    //setCentralWidget(view);
    //connect(m, SIGNAL(type_pts(int, int)), ); check with recipe

    connect(view, SIGNAL(booktypetowindow(int)), mc, SLOT(updatescore(int)));
    connect(view, SIGNAL(booktypetowindow(int)), this, SLOT(updatescorelabel(int)));
    connect(view, SIGNAL(booktypetowindow(int)), r, SLOT(book_caught(int)));
    //connect(r, SIGNAL(round_complete()), this, SLOT(newrecipe()));
    //connect(r, SIGNAL(wrong_book()), this, SLOT(deductlife()));


    show(); //shows the singlewindo
}

void singlewindow::deductlife(){
    --lives;
    livesnum->setText("Lives \n" + lives);
}


void singlewindow::dropobject(){
    books* newbook = new books(1);
    //connect(this, SIGNAL(dropbook(newbook)), view, SLOT(bookdrop(books*)));
    //emit dropbook(newbook);

    //emit signal to gameview
}


void singlewindow::newrecipe(){
    Recipe::Recipe newr = new Recipe::Recipe();
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

void singlewindow::updatescorelabel(int num){
    pscore->setText(QString::number(num));
}

//qlabel the lives
//size_t lives;
//in constructor connect(lives, zerolives(), singlewindow, emittomainwindow_
//connect(singlewindow, emittomain, main/this, changeindex(loserwindow);



