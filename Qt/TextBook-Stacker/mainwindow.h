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
//#include<QSignalMapper>



class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    //void lboardclicked();

public slots:
    void  lboarddisplay();
    void maindisplay();

private:
    Ui::MainWindow *ui;
    QWidget *widgets;
    QWidget *widget2;
    QPushButton *singleplayer;
    QPushButton *multiplayer;
    QPushButton *leaderboard;
    QPushButton *helpbutton;
    QVBoxLayout *buttonslayout;
    QPushButton *music;
    QPushButton *pic_label;
    QFontDatabase database;
    Leaderboardwindow::leaderboard*  lboard;
    QStackedWidget* swindows;
};
#endif // MAINWINDOW_H
