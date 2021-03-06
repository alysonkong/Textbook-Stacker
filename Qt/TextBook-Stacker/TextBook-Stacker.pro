QT       += core gui
QT += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Lboardwindow.cpp \
    avatar.cpp \
    books.cpp \
    gameview.cpp \
    helpwindow.cpp \
    loserwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    nameinputwindow.cpp \
    recipe.cpp \
    roundwindow.cpp \
    singlewindow.cpp \
    sprite.cpp \
    winnerwindow.cpp

HEADERS += \
    Lboardwindow.h \
    avatar.h \
    books.h \
    gameview.h \
    helpwindow.h \
    loserwindow.h \
    mainwindow.h \
    nameinputwindow.h \
    recipe.h \
    roundwindow.h \
    singlewindow.h \
    sprite.h \
    winnerwindow.h

FORMS += \
    mainwindow.ui \
    singlewindow1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
