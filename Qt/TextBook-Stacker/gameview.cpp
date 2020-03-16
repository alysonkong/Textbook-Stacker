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
GameView::GameView(avatar* mc) : QGraphicsView(), mc(mc)
{
    setFixedSize(500, 750); //set fixed size for game display in singlewindow
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff ); //no horizontal scroll
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff ); //no vertical scroll

    scene.setSceneRect(0,0,500,750); //sets the dimensions of the scene Rect
    fitInView(scene.sceneRect(), Qt::KeepAspectRatio); //put game scene within the bounding rectangle
    mc->setPos(200, 360.2); //sets position of the avatar in the gameview
    scene.addItem(mc); //adds avatar to scene

    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance); //connects timer to scene; scene advances according to the timer
    timer.start(1000/30); //starts the timer

    connect(&timer2, SIGNAL(timeout()), this, SLOT(bookdrop())); //connects timer2 so books drop according to timer speed
    timer2.start(1500); //starts timer2

    setScene(&scene); //sets the scene as the gameview scene
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
        case Qt::Key_A: //if key is A key
            mc->go(Left); //make avatar go left
            break;
        case Qt::Key_Right: //if the key is the right key
            mc->go(Right); //make the avatar go right
            break;
        case Qt::Key_D: //if key is D key
            mc->go(Right); //make avatar go right
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
    case Qt::Key_A: //if key is A
        mc->stop(Left); //stop avatar movement from going left
        break;
    case Qt::Key_Right: //if key is right
        mc->stop(Right); //stop avatar movement from going right
        break;
    case Qt::Key_D: //if key is D
        mc->stop(Right); //stop avatar movement from going right
        break;
    }
}



/**
 * @brief GameView::drawBackground draws the background for the gameview
 * @param painter the painter that will paint the background
 * @param rect the rect in which the gameview will be painted within
 */
void GameView::drawBackground(QPainter *painter, const QRectF &rect) {

    back = new QPixmap(":/bkgnd/classroom3.jpg"); //chooses custom picture for the background
    painter->setBrush(*back);
    this->setAutoFillBackground(true); //fills the entire background
    painter->drawRect(0,0, 500,750); //sets dimensions for the rect
}


/**
 * @brief GameView::bookdrop randomly generates items to fall, and randomly generates how far left/right they will fall from
 */
void GameView::bookdrop(){
    b= new books(QRandomGenerator::global()->bounded(0,9)); //generates random books with codes from 0-8 (some are Fs)
    int x = QRandomGenerator::global()->bounded(0,6); //randomly generates position of where items will fall
    b->setX(x*100); //set position
    scene.addItem(b); //scene takes ownership of the item
    scene.update(); //update scene

    connect(b, SIGNAL(emittype(int)), this, SLOT(getbook(int))); //connects signal from books so gameview knows which item was caught
}



/**
 * @brief GameView::getbook passes the information of which item was caught and sends signal to recipe
 * @param n the book code of the item that was caught
 */
void GameView::getbook(int n){
    emit booktypetowindow(n);
}


/**
 * @brief GameView::increase_speed increases the speed of the falling items
 * @param round_num the number of the round
 */
void GameView::increase_speed(int round_num) {
        timer2.start(1500/(1.3*round_num)); //speed increases as round levels increase
}


/**
 * @brief GameView::stopbookdrop stops the items from falling
 */
void GameView::stopbookdrop(){
    if(b){ //if there are books in the scene
        scene.removeItem(b); //remove them
        delete b; //delete them
        b = nullptr;
    }

    timer2.stop(); //stop timer so items stop falling

}

/**
 * @brief GameView::~GameView destructs the background so there are no memory leaks
 */
GameView::~GameView(){
    delete back;
}

