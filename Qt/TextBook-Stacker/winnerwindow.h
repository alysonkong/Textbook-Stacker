#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMediaPlayer>

class winnerwindow : public QWidget
{
    Q_OBJECT

public:
   winnerwindow(const QString&, int);

signals:
    void returntomain();
    void gotoLboard(QString, int);

public slots:
    void pressedmain();
    void pressedLboard();

private:
    QGridLayout *layout;
    QString player_name;
    int score_value;
    QMediaPlayer* winning_sound;

};


#endif // WINNERWINDOW_H
