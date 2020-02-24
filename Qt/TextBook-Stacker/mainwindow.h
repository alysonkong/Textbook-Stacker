/**
@file mainwindow.cpp
@author Alyson Kong
@brief This file contains the declarations of our mainwindow
Pic 10C, UCLA
02/7/2020
"I pledge that I have neither given nor received unauthorized assistance on this assignment."
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H


//change mainwindow title

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDockWidget>
#include <QPixmap>
#include <ui_mainwindow.h>
#include <QFontDatabase>
#include<Lboardwindow.h>
#include<QStackedWidget>
#include "singlewindow1.h"
#include "ui_singlewindow1.h"
#include <QMediaPlayer>
#include<QMediaPlaylist>
#include "gamewindow.h"
#include "helpwindow.h"
#include "nameinputwindow.h"
#include "twonamesinput.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



signals:
    //void lboardclicked();
   // void emitname(QString);

public slots:
    void lboarddisplay();
    void maindisplay();
    void splayerdisplay();
    void musiconoff();
    void mplayerdisplay();
    void hwindowdisplay();
    void namewindowdisplay();
    void twonamesdisplay();
    void getname(QString n);
    void getnames(QString n1, QString n2);

private:
    Ui::MainWindow *ui;
    Ui::singlewindow1 *singlewindow;
    QDialog* single;
    QWidget *widgets;
    QWidget *widget2;
    QPushButton *singleplayer;
    QPushButton *multiplayer;
    QPushButton *leaderboard;
    QPushButton *helpbutton;
    QGridLayout *buttonslayout;
    QPushButton *music;
    QPushButton* music_icon;
    QPushButton *pic_label;
    QFontDatabase database;
    Leaderboardwindow::leaderboard*  lboard;
    QStackedWidget* swindows;
    QMediaPlayer* song;
    gamewindow *gwindow;
    HelpWindow::helpwindow* hwindow;
    nameinputwindow* namewindow;
    twonamesinput* twonameswindow;

};
#endif // MAINWINDOW_H
