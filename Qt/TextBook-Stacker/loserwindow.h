#ifndef LOSERWINDOW_H
#define LOSERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>


class loserwindow : public QWidget
{
    Q_OBJECT
public:
    //explicit loserwindow(QWidget *parent = nullptr);
    loserwindow(int);
signals:
     void pressedmain();
public slots:
     void returntomain();
private:
    QGridLayout *layout;
    QString player_name;
    int score_value;

};



#endif // LOSERWINDOW_H
