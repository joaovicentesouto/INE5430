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
    char _board[15][15];

    Facade();
    ~Facade();

    void clean();
    bool gameOver(int x, int y, char player);

    std::pair<int,int> played(int depth);
    std::pair<int,int> played(int x, int y, int depth);
};

#endif // FACADE_H
