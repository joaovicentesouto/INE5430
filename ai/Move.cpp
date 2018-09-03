
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

move_type next_move(const move_type& move)
{
    return { (move._x + 1) % 15, (move._y + 1) % 15};
}

} // namespace ai
