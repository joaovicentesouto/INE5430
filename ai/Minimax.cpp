#include "Minimax.hpp"

namespace ai
{

move_type minimax(board_type& board, move_type move, char player)
{
    move.play(board, player);

    return move;
}

}
