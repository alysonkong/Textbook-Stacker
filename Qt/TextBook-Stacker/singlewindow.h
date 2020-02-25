#ifndef SINGLEWINDOW_H
#define SINGLEWINDOW_H


#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include<QPushButton>
#include "nameinputwindow.h"
#include <QLabel>
#include "avatar.h"
#include "books.h"

class singlewindow : public QWidget
{
    Q_OBJECT
public:
    singlewindow(QString const & name1);

    ~singlewindow();

signals:
   void pressedmain();

public slots:
    void returntomain();

private:
    QGraphicsScene scene;
    QPixmap* spritesheet;
    QTimer timer;
    QPushButton* exit;
    QLabel* p2name;
    avatar* mc;
    books* m;

};


#endif // SINGLEWINDOW_H
