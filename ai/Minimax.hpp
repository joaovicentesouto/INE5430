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

// using move_type = Move;

move_type minimax(board_type& board, move_type move = {7, 7}, char player = 'p'); //! move => list<moves>

}   // namespace ai

#endif // MINIMAX_HPP