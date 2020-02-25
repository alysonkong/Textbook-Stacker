#include "gameview.h"
#include <QKeyEvent>
#include<QGraphicsView>

/**
 * @brief GameView::GameView implementation for the gameview constructor
 * @param mc avatar for the player
 * @param yb books that fall from the sky
 */
GameView::GameView(avatar* mc, books* yb)
    : QGraphicsView()
    , mc(mc), b(yb)
{
    scene.setSceneRect(0,0,450,700); //sets the dimensions of the scene Rect
    mc->setPos(193, 604); //sets position of the avatar in the gameview
    scene.addItem(mc); //adds avatar to scene
    scene.addItem(b); //adds books to scene
    setScene(&scene); //sets the scene of the gameview to our scene

    QObject::connect(&timer, &QTimer::timeout,
                     &scene, &QGraphicsScene::advance); //connects the timer to our scene so our scene can advance according to the timer
    timer.start(1000/30); //starts the timer
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
    painter->setBrush(Qt::blue); //sets the brush to blue
    painter->drawRect(0,0, 450,700); //sets dimensions for the rect
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
