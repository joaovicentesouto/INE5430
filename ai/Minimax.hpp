//! João Vicente Souto

#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include <limits>
#include <functional>
#include <iostream>

#include "Util.hpp"


namespace ai
{

using board_type = char[15][15];
using pair_played = std::pair<int,int>;
using pair_weight = std::pair<double,double>;

double horizontal_points(board_type board)
{
    double result = 0;

    for (int i = 0; i < 15; i++) {

        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 0; j < 15; j++) {

            if (board[i][j] == current) {

                if (current != ' ')
                    point++;

            } else if (((board[i][j] == ' ' || openned) && point) || point == 5) {

                switch(point) {
                    case 1: current == 'x' ? result++ : result--; break;
                    case 2: current == 'x' ? result += 250 : result -= 250; break;
                    case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                    case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                    default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ') {
                    openned = true;
                    point = 0;
                } else {
                    openned = false;
                    point = 1;
                }

            } else {

                point = 1;
                openned = current == ' ';

            }

            current = board[i][j];

        }

        if ((openned && point) || point == 5)

            switch(point) {
                case 1: current == 'x' ? result++ : result--; break;
                case 2: current == 'x' ? result += 250 : result -= 250; break;
                case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
    }

    return result;
}

double vertical_points(board_type board)
{
    double result = 0;

    for (int j = 0; j < 15; j++) {

        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int i = 0; i < 15; i++) {

            if (board[i][j] == current) {

                if (current != ' ')
                    point++;

            } else if (((board[i][j] == ' ' || openned) && point) || point == 5) {

                switch(point) {
                    case 1: current == 'x' ? result++ : result--; break;
                    case 2: current == 'x' ? result += 250 : result -= 250; break;
                    case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                    case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                    default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ') {
                    openned = true;
                    point = 0;
                } else {
                    openned = false;
                    point = 1;
                }

            } else {

                point = 1;
                openned = current == ' ';

            }

            current = board[i][j];

        }

        if ((openned && point) || point == 5)

            switch(point) {
                case 1: current == 'x' ? result++ : result--; break;
                case 2: current == 'x' ? result += 250 : result -= 250; break;
                case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
    }

    return result;
}

#include <iostream>

double diagonal_right_points(board_type board)
{
    double result = 0;

    for (int k = 0; k < 15; k++) {

        int i = 0;
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 14-k; j < 15; j++) {

            if (board[i][j] == current) {

                if (current != ' ')
                    point++;

            } else if (((board[i][j] == ' ' || openned) && point) || point == 5) {

                switch(point) {
                    case 1: current == 'x' ? result++ : result--; break;
                    case 2: current == 'x' ? result += 250 : result -= 250; break;
                    case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                    case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                    default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ') {
                    openned = true;
                    point = 0;
                } else {
                    openned = false;
                    point = 1;
                }

            } else {

                point = 1;
                openned = current == ' ';

            }

            current = board[i++][j];

        }

        if ((openned && point) || point == 5)

            switch(point) {
                case 1: current == 'x' ? result++ : result--; break;
                case 2: current == 'x' ? result += 250 : result -= 250; break;
                case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }

    }

    for (int k = 15; k < 29; k++) {

        int i = 0;
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = k-14; j < 15; j++) {

            if (board[j][i] == current) {

                if (current != ' ')
                    point++;

            } else if (((board[j][i] == ' ' || openned) && point) || point == 5) {

                switch(point) {
                    case 1: current == 'x' ? result++ : result--; break;
                    case 2: current == 'x' ? result += 250 : result -= 250; break;
                    case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                    case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                    default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[j][i] == ' ') {
                    openned = true;
                    point = 0;
                } else {
                    openned = false;
                    point = 1;
                }

            } else {

                point = 1;
                openned = current == ' ';

            }

            current = board[j][i++];

        }

        if ((openned && point) || point == 5)
            switch(point) {
                case 1: current == 'x' ? result++ : result--; break;
                case 2: current == 'x' ? result += 250 : result -= 250; break;
                case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }

    }

    return result;
}

double diagonal_left_points(board_type board)
{
    double result = 0;

    for (int k = 0; k < 15; k++) {

        int i = 0;
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = k; j > -1; j--) {

            if (board[i][j] == current) {

                if (current != ' ')
                    point++;

            } else if (((board[i][j] == ' ' || openned) && point) || point == 5) {

                switch(point) {
                    case 1: current == 'x' ? result++ : result--; break;
                    case 2: current == 'x' ? result += 250 : result -= 250; break;
                    case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                    case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                    default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ') {
                    openned = true;
                    point = 0;
                } else {
                    openned = false;
                    point = 1;
                }

            } else {

                point = 1;
                openned = current == ' ';

            }

            current = board[i++][j];

        }

        if ((openned && point) || point == 5)

            switch(point) {
                case 1: current == 'x' ? result++ : result--; break;
                case 2: current == 'x' ? result += 250 : result -= 250; break;
                case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }

    }

    for (int k = 0; k < 15; k++) {

        int i = k+1;
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 14; j > k+1; j--) {

            if (board[j][i] == current) {

                if (current != ' ')
                    point++;

            } else if (((board[j][i] == ' ' || openned) && point) || point == 5) {

                switch(point) {
                    case 1: current == 'x' ? result++ : result--; break;
                    case 2: current == 'x' ? result += 250 : result -= 250; break;
                    case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                    case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                    default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[j][i] == ' ') {
                    openned = true;
                    point = 0;
                } else {
                    openned = false;
                    point = 1;
                }

            } else {

                point = 1;
                openned = current == ' ';

            }

            current = board[j][i++];

        }

        if ((openned && point) || point == 5)
            switch(point) {
                case 1: current == 'x' ? result++ : result--; break;
                case 2: current == 'x' ? result += 250 : result -= 250; break;
                case 3: current == 'x' ? result += 50000 : result -= 50000; break;
                case 4: current == 'x' ? result += 3600000 : result -= 3600000; break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }

    }

    return result;
}

double utility(board_type board)
{
    return horizontal_points(board) + vertical_points(board) + diagonal_left_points(board) + diagonal_right_points(board);
}

double horizontal_winner_possible(board_type board)
{
    double result = 0;

    for (int i = 0; i < 15; i++) {

        for (int j = 0; j < 11; j++) {

            int point = 0;
            char current = ' ';

            for (int k = j; k < j+5; k++) {
                if (board[i][k] == ' ')
                    continue;
                if (current == ' ') {
                    current = board[i][k];
                    point++;
                    continue;
                }
                if (board[i][k] != current) {
                    point = 0;
                    break;
                }
                point++;
            }

            switch(point) {
                case 1: current == 'x' ? result += 10 : result -= 10; break;
                case 2: current == 'x' ? result += 100 : result -= 100; break;
                case 3: current == 'x' ? result += 1000 : result -= 1000; break;
                case 4: current == 'x' ? result += 10000 : result -= 10000; break;
                default: break;
            }

        }
    }

    return result;
}

double vertical_winner_possible(board_type board)
{
    double result = 0;

    for (int j = 0; j < 15; j++) {

        for (int i = 0; i < 11; i++) {

            int point = 0;
            char current = ' ';

            for (int k = i; k < i+5; k++) {
                if (board[k][j] == ' ')
                    continue;
                if (current == ' ') {
                    current = board[k][j];
                    point++;
                    continue;
                }
                if (board[k][j] != current) {
                    point = 0;
                    break;
                }
                point++;
            }

            switch(point) {
                case 1: current == 'x' ? result += 10 : result -= 10; break;
                case 2: current == 'x' ? result += 100 : result -= 100; break;
                case 3: current == 'x' ? result += 1000 : result -= 1000; break;
                case 4: current == 'x' ? result += 10000 : result -= 10000; break;
                default: break;
            }

        }
    }

    return result;
}

double diagonal_right_winner_possible(board_type board)
{
    double result = 0;

    for (int k = 4; k < 15; k++) {

        for (int j = 14-k, i = 0; j < 11; j++, i++) {

            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i+5; m++, n++) {
                if (board[m][n] == ' ')
                    continue;
                if (current == ' ') {
                    current = board[m][n];
                    point++;
                    continue;
                }
                if (board[m][n] != current) {
                    point = 0;
                    break;
                }
                point++;
            }

            switch(point) {
                case 1: current == 'x' ? result += 10 : result -= 10; break;
                case 2: current == 'x' ? result += 100 : result -= 100; break;
                case 3: current == 'x' ? result += 1000 : result -= 1000; break;
                case 4: current == 'x' ? result += 10000 : result -= 10000; break;
                default: break;
            }
        }
    }

    for (int k = 1; k < 11; k++) {

        for (int i = k, j = 0; i < 11; i++, j++) {

            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i+5; m++, n++) {
                if (board[m][n] == ' ')
                    continue;
                if (current == ' ') {
                    current = board[m][n];
                    point++;
                    continue;
                }
                if (board[m][n] != current) {
                    point = 0;
                    break;
                }
                point++;
            }

            switch(point) {
                case 1: current == 'x' ? result += 10 : result -= 10; break;
                case 2: current == 'x' ? result += 100 : result -= 100; break;
                case 3: current == 'x' ? result += 1000 : result -= 1000; break;
                case 4: current == 'x' ? result += 10000 : result -= 10000; break;
                default: break;
            }
        }
    }

    return result;
}

double diagonal_left_winner_possible(board_type board)
{
    double result = 0;

    for (int k = 4; k < 15; k++) {

        for (int j = k, i = 0; j > 3; j--, i++) {

            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i+5; m++, n--) {
                if (board[m][n] == ' ')
                    continue;
                if (current == ' ') {
                    current = board[m][n];
                    point++;
                    continue;
                }
                if (board[m][n] != current) {
                    point = 0;
                    break;
                }
                point++;
            }

            switch(point) {
                case 1: current == 'x' ? result += 10 : result -= 10; break;
                case 2: current == 'x' ? result += 100 : result -= 100; break;
                case 3: current == 'x' ? result += 1000 : result -= 1000; break;
                case 4: current == 'x' ? result += 10000 : result -= 10000; break;
                default: break;
            }
        }
    }

    for (int k = 1; k < 11; k++) {

        for (int i = k, j = 14; i < 11; i++, j--) {

            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i+5; m++, n--) {
                if (board[m][n] == ' ')
                    continue;
                if (current == ' ') {
                    current = board[m][n];
                    point++;
                    continue;
                }
                if (board[m][n] != current) {
                    point = 0;
                    break;
                }
                point++;
            }

            switch(point) {
                case 1: current == 'x' ? result += 10 : result -= 10; break;
                case 2: current == 'x' ? result += 100 : result -= 100; break;
                case 3: current == 'x' ? result += 1000 : result -= 1000; break;
                case 4: current == 'x' ? result += 10000 : result -= 10000; break;
                default: break;
            }
        }
    }

    return result;
}

double heuristic(board_type board)
{
    return utility(board) + horizontal_winner_possible(board) + vertical_winner_possible(board) + diagonal_right_winner_possible(board) + diagonal_left_winner_possible(board);
}

pair_played minimax(board_type board, int depth)
{
    return {0,0};
}

pair_weight minimax(board_type board, int depht, pair_played last_played, double alpha, double beta, char player)
{
    return {0,0};
}

}   // namespace ai

#endif // MINIMAX_HPP
