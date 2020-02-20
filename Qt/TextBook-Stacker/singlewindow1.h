#ifndef SINGLEWINDOW1_H
#define SINGLEWINDOW1_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class singlewindow1;
}

class singlewindow1 : public QDialog
{
    Q_OBJECT

public:
    explicit singlewindow1(QWidget *parent = nullptr);
    ~singlewindow1();

private:
    Ui::singlewindow1 *ui;
};

#endif // SINGLEWINDOW1_H
