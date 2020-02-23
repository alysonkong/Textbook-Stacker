#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include "avatar.h"

class GameView : public QGraphicsView
{
private:
    avatar* mc;
    QGraphicsScene scene;
    QTimer timer;
public:
    GameView(avatar* mc);

    void drawBackground(QPainter *painter, const QRectF &rect) override;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GAMEVIEW_H
