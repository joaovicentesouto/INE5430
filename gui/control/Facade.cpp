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
    std::pair<int,int> pc = ai::minimax(_board, depth);
    _board[pc.first][pc.second] = 'x';
    return {pc.first, pc.second};
}

std::pair<int,int> Facade::played(int depth)
{
    std::pair<int,int> pc = ai::minimax(_board, depth);
    _board[pc.first][pc.second] = 'x';
    return {pc.first, pc.second};
}
