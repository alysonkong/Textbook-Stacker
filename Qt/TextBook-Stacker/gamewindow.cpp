#include "gamewindow.h"
#include <QGraphicsView>
#include "sprite.h"
#include "gameview.h"
#include "avatar.h"
#include <QGridLayout>
#include <QPixmap>

gamewindow::gamewindow()
{
    spritesheet = new QPixmap(":/spritesheets/moreoverworld.png");

    //avatar(QString user_name, QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 0.5, int tpf=1)
    avatar* mc = new avatar(QString("Abby"), spritesheet, 32, 48, 4, 4, 112, 0, 2, 4);
    mc->setPos(0,0);
    mc->setSpeed(5);

    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setAutoFillBackground(true);
    this->setPalette(palette);


    GameView* view = new GameView(mc);
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(view);
    this->setLayout(layout);
    //setCentralWidget(view);

    show();
}

void gamewindow::getplayername(QString){

}

gamewindow::~gamewindow()
{
    delete spritesheet;
}

void gamewindow::returntomain(){
    emit pressedmain();

}
