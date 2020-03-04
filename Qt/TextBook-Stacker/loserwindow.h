#ifndef LOSERWINDOW_H
#define LOSERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>


class loserwindow : public QWidget
{
    Q_OBJECT
public:
    explicit loserwindow(QWidget *parent = nullptr);
signals:
     //void pressedmain(int);
public slots:
     //void returntomain();
private:
    QGridLayout *layout;
    int score_value;
    QString player_name;

};



#endif // LOSERWINDOW_H
