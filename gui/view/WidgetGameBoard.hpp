#ifndef WIDGETGAMEBOARD_HPP
#define WIDGETGAMEBOARD_HPP

#include <QWidget>
#include <QAbstractItemView>
#include <QTableWidgetItem>
#include "control/Facade.hpp"

namespace Ui {
class WidgetGameBoard;
}

class WidgetGameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetGameBoard(QWidget *parent = 0);
    ~WidgetGameBoard();

    void setFacade(Facade * facade);
    void clean(bool on, bool tw, bool th, bool fo);

private slots:
    void on__resetButton_clicked();
    void on__rollButton_clicked();
    void on__gameBoard_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::WidgetGameBoard *ui;
    Facade * _facade;
};

#endif // WIDGETGAMEBOARD_HPP
