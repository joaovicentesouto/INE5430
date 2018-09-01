//! João Vicente Souto

#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include <limits>
#include <functional>
#include <iostream>

namespace ai
{

using board_type = char[15][15];

struct Move
{
    // Move(size_t x, size_t y);

    ~Move() = default;

    void play(board_type& board, char player);
    void unplay(board_type& board);

    size_t _x, _y;
};

}   // namespace ai

#endif // DESIMONETREE_H