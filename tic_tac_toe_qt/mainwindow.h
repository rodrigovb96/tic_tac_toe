#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "general_handler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *pvp_mode_bt, *pve_mode_bt;
    QPushButton *x_mark_bt, *o_mark_bt;
    GameState::Mode game_mode;
    void set_layout(QPushButton *bt1, QPushButton *bt2);
private slots:
    void handle_button_pvp();
    void handle_button_pve();
    void handle_button_x();
    void handle_button_o();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
