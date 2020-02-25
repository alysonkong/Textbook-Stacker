#include "multiwindow.h"
#include <QGraphicsView>
#include "sprite.h"
#include "gameview.h"
#include <QGridLayout>
#include <QPixmap>
#include <QFontDatabase>


/**
 * @brief gamewindow::gamewindow sets up the gamewindow layout, and adds in the gameview window
 * @param name1 is name of player 1 avatar
 * @param name2 is name of player 2 avatar
 */
gamewindow::gamewindow(QString const & name1, QString const & name2)
{
    spritesheet = new QPixmap(":/spritesheets/moreoverworld.png");

    //QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1 for reference
    avatar* mc3 = new avatar(name1, spritesheet, 32, 48, 4, 4, 112, 0, 2, 4); //creates player 1's avatar
    mc3->setPos(0,0);
    mc3->setSpeed(5);

    avatar* mc2 = new avatar(name2, spritesheet, 32, 48, 4, 4, 112, 0, 2, 4); //creates player 2's avatar
    mc2->setPos(0,0);
    mc2->setSpeed(5);

    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //sets up font to use
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family, 20);

    exit = new QPushButton("Exit");
    exit->setFont(f);
    exit->setStyleSheet("QPushButton { font-size: 18px; color : white; background-color: black; border-style: outset;"
          "border-width: 2px; border-color: solid yellow;}");
    connect(exit, SIGNAL(clicked()), this, SLOT(returntomain()));

    QLabel* p1_name = new QLabel;
    p1_name->setText(name1);
    p1_name->setFont(f);
    p2name = new QLabel("Player 2 name");
    p2name->setText(name2);
    p2name->setFont(f);

    QLabel* temp = new QLabel("recipe"); //placeholder for recipe
    QLabel* temp2 = new QLabel("recipe2");

    m = new books();

    GameView* view = new GameView(mc3, m);
    GameView* view2 = new GameView(mc2, m);
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(p1_name,0,0,1,1, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(temp,1,0,3,1, Qt::AlignTop);
    layout->addWidget(view,0,1,-1,1);
    layout->addWidget(p2name, 0,2,1,1,Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(temp2, 1,2,1,1, Qt::AlignTop);
    layout->addWidget(exit, 2,2,5,1, Qt::AlignCenter);
    layout->addWidget(view2, 0,3,-1,1);




    this->setLayout(layout);
    //setCentralWidget(view);

    show();
}


/**
 * @brief gamewindow::~gamewindow destructor for gamewindow that deletes the spritesheet to prevent memory leaks
 */
gamewindow::~gamewindow()
{
    delete spritesheet;
}

/**
 * @brief gamewindow::returntomain sends out signal to mainwindow to return back to homepage
 */
void gamewindow::returntomain(){
    emit pressedmain();

}
