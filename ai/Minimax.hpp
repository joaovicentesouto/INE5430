//! João Vicente Souto

#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include <limits>
#include <functional>
#include <iostream>
#include <limits>
#include <cmath>

namespace ai
{
    using board_type = char[15][15];
    using pair_played = std::pair<int,int>;
    using pair_weight = std::pair<double,double>;

    #define POSITIVE_INFINITE std::numeric_limits<double>::max()
    #define NEGATIVE_INFINITE -POSITIVE_INFINITE

    double horizontal_utility(board_type board);
    double vertical_utility(board_type board);
    double diagonal_right_utility(board_type board);
    double diagonal_left_utility(board_type board);

    double horizontal_heuristic(board_type board);
    double vertical_heuristic(board_type board);
    double diagonal_right_heuristic(board_type board);
    double diagonal_left_heuristic(board_type board);

    double heuristic(board_type board);
    double utility(board_type board);

    bool is_game_over(board_type board);
    bool is_game_over(board_type board, pair_played last_played);

    pair_played minimax(board_type board, const int depth_max);
    double minimax(board_type board, const int depth_max, int depth, pair_played last_played, double alpha, double beta, char player);

}   // namespace ai

#endif // MINIMAX_HPP
