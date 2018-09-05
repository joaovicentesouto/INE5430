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

pair_played minimax(board_type board, int depth)
{
    return {0,0};
}

pair_weight minimax(board_type board, int depht, pair_played last_played, double alpha, double beta, char player)
{
    return {0,0};
}

double utility(board_type board)
{
    return horizontal_points(board) + vertical_points(board) + diagonal_left_points(board) + diagonal_right_points(board);
}

double heuristic(board_type board)
{
    return 0;
}

}   // namespace ai

#endif // MINIMAX_HPP
