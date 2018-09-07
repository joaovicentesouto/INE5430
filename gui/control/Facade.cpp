#include "Facade.hpp"
#include <unistd.h>

Facade::Facade()
{
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            _board[i][j] = ' ';
}

Facade::~Facade()
{

}

std::pair<int,int> Facade::played(int x, int y, int depth)
{
    _board[x][y] = 'o';
    _moves.remove(x, y);
    auto pc = ai::minimax(_board, _moves, depth);
    _board[pc->_x][pc->_y] = 'x';
    return {pc->_x, pc->_y};
}

std::pair<int,int> Facade::played(int depth)
{
    auto pc = ai::minimax(_board, _moves, depth);
    _board[pc->_x][pc->_y] = 'x';
    return {pc->_x, pc->_y};
}
