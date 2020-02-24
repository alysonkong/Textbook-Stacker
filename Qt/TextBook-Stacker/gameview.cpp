#include "gameview.h"
#include <QKeyEvent>


GameView::GameView(avatar* mc)
    : QGraphicsView()
    , mc(mc)
{
    scene.setSceneRect(0,0,450,700);
    mc->setPos(193, 604);
    scene.addItem(mc);
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

// I forgot the GameView:: in class
void GameView::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setBrush(Qt::blue);
    painter->drawRect(0,0, 450,700);
}
