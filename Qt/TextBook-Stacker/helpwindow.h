#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>




namespace HelpWindow {

/**
 * @brief The helpwindow class shows the help window and connects to mainwindow
 */
class helpwindow : public QWidget
{
    Q_OBJECT
public:
    //explicit helpwindow(QWidget *parent = nullptr);
    helpwindow();

signals:
    void pressed_main(int);

public slots:
    void return_to_main();

private:
    QLabel* title;
    QLabel* instructions;
    QLabel* instructions1;
    QLabel* instructions2;
    QLabel* instructions3;
    QLabel* instructions4;
    QLabel* instructions5;
    QPushButton* returntomain;
    QVBoxLayout* main_layout;
    QHBoxLayout* first_layout;
    QHBoxLayout* second_layout;
    QHBoxLayout* third_layout;
    QHBoxLayout* fourth_layout;
    QHBoxLayout* fifth_layout;
    QPushButton* pic_Left;
    QPushButton* pic_Right;
    QPushButton* pic_left;
    QPushButton* pic_right;
    QPushButton* book;
    QPushButton* heart;
    QPushButton* fletter;
    QPushButton* recipe;
    int index;

};

}


#endif // HELPWINDOW_H
