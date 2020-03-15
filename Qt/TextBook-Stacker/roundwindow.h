#ifndef ROUNDWINDOW_H
#define ROUNDWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>

class roundwindow : public QWidget
{
    Q_OBJECT
public:
    //explicit roundwindow(QWidget *parent = nullptr);
    roundwindow(int);

signals:
    void nextround();
    void returntomain();

private:
    int round;
    QLabel* roundtext;
    QGridLayout* layout;
    QMediaPlayer* newround_sound;

};

#endif // ROUNDWINDOW_H
