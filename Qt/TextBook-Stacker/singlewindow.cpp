#include "singlewindow.h"
#include <QGraphicsView>
#include "sprite.h"
#include "gameview.h"
#include <QGridLayout>
#include <QPixmap>
#include <QFontDatabase>

singlewindow::singlewindow(QString const & name1)
{
    spritesheet = new QPixmap(":/spritesheets/moreoverworld.png");

    //QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1
    avatar* mc3 = new avatar(name1, spritesheet, 32, 48, 4, 4, 112, 50, 2, 4); //32, 48, 4, 4, 112, 0, 2, 4
    mc3->setPos(100,100); //0,0
    mc3->setSpeed(5);

    QPixmap back(":/bkgnd/textbookbkgndclear.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family, 20);

    exit = new QPushButton("Exit");
    connect(exit, SIGNAL(clicked()), this, SLOT(returntomain()));

    QLabel* p1_name = new QLabel;
    p1_name->setText(name1);
    p1_name->setFont(f);


    QLabel* temp = new QLabel("recipe");
    QLabel* temp2 = new QLabel("recipe2");

    m = new books();

    GameView* view = new GameView(mc3, m);
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(p1_name,0,0,1,1, Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(temp,1,0,3,1, Qt::AlignTop);
    layout->addWidget(view,0,1,-1,1);
    layout->addWidget(temp2, 1,2,1,1, Qt::AlignTop);
    layout->addWidget(exit, 2,2,5,1, Qt::AlignCenter);

    this->setLayout(layout);
    //setCentralWidget(view);

    show();
}



singlewindow::~singlewindow()
{
    delete spritesheet;
}

void singlewindow::returntomain(){
    emit pressedmain();

}
