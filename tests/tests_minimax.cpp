
#include <catch2/catch.hpp>

#include <iostream>

#include <ai/Minimax.hpp>

using namespace ai;

TEST_CASE("Minimax: minimax default", "[ai][minimax]")
{
    ai::board_type board = { [0 ... 14] = { [0 ... 14] = ' ' } };

    CHECK(board[7][7] == ' ');

    move_type t = minimax(board);

    CHECK(board[t._x][t._y] == 'p');
}
