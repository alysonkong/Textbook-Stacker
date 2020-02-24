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
    void gotogamewindow();

signals:
    void playername(QString);
    void gamewindowindex();

private:
     QLineEdit *nameEdit;
     QString name;


};

#endif // NAMEINPUTWINDOW_H
