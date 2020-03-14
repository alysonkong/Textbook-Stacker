#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>


class winnerwindow : public QWidget
{
    Q_OBJECT
public:
    //explicit loserwindow(QWidget *parent = nullptr);
   winnerwindow(const QString&, int);

signals:
    void returntomain();
    void gotoLboard();
public slots:
    void pressedmain();
    void pressedLboard();
private:
    QGridLayout *layout;
    QString player_name;
    int score_value;

};


#endif // WINNERWINDOW_H
