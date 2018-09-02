#include "Minimax.hpp"

namespace ai
{

move_type minimax(board_type& board, move_type move, char player)
{
    move_type test{7, 7};

    test.play(board, player);

    return test;
}

}
