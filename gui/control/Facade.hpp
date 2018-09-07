//! João Vicente Souto e Bruno Izaias Bonotto

#ifndef FACADE_H
#define FACADE_H

#include <QObject>
#include <QString>
#include "ai/Minimax.hpp"

class Facade : public QObject
{
    Q_OBJECT

public:
    ai::board_type      _board;
    ai::moves_list_type _moves;

    Facade();
    ~Facade();

    std::pair<int,int> played(int depth);
    std::pair<int,int> played(int x, int y, int depth);
};

#endif // FACADE_H
