#ifndef SIDESTACK_H
#define SIDESTACK_H

#include <QGraphicsView>
#include "books.h"
#include <vector>
#include <QVariant>



class SideStack : public QGraphicsView
{
    Q_OBJECT
public:
    SideStack();
   // void drawBackground(QPainter *painter, const QRectF &rect) override;
public slots:
    void addbooks(int);
private:
    QGraphicsScene scene; //the scene where our game is taking place
    std::vector<books*> bs; //books that fall from the sky
    int y; //y coord of the books
};

#endif // SIDESTACK_H
