//! João Vicente Souto

#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include <limits>
#include <functional>
#include <iostream>

#include "Util.hpp"
#include "Move.hpp"

namespace ai
{

using move_type = Move;

move_type minimax(board_type& board, move_type move = {-1, -1}, char player = 'p');

}   // namespace ai

#endif // MINIMAX_HPP