#ifndef SINGLEWINDOW1_H
#define SINGLEWINDOW1_H

#include <QDialog>

namespace Ui {
class singlewindow1;
}

class singlewindow1 : public QDialog
{
    Q_OBJECT

public:
    explicit singlewindow1(QWidget *parent = nullptr);
    ~singlewindow1();

signals:
    void pressedmain(int);

public slots:
    void on_back_to_main_clicked();

private:
    Ui::singlewindow1 *ui;
};

#endif // SINGLEWINDOW1_H
