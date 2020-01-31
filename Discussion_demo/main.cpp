#include "disc_demo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    disc_demo w;
    w.show();
    return a.exec();
}
