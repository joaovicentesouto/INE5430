
#include "Move.hpp"

namespace ai
{
    
void Move::play(board_type &board, char player)
{
    board[_x][_y] = player;
}

void Move::unplay(board_type &board)
{
    board[_x][_y] = ' ';
}

} // namespace ai
