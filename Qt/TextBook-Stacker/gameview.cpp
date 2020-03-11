#include "gameview.h"
#include <QKeyEvent>
#include<QGraphicsView>
#include <QRandomGenerator>
#include <QtGlobal>
#include <QTime>

/**
 * @brief GameView::GameView implementation for the gameview constructor
 * @param mc avatar for the player
 * @param yb books that fall from the sky
 */
GameView::GameView(avatar* mc, books* boo)
    : QGraphicsView()
    , mc(mc), b(boo)
{
    setFixedSize(500, 750);
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    //view->setSceneRect(0, 0, width, height);

    scene.setSceneRect(0,0,500,750); //sets the dimensions of the scene Rect
    fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    mc->setPos(193, 360.2); //sets position of the avatar in the gameview
    scene.addItem(mc); //adds avatar to scene
   // b->setPos(100,0);

    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance); //connects the timer to our scene so our scene can advance according to the timer
    //timer.setInterval();
    //connect(&timer, SIGNAL(timeout()), this, SLOT(bookdrop()));
    timer.start(1000/30); //starts the timer
    //while loop


    connect(&timer2, SIGNAL(timeout()), this, SLOT(bookdrop()));
    timer2.start(1000);

    setScene(&scene);

}

/**
 * @brief GameView::keyPressEvent implementation for the keyPressEvent function (in the event that the a key is pressed)
 * @param event the key event
 */
void GameView::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) { //if event relates to a key event
        case Qt::Key_Left: //if key is the left key
            mc->go(Left); //make the avatar go left
           break;
    case Qt::Key_A:
        mc->go(Left);
        break;
        case Qt::Key_Right: //if the key is the right key
            mc->go(Right); //make the avatar go right
            break;
    case Qt::Key_D:
        mc->go(Right);
        break;

    }
}

/**
 * @brief GameView::keyReleaseEvent implementation for the keyReleaseEvent function (in the event that a key is released)
 * @param event the key event
 */
void GameView::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()) { //if event relates to a key event
    case Qt::Key_Left: //if key is left
        mc->stop(Left); //stop avatar movement from going left
        break;
    case Qt::Key_A:
        mc->stop(Left);
        break;
    case Qt::Key_Right: //if key is right
        mc->stop(Right); //stop avatar movement from going right
        break;
    case Qt::Key_D:
        mc->stop(Right);
        break;
    }

}

/**
 * @brief GameView::drawBackground implementation for the drawBackground function (draws the background fo the gameview)
 * @param painter the painter that will paint the background
 * @param rect the rect in which the gameview will be painted within
 */
void GameView::drawBackground(QPainter *painter, const QRectF &rect) {

    back = new QPixmap(":/bkgnd/classroom3.jpg"); //chooses custom picture for the background
    painter->setBrush(*back);
    this->setAutoFillBackground(true); //fills the entire background
    painter->drawRect(0,0, 500,750); //sets dimensions for the rect
}


void GameView::bookdrop(){
    b= new books(QRandomGenerator::global()->bounded(0,9));
    int x = QRandomGenerator::global()->bounded(0,5);
    b->setX(x*100);
    scene.addItem(b); //scene takes ownership of the item
    //boo->setParent(scene)
    scene.update();

    //connect(b, SIGNAL(emittype(int)), this, SIGNAL(booktypetowindow(int)));

    connect(b, SIGNAL(emittype(int)), this, SLOT(getbook(int)));

}


void GameView::getbook(int n){
    emit booktypetowindow(n);
}

void GameView::increase_speed(int round_num) {
    timer2.stop();
//    if(round_num < 2){
//    timer2.start(3000 - 1000*round_num); //1000/round_num
//    }
//    else{
        timer2.start(1000/round_num);
    //}

}

GameView::~GameView(){
    delete back;
}

