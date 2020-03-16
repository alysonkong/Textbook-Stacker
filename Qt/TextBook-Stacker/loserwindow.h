#ifndef LOSERWINDOW_H
#define LOSERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMediaPlayer>

/**
 * @brief The loserwindow class generates and displays a window that appears when the user has lost the game
 */
class loserwindow : public QWidget
{
    Q_OBJECT

public:
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
