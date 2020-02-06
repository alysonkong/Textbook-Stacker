#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDockWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
   // Ui::MainWindow *ui;
    QPushButton *singleplayer;
    QPushButton *multiplayer;
    QPushButton *leaderboard;
    QPushButton *helpbutton;
    QVBoxLayout *buttonslayout;
    QPushButton *music;
};
#endif // MAINWINDOW_H
