#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include<QPushButton>
#include "nameinputwindow.h"
#include <QLabel>
#include "avatar.h"
#include "books.h"

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    gamewindow(QString const & name1, QString const & name2);

    ~gamewindow();

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

#endif // GAMEWINDOW_H
