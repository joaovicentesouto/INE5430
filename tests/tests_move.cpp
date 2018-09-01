
#include <catch2/catch.hpp>

#include <iostream>

#include <ai/Move.hpp>

using namespace ai;

TEST_CASE("Move: play and unplay", "[ai][minimax]")
{
    ai::Move t{7, 7};
    ai::board_type board = { [0 ... 14] = { [0 ... 14] = ' ' } };

    REQUIRE(board[0][0] == ' ');
    REQUIRE(board[t._x][t._y] == ' ');
    REQUIRE(board[14][14] == ' ');

    t.play(board, 'p');

    CHECK(board[t._x][t._y] == 'p');

    t.unplay(board);

    CHECK(board[t._x][t._y] == ' ');
}
