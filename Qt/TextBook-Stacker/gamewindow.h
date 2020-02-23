#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include<QPushButton>

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    gamewindow();
    ~gamewindow();

signals:
   void pressedmain();

public slots:
    void returntomain();
    void getplayername();

private:
    QGraphicsScene scene;
    QPixmap* spritesheet;
    QTimer timer;
    QPushButton* exit;



};

#endif // GAMEWINDOW_H
