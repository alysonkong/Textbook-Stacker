#ifndef TWONAMESINPUT_H
#define TWONAMESINPUT_H

#include <QWidget>
#include <QLineEdit>

class twonamesinput : public QWidget
{
    Q_OBJECT
public:
    explicit twonamesinput(QWidget *parent = nullptr);

public slots:
    void namechanged();
    void gotogamewindow();

signals:
    void playernames(QString, QString);
    void gamewindowindex();

private:
     QLineEdit *name1Edit;
     QLineEdit *name2Edit;

};

#endif // TWONAMESINPUT_H
