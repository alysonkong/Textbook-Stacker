#ifndef LOSERWINDOW_H
#define LOSERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMediaPlayer>


class loserwindow : public QWidget
{
    Q_OBJECT
public:
    //explicit loserwindow(QWidget *parent = nullptr);
    loserwindow(QString, int);
signals:
     void pressedmain();
     void gotolboard(QString, int);
public slots:
     void returntomain();
     void pressedLboard();
private:
    QGridLayout *layout;
    QString player_name;
    int score_value;
    QMediaPlayer* loser_sound;

};



#endif // LOSERWINDOW_H
