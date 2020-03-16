#ifndef HELPWINDOW_H
#define HELPWINDOW_H

//included files
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>

//HelpWindow namespace
namespace HelpWindow
{

/**
 * @brief The helpwindow class shows the help window and connects to mainwindow
 */
class helpwindow : public QWidget
{
    Q_OBJECT
public:
    helpwindow(); //default constructor for helpwindow

//signals for helpwindow
signals:
    void pressed_main(int);

//slots for helpwindow
public slots:
    void return_to_main();

//private fields for helpwindow
private:
    int index;
    QLabel* title;
    QLabel* instructions;
    QPushButton* returntomain;
    QPushButton* avatar_instruct;
    QPushButton* book;
    QPushButton* fletter;
    QPushButton* recipe;
    QGridLayout* layout;

};

}


#endif // HELPWINDOW_H
