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
#include <QMediaPlayer>
#include<QMediaPlaylist>
#include "multiwindow.h"
#include "singlewindow.h"
#include "helpwindow.h"
#include "nameinputwindow.h"
#include "twonamesinput.h"
#include "loserwindow.h"

#include "recipe.h"

/* FUNCTION:
 * the mainwindow class communicates between all the windows in the game via a stackedwidget set-up
 * mainwindow is derived from a QWidget
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void lboarddisplay(); //display leaderboard
    void maindisplay(); //display homepage
    void splayerdisplay(); //display singleplayer window
    void musiconoff(); //turn music on or off
    void mplayerdisplay(); //display multiplayer window
    void hwindowdisplay(); //display help window
    void namewindowdisplay(); //display name input window for singleplayer
    void twonamesdisplay(); //display name inputs for multiplayer
    void getname(QString n);  //creates the singleplayer window by getting the names from name input window
    void getnames(QString n1, QString n2); //creates the multiplayer window by getting the names from name inputs window
    void loserdisplay(QString, int);


private:
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
    gamewindow *gwindow; //multiwindow
    singlewindow *single_window;
    HelpWindow::helpwindow* hwindow;
    nameinputwindow* namewindow;
    twonamesinput* twonameswindow;
    loserwindow* lostwindow;

};
#endif // MAINWINDOW_H
