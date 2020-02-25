#include "singlewindow.h"
#include <QGraphicsView>
#include "sprite.h"
#include "gameview.h"
#include <QGridLayout>
#include <QPixmap>
#include <QFontDatabase>

/**
 * @brief singlewindow::singlewindow constructor implementation for singlewindow
 * @param name1 the one parameter that this constructor takes (the player's name)
 */
singlewindow::singlewindow(QString const & name1)
{
    spritesheet = new QPixmap(":/spritesheets/moreoverworld.png"); //creates the spritesheet as a pixmap with a custom image

    //QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1
    avatar* mc3 = new avatar(name1, spritesheet, 32, 48, 4, 4, 112, 50, 2, 4); //creates an avatar that the player will control
    mc3->setPos(100,100); //sets position of this avatar
    mc3->setSpeed(5); //sets speed of the avatar

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

    QLabel* p1_name = new QLabel; //creates new label for the player's name
    p1_name->setText(name1); //sets the text to the player's name
    p1_name->setFont(f); //sets the font of this text to the font we chose earlier

    QLabel* temp = new QLabel("recipe"); //creates new label for the recipe

    m = new books(); //creates new books object

    GameView* view = new GameView(mc3, m); //creates new gameview object
    QGridLayout *layout = new QGridLayout(); //creates new gridlayout

    /**
      adds the widgets we created earlier to the gridlayout
      **/
    layout->addWidget(p1_name,0,0,1,1, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(temp,1,0,3,1, Qt::AlignTop);
    layout->addWidget(view,0,1,-1,1);
    layout->addWidget(exit, 2,2,5,1, Qt::AlignCenter);

    this->setLayout(layout); //sets window's layout to the gridlayout
    //setCentralWidget(view);

    show(); //shows the singlewindow
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
