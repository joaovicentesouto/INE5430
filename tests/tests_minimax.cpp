
#include <catch2/catch.hpp>

#include <iostream>

#include <ai/Minimax.hpp>

using namespace ai;

TEST_CASE("Minimax: minimax default", "[ai][minimax]")
{
//    ai::board_type board = { [0 ... 14] = { [0 ... 14] = ' ' } };

    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    CHECK(board[2][2] == ' ');
    minimax(board, 2);
    CHECK(board[2][2] == ' ');
}

TEST_CASE("Minimax: minimax horizontal_points", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[5][4] = 'x';
    board[5][5] = 'x';
    board[5][6] = 'x';
    board[5][7] = 'x';
    board[5][8] = 'x';
    board[5][9] = 'o';
    board[6][6] = 'o';
    board[6][7] = 'o';
    board[6][8] = 'o';

    CHECK(horizontal_points(board) == 199949999);
}

TEST_CASE("Minimax: minimax vertical_points", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[4][5] = 'x';
    board[5][5] = 'x';
    board[6][5] = 'x';
    board[7][5] = 'x';
    board[8][5] = 'x';
    board[9][5] = 'o';
    board[6][6] = 'o';
    board[7][6] = 'o';
    board[8][6] = 'o';

    CHECK(vertical_points(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_right_points", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[4][4] = 'x';
    board[5][5] = 'x';
    board[6][6] = 'x';
    board[7][7] = 'x';
    board[8][8] = 'x';
    board[9][9] = 'o';
    board[5][6] = 'o';
    board[6][7] = 'o';
    board[7][8] = 'o';

    CHECK(diagonal_right_points(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_right_points2", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[4][4] = 'x';
    board[5][5] = 'x';
    board[6][6] = 'x';
    board[7][7] = 'x';
    board[8][8] = 'x';
    board[9][9] = 'o';
    board[7][6] = 'o';
    board[8][7] = 'o';
    board[9][8] = 'o';

    CHECK(diagonal_right_points(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_left_points", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[6][8] = 'x';
    board[7][7] = 'x';
    board[8][6] = 'x';
    board[9][5] = 'x';
    board[10][4] = 'x';
    board[11][3] = 'o';
    board[7][6] = 'o';
    board[8][5] = 'o';
    board[9][4] = 'o';

    CHECK(diagonal_left_points(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_left_points2", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[6][8] = 'x';
    board[7][7] = 'x';
    board[8][6] = 'x';
    board[9][5] = 'x';
    board[10][4] = 'x';
    board[11][3] = 'o';
    board[7][8] = 'o';
    board[8][7] = 'o';
    board[9][6] = 'o';

    CHECK(diagonal_left_points(board) == 199949999);
}

TEST_CASE("Minimax: minimax utility", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[5][4] = 'x';
    board[5][5] = 'x';
    board[5][6] = 'x';
    board[5][7] = 'x';
    board[5][8] = 'x';
    board[5][9] = 'o';
    board[6][6] = 'o';
    board[6][7] = 'o';
    board[6][8] = 'o';

    CHECK(utility(board) == 199949754);
}

TEST_CASE("Minimax: minimax horizontal_winner_possible", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[2][5] = 'x';
    board[2][9] = 'x';
    board[8][8] = 'x';
    board[8][10] = 'o';
    board[8][11] = 'o';
    board[14][6] = 'o';
    board[14][8] = 'o';
    board[14][10] = 'o';

    CHECK(horizontal_winner_possible(board) == -1440);
}

TEST_CASE("Minimax: minimax vertical_winner_possible", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[5][2] = 'x';
    board[9][2] = 'x';
    board[8][8] = 'x';
    board[10][8] = 'o';
    board[11][8] = 'o';
    board[6][14] = 'o';
    board[8][14] = 'o';
    board[10][14] = 'o';

    CHECK(vertical_winner_possible(board) == -1440);
}

TEST_CASE("Minimax: minimax diagonal_left_winner_possible", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[4][8] = 'x';
    board[8][4] = 'x';
    board[8][6] = 'x';
    board[10][4] = 'o';
    board[11][3] = 'o';
    board[6][10] = 'o';
    board[8][8] = 'o';
    board[10][6] = 'o';

    CHECK(diagonal_left_winner_possible(board) == -1440);
}

TEST_CASE("Minimax: minimax heuristic", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[5][4] = 'x';
    board[5][5] = 'x';
    board[5][7] = 'x';
    board[5][8] = 'x';
    board[5][9] = 'o';
    board[6][6] = 'o';
    board[6][7] = 'o';
    board[6][8] = 'o';

    CHECK(heuristic(board) == -42089);
}


TEST_CASE("Minimax: minimax", "[ai][minimax]")
{
    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';


    board[5][3] = 'x';
    board[5][4] = 'o';
    board[5][5] = 'o';
    board[5][6] = 'o';
    board[5][7] = 'o';
    board[5][8] = 'x';

//    REQUIRE(heuristic(board) == 0);

    auto x = minimax(board, 4);

    CHECK(x.first == 5);
    CHECK(x.second == 3);
}
