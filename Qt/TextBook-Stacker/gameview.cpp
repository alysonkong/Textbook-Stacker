#include "gameview.h"
#include <QKeyEvent>
#include<QGraphicsView>


GameView::GameView(avatar* mc, books* yb)
    : QGraphicsView()
    , mc(mc), b(yb)
{
    scene.setSceneRect(0,0,450,700);
    mc->setPos(193, 604);
    scene.addItem(mc);
    scene.addItem(b);
    setScene(&scene);

    QObject::connect(&timer, &QTimer::timeout,
                     &scene, &QGraphicsScene::advance);
    timer.start(1000/30);
}

void GameView::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_Left:
            mc->go(Left);
           break;
        case Qt::Key_Right:
            mc->go(Right);
            break;

    }
}
void GameView::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Left:
        mc->stop(Left);
        break;
    case Qt::Key_Right:
        mc->stop(Right);
        break;
    }

}

void GameView::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setBrush(Qt::blue);
    painter->drawRect(0,0, 450,700);
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
