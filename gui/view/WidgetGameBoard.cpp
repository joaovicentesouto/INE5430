#include "WidgetGameBoard.hpp"
#include "ui_WidgetGameBoard.h"
#include <iostream>

WidgetGameBoard::WidgetGameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetGameBoard)
{
    ui->setupUi(this);
    ui->_gameBoard->setRowCount(15);
    ui->_gameBoard->setColumnCount(15);
    ui->_searchDepht->setMinimum(1);

    for (int i = 0; i < 15; i++) {

        ui->_gameBoard->setRowHeight(i, 30);
        ui->_gameBoard->setColumnWidth(i, 30);

        for (int j = 0; j < 15; j++) {
            auto item = new QTableWidgetItem(' ');
            item->setFlags(item->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
            ui->_gameBoard->setItem(i, j, item);
        }

    }

    clean(true,true,true,false);
}

WidgetGameBoard::~WidgetGameBoard()
{
    delete ui;
}

void WidgetGameBoard::clean(bool on, bool tw, bool th, bool fo)
{
    ui->_gameBoard->setDisabled(on);
    ui->_currentActions->setDisabled(tw);
    ui->_eventualActions->setDisabled(th);
    ui->_initialActions->setDisabled(fo);
}

void WidgetGameBoard::setFacade(Facade * facade)
{
    _facade = facade;
}

void WidgetGameBoard::on__rollButton_clicked()
{
    std::srand (std::time(NULL));

    if (std::rand() % 2)
        ui->_playerLabel->setText("You Win!");
    else {
        ui->_playerLabel->setText("PC Wins!");

        qApp->processEvents();

        std::pair<int,int> pc = _facade->played(ui->_searchDepht->text().toInt());
        ui->_gameBoard->item(pc.first, pc.second)->setFlags(ui->_gameBoard->item(pc.first, pc.second)->flags() & ~Qt::ItemIsEnabled);
        ui->_gameBoard->item(pc.first, pc.second)->setBackground(QColor("#ff4d4d"));

        ui->_playerLabel->setText("Your turn");
    }

    clean(false,false,false,true);
}

void WidgetGameBoard::on__gameBoard_itemDoubleClicked(QTableWidgetItem *item)
{
    if (item->flags() != (item->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable))
        return;

    item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
    item->setBackground(QColor("#4d4dff"));

    if(_facade->gameOver(item->row(), item->column(), 'o')) {

        _facade->clean();
        clean(true,false,true,true);
        ui->_playerLabel->setText("You Win!");

        return;
    }

    ui->_playerLabel->setText("PC turn");

    qApp->processEvents();

    std::pair<int,int> pc = _facade->played(item->row(), item->column(), ui->_searchDepht->text().toInt());

    auto tableItem = ui->_gameBoard->item(pc.first, pc.second);
    tableItem->setFlags(tableItem->flags() & ~Qt::ItemIsEnabled);
    tableItem->setBackground(QColor("#ff4d4d"));


    if(_facade->gameOver(pc.first, pc.second, 'x')) {

        _facade->clean();
        clean(true,false,true,true);
        ui->_playerLabel->setText("You Lose!");

        return;
    }

    ui->_playerLabel->setText("Your turn");
}

void WidgetGameBoard::on__resetButton_clicked()
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++) {
            auto item = new QTableWidgetItem(' ');
            item->setBackground(QColor("#ffffff"));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
            ui->_gameBoard->setItem(i, j, item);
        }

    ui->_playerLabel->setText("?");

    clean(true,true,true,false);
}
