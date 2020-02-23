#ifndef NAMEINPUTWINDOW_H
#define NAMEINPUTWINDOW_H

#include <QWidget>
#include <QLineEdit>

class nameinputwindow : public QWidget
{
    Q_OBJECT
public:
    explicit nameinputwindow(QWidget *parent = nullptr);

public slots:
    void namechanged();

signals:
    void playername(QString);

private:
     QLineEdit *nameEdit;
     QString name;


};

#endif // NAMEINPUTWINDOW_H
