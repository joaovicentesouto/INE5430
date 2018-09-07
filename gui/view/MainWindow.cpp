#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_facade(new Facade())
{
    ui->setupUi(this);
    ui->_mainBoardGame->setFacade(m_facade);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_facade;
}
