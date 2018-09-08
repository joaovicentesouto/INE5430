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

std::pair<int,int> Facade::played(int depth)
{
    auto pc = ai::minimax(_board, _moves, depth);

    if (!pc)
        return {-1, -1};

    _board[pc->_x][pc->_y] = 'x';
    return {pc->_x, pc->_y};
}

std::pair<int,int> Facade::played(int x, int y, int depth)
{    
    auto pc = ai::minimax(_board, _moves, depth);

    if (!pc)
        return {-1, -1};

    _board[pc->_x][pc->_y] = 'x';
    return {pc->_x, pc->_y};
}

bool Facade::gameOver(int x, int y, char player)
{
    _board[x][y] = player;
    _moves.remove(x, y);

    return ai::is_game_over(_board);
}

void Facade::clean()
{
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            _board[i][j] = ' ';
}
