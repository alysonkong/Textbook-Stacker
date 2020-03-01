#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
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
    QPushButton* returntomain;
    QVBoxLayout* layout;
    int index;

};

}


#endif // HELPWINDOW_H
