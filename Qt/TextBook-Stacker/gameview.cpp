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
GameView::GameView(avatar* mc, books* yb)
    : QGraphicsView()
    , mc(mc), b(yb)
{
    setFixedSize(500, 750);
    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    //view->setSceneRect(0, 0, width, height);

    scene.setSceneRect(0,0,500,750); //sets the dimensions of the scene Rect
    fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    mc->setPos(193, 654); //sets position of the avatar in the gameview
    scene.addItem(mc); //adds avatar to scene
   // b->setPos(100,0);

//    for(int i = 0; i< 3; ++i){
//        books* temp = new books(1);
//        temp->setPos(i*100, 0);
//        scene.addItem(temp);
//    }


    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance); //connects the timer to our scene so our scene can advance according to the timer
    //timer.setInterval();
    //connect(&timer, SIGNAL(timeout()), this, SLOT(bookdrop()));
    timer.start(1000/30); //starts the timer
    //while loop


    connect(&timer2, SIGNAL(timeout()), this, SLOT(bookdrop()));
    timer2.start(3000);

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
        case Qt::Key_Right: //if the key is the right key
            mc->go(Right); //make the avatar go right
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
    case Qt::Key_Right: //if key is right
        mc->stop(Right); //stop avatar movement from going right
        break;
    }

}

/**
 * @brief GameView::drawBackground implementation for the drawBackground function (draws the background fo the gameview)
 * @param painter the painter that will paint the background
 * @param rect the rect in which the gameview will be painted within
 */
void GameView::drawBackground(QPainter *painter, const QRectF &rect) {
    //QRect rectangle(0, 0, 200, 300);
    QPixmap back(":/bkgnd/classroom3.jpg"); //chooses custom picture for the background
    //back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
   // QPixmap cropped = back.copy(rectangle);
   // QSize area(500,750);
    //cropped.scaled(area, Qt::IgnoreAspectRatio);
    painter->setBrush(back);
    this->setAutoFillBackground(true); //fills the entire background
    painter->drawRect(0,0, 500,750); //sets dimensions for the rect
}


void GameView::bookdrop(){
   // QCoreApplication::processEvents();
   // std::seed_seq sseq(0, 5);
   // qsrand(QTime::currentTime().msec());
    //QRandomGenerator generator(QRandomGenerator::global()->bounded(0,5);;
    books* boo= new books(QRandomGenerator::global()->bounded(0,5));

    boo->setX(QRandomGenerator::global()->bounded(0,width()));
    //quint32 v;
    //v->QRandomGenerator::bounded(5);
    //boo->setPos(v*100, 0);
    scene.addItem(boo);
    scene.update();
    connect(boo, SIGNAL(emittype(int)), this, SLOT(getbooktype(int)));

}

void GameView::getbooktype(int n){
    emit booktypetowindow(n);
}

// mc->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
//if(mc->pos() == QPointF(0,604)){ code for stopping animation
//    mc->pause();
//    if(!scene.sceneRect().contains(mc->pos())){
//        mc->stop();
//        //mc->stop(Left);
//        //mc->setPos(0,604);
//        mc->itemChange(QGraphicsItem::GraphicsItemChange::ItemPositionHasChanged, QPointF(0,604));
//    }
//    else if(mc->pos() == QPointF(386,604)){
//        mc->stop(Right);
//}
