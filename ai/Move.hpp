//! João Vicente Souto

#ifndef MOVE_HPP
#define MOVE_HPP

#include <limits>
#include <functional>
#include <iostream>

#include "Util.hpp"

namespace ai
{

struct Move
{
    // Move(size_t x, size_t y);

    ~Move() = default;

    void play(board_type& board, char player);
    void unplay(board_type& board);

    int _x, _y;
};

}   // namespace ai

#endif // MOVE_HPP
