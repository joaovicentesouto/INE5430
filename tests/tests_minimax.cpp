
#include <catch2/catch.hpp>

#include <iostream>

#include <ai/Minimax.hpp>
#include <ai/MovesList.hpp>

using namespace ai;

TEST_CASE("Minimax: minimax horizontal_utility", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(5, 4);
    moves.remove(5, 5);
    moves.remove(5, 6);
    moves.remove(5, 7);
    moves.remove(5, 8);
    moves.remove(5, 9);
    moves.remove(6, 6);
    moves.remove(6, 7);
    moves.remove(6, 8);

    CHECK(horizontal_utility(board) == 199949999);
}

TEST_CASE("Minimax: minimax vertical_utility", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(4, 5);
    moves.remove(5, 5);
    moves.remove(6, 5);
    moves.remove(7, 5);
    moves.remove(8, 5);
    moves.remove(9, 5);
    moves.remove(6, 6);
    moves.remove(7, 6);
    moves.remove(8, 6);

    CHECK(vertical_utility(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_right_utility", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(4, 4);
    moves.remove(5, 5);
    moves.remove(6, 6);
    moves.remove(7, 7);
    moves.remove(8, 8);
    moves.remove(9, 9);
    moves.remove(5, 6);
    moves.remove(6, 7);
    moves.remove(7, 8);

    CHECK(diagonal_right_utility(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_right_utility2", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(4, 4);
    moves.remove(5, 5);
    moves.remove(6, 6);
    moves.remove(7, 7);
    moves.remove(8, 8);
    moves.remove(9, 9);
    moves.remove(7, 6);
    moves.remove(8, 7);
    moves.remove(9, 8);

    CHECK(diagonal_right_utility(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_left_utility", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(6, 8);
    moves.remove(7, 7);
    moves.remove(8, 6);
    moves.remove(9, 5);
    moves.remove(10, 4);
    moves.remove(11, 3);
    moves.remove(7, 6);
    moves.remove(8, 5);
    moves.remove(9, 4);

    CHECK(diagonal_left_utility(board) == 199949999);
}

TEST_CASE("Minimax: minimax diagonal_left_utility2", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(6, 8);
    moves.remove(7, 7);
    moves.remove(8, 6);
    moves.remove(9, 5);
    moves.remove(10, 4);
    moves.remove(11, 3);
    moves.remove(7, 8);
    moves.remove(8, 7);
    moves.remove(9, 6);

    CHECK(diagonal_left_utility(board) == 199949999);
}

TEST_CASE("Minimax: minimax utility", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(5, 4);
    moves.remove(5, 5);
    moves.remove(5, 6);
    moves.remove(5, 7);
    moves.remove(5, 8);
    moves.remove(5, 9);
    moves.remove(6, 6);
    moves.remove(6, 7);
    moves.remove(6, 8);

    CHECK(utility(board) == 199949754);
}

TEST_CASE("Minimax: minimax horizontal_heuristic", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(2, 5);
    moves.remove(2, 8);
    moves.remove(8, 8);
    moves.remove(8, 10);
    moves.remove(8, 11);
    moves.remove(14, 6);
    moves.remove(14, 8);
    moves.remove(14, 10);

    CHECK(horizontal_heuristic(board) == -1440);
}

TEST_CASE("Minimax: minimax vertical_heuristic", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(5, 2);
    moves.remove(9, 2);
    moves.remove(8, 8);
    moves.remove(10, 8);
    moves.remove(11, 8);
    moves.remove(6, 14);
    moves.remove(8, 14);
    moves.remove(10, 14);

    CHECK(vertical_heuristic(board) == -1440);
}

TEST_CASE("Minimax: minimax diagonal_left_heuristic", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(4, 8);
    moves.remove(8, 4);
    moves.remove(8, 6);
    moves.remove(10, 4);
    moves.remove(11, 3);
    moves.remove(6, 10);
    moves.remove(8, 8);
    moves.remove(10, 6);

    CHECK(diagonal_left_heuristic(board) == -1440);
}

TEST_CASE("Minimax: minimax heuristic", "[ai][minimax]")
{
    ai::moves_list_type moves;

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

    moves.remove(5, 4);
    moves.remove(5, 5);
    moves.remove(5, 6);
    moves.remove(5, 7);
    moves.remove(5, 8);
    moves.remove(5, 9);
    moves.remove(6, 6);
    moves.remove(6, 7);
    moves.remove(6, 8);

    CHECK(heuristic(board) == -42089);
}

TEST_CASE("Minimax: game_over", "[ai][minimax]")
{
    ai::moves_list_type moves;

    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[5][3] = 'o';
    board[5][4] = 'o';
    board[5][5] = 'o';
    board[5][6] = 'o';

    std::vector<Move*> moves_removed = {
        moves.remove(5, 3),
        moves.remove(5, 4),
        moves.remove(5, 5),
        moves.remove(5, 6)};

    CHECK(!is_game_over(board));

    for (auto m : moves_removed)
        CHECK(!is_game_over(board, m));

    board[5][7] = 'o';
    moves_removed.push_back(moves.remove(5, 7));

    CHECK(is_game_over(board));

    for (auto m : moves_removed)
        CHECK(is_game_over(board, m));
}

TEST_CASE("Minimax: moves list", "[ai][minimax]")
{
    MovesList<15, 15> list;

    auto head = list.remove_first();
    CHECK((head->_x == 7 && head->_y == 7));

    auto head2 = list.remove_first();
    CHECK((head2->_x == 6 && head2->_y == 6));

    list.put_back(head2);
    list.put_back(head);

    head = list.remove_first();
    CHECK((head->_x == 7 && head->_y == 7));

    head2 = list.next(head);
    CHECK((head2->_x == 6 && head2->_y == 6));

    head = list.remove_first();
    CHECK(head->_x == 7);
    CHECK(head->_y == 7);
    head = list.next(head);
    CHECK(head->_x == 8);
    CHECK(head->_y == 6);
    head = list.remove_first();
    CHECK(head->_x == 7);
    CHECK(head->_y == 7);
}

void print_board(board_type board)
{
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++)
            if (board[i][j] != ' ')
                std::cout << ' ' << board[i][j] << ' ';
            else
                std::cout << " _ ";

        std::cout << std::endl;
    }
}

TEST_CASE("Minimax: minimax", "[ai][minimax]")
{
    ai::moves_list_type moves;

    board_type board;
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            board[i][j] = ' ';

    board[5][4] = 'o';
    board[5][5] = 'o';
    board[5][6] = 'o';
    board[5][7] = 'o';
    board[5][8] = 'x';

    auto i0 = moves.remove(7, 7);
    auto i1 = moves.remove(5, 4);
    auto i2 = moves.remove(5, 5);
    auto i3 = moves.remove(5, 6);
    auto i4 = moves.remove(5, 7);
    auto i5 = moves.remove(5, 8);

    for (auto i = moves.remove_first(); i != nullptr; i = moves.next(i))
    {
        REQUIRE(i0 != i);
        REQUIRE(i1 != i);
        REQUIRE(i2 != i);
        REQUIRE(i3 != i);
        REQUIRE(i4 != i);
        REQUIRE(i5 != i);
    }

    print_board(board);

    auto played = minimax(board, moves, 3);

    CHECK(played->_x == 5);
    CHECK(played->_y == 3);

    board[played->_x][played->_y] = 'x';
    std::cout << std::endl;
    print_board(board);
}