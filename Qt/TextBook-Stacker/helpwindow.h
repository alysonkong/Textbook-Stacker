#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>



namespace HelpWindow {

/**
 * @brief The helpwindow class displays a window providing instructions how to play the game
 * helpwindow is derived from QWidget
 */
class helpwindow : public QWidget
{
    Q_OBJECT
public:
    //explicit helpwindow(QWidget *parent = nullptr);
    helpwindow();

signals:
    void pressed_main(int); //signal to return to the main screen

public slots:
    void return_to_main(); //returns to the main screen

private:
    QLabel* title;
    QLabel* instructions;
    QPushButton* returntomain;
    QVBoxLayout* layout;
    int index;

};

}


#endif // HELPWINDOW_H
