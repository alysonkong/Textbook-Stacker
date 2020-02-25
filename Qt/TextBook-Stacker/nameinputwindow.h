#ifndef NAMEINPUTWINDOW_H
#define NAMEINPUTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QString>

class nameinputwindow : public QWidget
{
    Q_OBJECT
public:
    explicit nameinputwindow(QWidget *parent = nullptr);

public slots:
    void namechanged();
    void gotosingle_window();

signals:
    void playername(QString);
    void single_windowindex();

private:
     QLineEdit *nameEdit;

};

#endif // NAMEINPUTWINDOW_H
