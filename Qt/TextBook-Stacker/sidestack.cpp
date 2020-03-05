#include "sidestack.h"

SideStack::SideStack() :QGraphicsView(), bs()
{
    setFixedSize(100, 520);
    setStyleSheet("background: transparent");
    setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    scene.setSceneRect(0,0,100,520); //sets the dimensions of the scene Rect
    fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
//    books* temp = new books(1);
//    temp->setPos(0,0);
//    scene.addItem(temp);

    setScene(&scene);
}
//book dimensions: 100 x 32.2
void SideStack::addbooks(int index){
//    bs.push_back(b);
//    y = bs.size();
//    b->setPos(0, 0); //(-520+(y*32.2))
//    scene.addItem(b);
    books* temp = new books(index);
    bs.push_back(temp);
    y = bs.size();
    temp->setPos(0,(520-(y*32.2)));
    scene.addItem(temp);
    scene.update();
}

//void SideStack::drawBackground(QPainter *painter, const QRectF &rect){
//    painter->setBrush(Qt::white);
//    painter->drawRect(0,0,100,520);

//}
