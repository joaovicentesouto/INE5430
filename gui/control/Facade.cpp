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
    std::pair<int,int> pc = ai::minimax(_board, depth);
    _board[pc.first][pc.second] = 'x';
    return pc;
}

std::pair<int,int> Facade::played(int x, int y, int depth)
{
    std::pair<int,int> pc = ai::minimax(_board, depth);
    _board[pc.first][pc.second] = 'x';
    return pc;
}

bool Facade::gameOver(int x, int y, char player)
{
    _board[x][y] = player;
    return ai::is_game_over(_board, {x,y});
}

void Facade::clean()
{
    for (int i = 0; i < 15; ++i)
        for (int j = 0; j < 15; ++j)
            _board[i][j] = ' ';
}
