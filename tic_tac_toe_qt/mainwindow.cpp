#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("TIC TAC TOE");
    setFixedSize(200,200);

    pvp_mode_bt = new QPushButton;
    pve_mode_bt = new QPushButton;

    x_mark_bt = new QPushButton;
    o_mark_bt = new QPushButton;

    pvp_mode_bt->setText("PVP MODE");
    pve_mode_bt->setText("PVE MODE");

    x_mark_bt->setText("X");
    o_mark_bt->setText("O");

    set_layout(pvp_mode_bt,pve_mode_bt);

    connect(pvp_mode_bt,SIGNAL(clicked(bool)),this,SLOT(handle_button_pvp()));
    connect(pve_mode_bt,SIGNAL(clicked(bool)),this,SLOT(handle_button_pve()));
    connect(x_mark_bt,SIGNAL(clicked(bool)),this,SLOT(handle_button_x()));
    connect(o_mark_bt,SIGNAL(clicked(bool)),this,SLOT(handle_button_o()));
}


MainWindow::~MainWindow()
{

}
void MainWindow::set_layout(QPushButton* bt1, QPushButton* bt2)
{
    QHBoxLayout* window_layout = new QHBoxLayout;

    window_layout->addWidget(bt1);
    window_layout->addWidget(bt2);

    QWidget* window = new QWidget;

    window->setLayout(window_layout);

    setCentralWidget(window);

}

void MainWindow::handle_button_pvp()
{
    game_mode = GameState::Mode::PVP_GAME;
    set_layout(x_mark_bt,o_mark_bt);
}

void MainWindow::handle_button_pve()
{
    game_mode = GameState::Mode::PVC_GAME;
    set_layout(x_mark_bt,o_mark_bt);
}

void MainWindow::handle_button_x()
{
    General_Handler game;
    close();
    game.main_loop(game_mode,'x');

    show();
}

void MainWindow::handle_button_o()
{
    General_Handler game;
    close();
    game.main_loop(game_mode,'o');
    show();
}
