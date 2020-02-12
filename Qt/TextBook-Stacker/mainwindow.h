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


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *singleplayer;
    QPushButton *multiplayer;
    QPushButton *leaderboard;
    QPushButton *helpbutton;
    QVBoxLayout *buttonslayout;
    QPushButton *music;
    QPushButton *pic_label;
    QFontDatabase database;
};
#endif // MAINWINDOW_H
