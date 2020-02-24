#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include "avatar.h"
#include <QVariant>
#include "books.h"


class GameView : public QGraphicsView
{
private:
    avatar* mc;
    QGraphicsScene scene;
    QTimer timer;
    books* b;
public:
    GameView(avatar* mc, books*);

    void drawBackground(QPainter *painter, const QRectF &rect) override;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GAMEVIEW_H
