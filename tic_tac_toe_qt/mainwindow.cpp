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

    QHBoxLayout* window_layout = new QHBoxLayout;

    window_layout->addWidget(pvp_mode_bt);
    window_layout->addWidget(pve_mode_bt);

    QWidget* window = new QWidget;

    window->setLayout(window_layout);

    setCentralWidget(window);
    connect(pvp_mode_bt,SIGNAL(clicked(bool)),this,SLOT(handle_button_pvp()));
    connect(pve_mode_bt,SIGNAL(clicked(bool)),this,SLOT(handle_button_pve()));

}


MainWindow::~MainWindow()
{

}

void MainWindow::init_game(GameState::Mode mode)
{
    // pop_up for chosing the mark
    QMessageBox mark_box;
    this->close();

    mark_box.setWindowTitle("Escolha sua marca");
    mark_box.setText("Qual sua Escolha?");


    QPushButton * x_button = mark_box.addButton( tr("X"),QMessageBox::ActionRole);;
    QPushButton * o_button = mark_box.addButton( tr("O"),QMessageBox::ActionRole);;

    mark_box.exec();

    General_Handler game;
    if(mark_box.clickedButton() == x_button)
        game.main_loop(mode,'x');
    else if(mark_box.clickedButton() == o_button)
        game.main_loop(mode,'o');

    this->show();
}

void MainWindow::handle_button_pvp()
{
    game_mode = GameState::Mode::PVP_GAME;
    init_game(game_mode);
}

void MainWindow::handle_button_pve()
{
    game_mode = GameState::Mode::PVC_GAME;
    init_game(game_mode);
}
