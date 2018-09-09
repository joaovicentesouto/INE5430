#include "Minimax.hpp"

//! João Vicente Souto and Bruno Bonotto

namespace ai
{

double horizontal_points(board_type board)
{
    double result = 0;

    for (int i = 0; i < 15; i++)
    {
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 0; j < 15; j++)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                switch (point)
                {
                case 1:  current == 'x' ? result += 1         : result -= 1;         break;
                case 2:  current == 'x' ? result += 250       : result -= 250;       break;
                case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
                case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ')
                {
                    openned = true;
                    point = 0;
                }
                else
                {
                    openned = false;
                    point = 1;
                }
            }
            else
            {
                point = 1;
                openned = current == ' ';
            }

            current = board[i][j];
        }

        if ((openned && point) || point == 5)
        {
            switch (point)
            {
            case 1:  current == 'x' ? result += 1         : result -= 1;         break;
            case 2:  current == 'x' ? result += 250       : result -= 250;       break;
            case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
            case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
            default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
        }
    }

    return result;
}

double vertical_points(board_type board)
{
    double result = 0;

    for (int j = 0; j < 15; j++)
    {
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int i = 0; i < 15; i++)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                switch (point)
                {
                case 1:  current == 'x' ? result += 1         : result -= 1;         break;
                case 2:  current == 'x' ? result += 250       : result -= 250;       break;
                case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
                case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ')
                {
                    openned = true;
                    point = 0;
                }
                else
                {
                    openned = false;
                    point = 1;
                }
            }
            else
            {

                point = 1;
                openned = current == ' ';
            }

            current = board[i][j];
        }

        if ((openned && point) || point == 5)
        {
            switch (point)
            {
            case 1:  current == 'x' ? result += 1         : result -= 1;         break;
            case 2:  current == 'x' ? result += 250       : result -= 250;       break;
            case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
            case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
            default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
        }
    }

    return result;
}

double diagonal_right_points(board_type board)
{
    double result = 0;

    for (int k = 0; k < 15; k++)
    {
        int i = 0, point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 14 - k; j < 15; j++)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                switch (point)
                {
                case 1:  current == 'x' ? result += 1         : result -= 1;         break;
                case 2:  current == 'x' ? result += 250       : result -= 250;       break;
                case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
                case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ')
                {
                    openned = true;
                    point = 0;
                }
                else
                {
                    openned = false;
                    point = 1;
                }
            }
            else
            {
                point = 1;
                openned = current == ' ';
            }

            current = board[i++][j];
        }

        if ((openned && point) || point == 5)
        {
            switch (point)
            {
            case 1:  current == 'x' ? result += 1         : result -= 1;         break;
            case 2:  current == 'x' ? result += 250       : result -= 250;       break;
            case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
            case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
            default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
        }
    }

    for (int k = 15; k < 29; k++)
    {
        int i = 0, point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = k - 14; j < 15; j++)
        {
            if (board[j][i] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[j][i] == ' ' || openned) && point) || point == 5)
            {
                switch (point)
                {
                case 1:  current == 'x' ? result += 1         : result -= 1;         break;
                case 2:  current == 'x' ? result += 250       : result -= 250;       break;
                case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
                case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[j][i] == ' ')
                {
                    openned = true;
                    point = 0;
                }
                else
                {
                    openned = false;
                    point = 1;
                }
            }
            else
            {
                point = 1;
                openned = current == ' ';
            }

            current = board[j][i++];
        }

        if ((openned && point) || point == 5)
        {
            switch (point)
            {
            case 1:  current == 'x' ? result += 1         : result -= 1;         break;
            case 2:  current == 'x' ? result += 250       : result -= 250;       break;
            case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
            case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
            default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
        }
    }

    return result;
}

double diagonal_left_points(board_type board)
{
    double result = 0;

    for (int k = 0; k < 15; k++)
    {
        int i = 0, point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = k; j > -1; j--)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                switch (point)
                {
                case 1:  current == 'x' ? result += 1         : result -= 1;         break;
                case 2:  current == 'x' ? result += 250       : result -= 250;       break;
                case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
                case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[i][j] == ' ')
                {
                    openned = true;
                    point = 0;
                }
                else
                {
                    openned = false;
                    point = 1;
                }
            }
            else
            {
                point = 1;
                openned = current == ' ';
            }

            current = board[i++][j];
        }

        if ((openned && point) || point == 5)
        {
            switch (point)
            {
            case 1:  current == 'x' ? result += 1         : result -= 1;         break;
            case 2:  current == 'x' ? result += 250       : result -= 250;       break;
            case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
            case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
            default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
        }
    }

    for (int k = 0; k < 15; k++)
    {
        int i = k + 1;
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 14; j > k + 1; j--)
        {
            if (board[j][i] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[j][i] == ' ' || openned) && point) || point == 5)
            {

                switch (point)
                {
                case 1:  current == 'x' ? result += 1         : result -= 1;         break;
                case 2:  current == 'x' ? result += 250       : result -= 250;       break;
                case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
                case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
                default: current == 'x' ? result += 200000000 : result -= 200000000; break;
                }

                if (board[j][i] == ' ')
                {
                    openned = true;
                    point = 0;
                }
                else
                {
                    openned = false;
                    point = 1;
                }
            }
            else
            {
                point = 1;
                openned = current == ' ';
            }

            current = board[j][i++];
        }

        if ((openned && point) || point == 5)
        {
            switch (point)
            {
            case 1:  current == 'x' ? result += 1         : result -= 1;         break;
            case 2:  current == 'x' ? result += 250       : result -= 250;       break;
            case 3:  current == 'x' ? result += 50000     : result -= 50000;     break;
            case 4:  current == 'x' ? result += 3600000   : result -= 3600000;   break;
            default: current == 'x' ? result += 200000000 : result -= 200000000; break;
            }
        }
    }

    return result;
}

double utility(board_type board)
{
    return horizontal_points(board)
         + vertical_points(board)
         + diagonal_left_points(board)
         + diagonal_right_points(board);
}

double horizontal_winner_possible(board_type board)
{
    double result = 0;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            int point = 0;
            char current = ' ';

            for (int k = j; k < j + 5; k++)
            {
                if (board[i][k] == ' ')
                    continue;

                if (current == ' ')
                {
                    current = board[i][k];
                    point++;
                    continue;
                }

                if (board[i][k] != current)
                {
                    point = 0;
                    break;
                }

                point++;
            }

            switch (point)
            {
            case 1: current == 'x' ? result += 10    : result -= 10;    break;
            case 2: current == 'x' ? result += 100   : result -= 100;   break;
            case 3: current == 'x' ? result += 1000  : result -= 1000;  break;
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

    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 11; i++)
        {
            int point = 0;
            char current = ' ';

            for (int k = i; k < i + 5; k++)
            {
                if (board[k][j] == ' ')
                    continue;

                if (current == ' ')
                {
                    current = board[k][j];
                    point++;
                    continue;
                }

                if (board[k][j] != current)
                {
                    point = 0;
                    break;
                }

                point++;
            }

            switch (point)
            {
            case 1: current == 'x' ? result += 10    : result -= 10;    break;
            case 2: current == 'x' ? result += 100   : result -= 100;   break;
            case 3: current == 'x' ? result += 1000  : result -= 1000;  break;
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

    for (int k = 4; k < 15; k++)
    {
        for (int j = 14 - k, i = 0; j < 11; j++, i++)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; m++, n++)
            {
                if (board[m][n] == ' ')
                    continue;

                if (current == ' ')
                {
                    current = board[m][n];
                    point++;
                    continue;
                }

                if (board[m][n] != current)
                {
                    point = 0;
                    break;
                }

                point++;
            }

            switch (point)
            {
            case 1: current == 'x' ? result += 10    : result -= 10;    break;
            case 2: current == 'x' ? result += 100   : result -= 100;   break;
            case 3: current == 'x' ? result += 1000  : result -= 1000;  break;
            case 4: current == 'x' ? result += 10000 : result -= 10000; break;
            default: break;
            }
        }
    }

    for (int k = 1; k < 11; k++)
    {
        for (int i = k, j = 0; i < 11; i++, j++)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; m++, n++)
            {
                if (board[m][n] == ' ')
                    continue;

                if (current == ' ')
                {
                    current = board[m][n];
                    point++;
                    continue;
                }

                if (board[m][n] != current)
                {
                    point = 0;
                    break;
                }

                point++;
            }

            switch (point)
            {
            case 1: current == 'x' ? result += 10    : result -= 10;    break;
            case 2: current == 'x' ? result += 100   : result -= 100;   break;
            case 3: current == 'x' ? result += 1000  : result -= 1000;  break;
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

    for (int k = 4; k < 15; k++)
    {
        for (int j = k, i = 0; j > 3; j--, i++)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; m++, n--)
            {
                if (board[m][n] == ' ')
                    continue;

                if (current == ' ')
                {
                    current = board[m][n];
                    point++;
                    continue;
                }

                if (board[m][n] != current)
                {
                    point = 0;
                    break;
                }

                point++;
            }

            switch (point)
            {
            case 1: current == 'x' ? result += 10    : result -= 10;    break;
            case 2: current == 'x' ? result += 100   : result -= 100;   break;
            case 3: current == 'x' ? result += 1000  : result -= 1000;  break;
            case 4: current == 'x' ? result += 10000 : result -= 10000; break;
            default: break;
            }
        }
    }

    for (int k = 1; k < 11; k++)
    {
        for (int i = k, j = 14; i < 11; i++, j--)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; m++, n--)
            {
                if (board[m][n] == ' ')
                    continue;

                if (current == ' ')
                {
                    current = board[m][n];
                    point++;
                    continue;
                }

                if (board[m][n] != current)
                {
                    point = 0;
                    break;
                }

                point++;
            }

            switch (point)
            {
            case 1: current == 'x' ? result += 10    : result -= 10;    break;
            case 2: current == 'x' ? result += 100   : result -= 100;   break;
            case 3: current == 'x' ? result += 1000  : result -= 1000;  break;
            case 4: current == 'x' ? result += 10000 : result -= 10000; break;
            default: break;
            }
        }
    }

    return result;
}

double heuristic(board_type board)
{
    return utility(board)
         + horizontal_winner_possible(board)
         + vertical_winner_possible(board)
         + diagonal_right_winner_possible(board)
         + diagonal_left_winner_possible(board);
}

bool is_game_over(board_type board)
{
    double weight = std::abs(utility(board));
    return weight >= 102800000;
}

bool is_game_over(board_type board, pair_played last_played)
{
    int point = 0;
    char player = board[last_played.first][last_played.second];

    for (int i = last_played.second - 4; i < last_played.second + 5 && i < 15; i++)
    {
        if (i < 0)
            continue;

        if (board[last_played.first][i] == player)
        {
            if (++point == 5)
                return true;
        }
        else
            point = 0;
    }

    point = 0;
    for (int i = last_played.first - 4; i < last_played.first + 5 && i < 15; i++)
    {
        if (i < 0)
            continue;

        if (board[i][last_played.second] == player)
        {
            if (++point == 5)
                return true;
        }
        else
            point = 0;
    }

    point = 0;
    for (int i = last_played.first - 4, j = last_played.second - 4; i < last_played.first + 5 && i < 15 && j < 15; i++, j++)
    {
        if (i < 0 || j < 0)
            continue;

        if (board[i][j] == player)
        {
            if (++point == 5)
                return true;
        }
        else
            point = 0;
    }

    point = 0;
    for (int i = last_played.first - 4, j = last_played.second + 4; i < last_played.first + 5 && i < 15 && j > -1; i++, j--)
    {
        if (i < 0 || j > 14)
            continue;

        if (board[i][j] == player)
        {
            if (++point == 5)
                return true;
        }
        else
            point = 0;
    }

    return false;
}

double minimax(board_type board, const int depth_max, int depth, pair_played last_played, double alpha, double beta, char player)
{
    if (is_game_over(board, last_played))
        return utility(board) / depth;

    if (depth == depth_max)
        return heuristic(board) / depth;

    double weigth = player == 'x' ? NEGATIVE_INFINITE : POSITIVE_INFINITE;
    double child_weight;

    if (board[7][7] == ' ')
    {
        board[7][7] = 'x';

        child_weight = minimax(board, depth_max, depth + 1, {7, 7}, alpha, beta, player == 'x' ? 'o' : 'x');

        if (player == 'x' && weigth < child_weight)
        {
            weigth = child_weight;
            alpha = child_weight;
        }
        else if (weigth > child_weight)
        {
            weigth = child_weight;
            beta = child_weight;
        }

        board[7][7] = ' ';
    }

    for (int k = 6, t = k + 3; k > -1 && alpha < beta; k--, t++)
    {
        for (int j = k; j < t && alpha < beta; j++)
        {
            if (board[k][j] == ' ')
            {
                board[k][j] = 'x';

                child_weight = minimax(board, depth_max, depth + 1, {k, j}, alpha, beta, player == 'x' ? 'o' : 'x');

                if (player == 'x' && weigth < child_weight)
                {
                    weigth = child_weight;
                    alpha = child_weight;
                }
                else if (player != 'x' && weigth > child_weight)
                {
                    weigth = child_weight;
                    beta = child_weight;
                }

                board[k][j] = ' ';
            }

            if (board[t - 1][j] != ' ')
                continue;

            board[t - 1][j] = 'x';

            child_weight = minimax(board, depth_max, depth + 1, {t - 1, j}, alpha, beta, player == 'x' ? 'o' : 'x');

            if (player == 'x' && weigth < child_weight)
            {
                weigth = child_weight;
                alpha = child_weight;
            }
            else if (player != 'x' && weigth > child_weight)
            {
                weigth = child_weight;
                beta = child_weight;
            }

            board[t - 1][j] = ' ';
        }

        for (int i = k + 1; i < t - 1 && alpha < beta; i++)
        {
            if (board[i][k] == ' ')
            {
                board[i][k] = 'x';

                child_weight = minimax(board, depth_max, depth + 1, {i, k}, alpha, beta, player == 'x' ? 'o' : 'x');

                if (player == 'x' && weigth < child_weight)
                {
                    weigth = child_weight;
                    alpha = child_weight;
                }
                else if (player != 'x' && weigth > child_weight)
                {
                    weigth = child_weight;
                    beta = child_weight;
                }

                board[i][k] = ' ';
            }

            if (board[i][t - 1] != ' ')
                continue;

            board[i][t - 1] = 'x';

            child_weight = minimax(board, depth_max, depth + 1, {i, t - 1}, alpha, beta, player == 'x' ? 'o' : 'x');

            if (player == 'x' && weigth < child_weight)
            {
                weigth = child_weight;
                alpha = child_weight;
            }
            else if (player != 'x' && weigth > child_weight)
            {
                weigth = child_weight;
                beta = child_weight;
            }

            board[i][t - 1] = ' ';
        }
    }

    return weigth;
}

pair_played minimax(board_type board, const int depth_max)
{
    if (is_game_over(board))
        return {-1, -1};

    double alpha = NEGATIVE_INFINITE;
    double weigth = NEGATIVE_INFINITE;
    pair_played best_played{-1, -1};
    double child_weight;

    if (board[7][7] == ' ')
    {
        board[7][7] = 'x';

        child_weight = minimax(board, depth_max, 1, {7, 7}, alpha, POSITIVE_INFINITE, 'o');

        if (weigth < child_weight)
        {
            weigth = child_weight;
            alpha = child_weight;
            best_played = {7, 7};
        }

        board[7][7] = ' ';
    }

    for (int k = 6, t = k + 3; k > -1; k--, t++)
    {
        for (int j = k; j < t; j++)
        {
            if (board[k][j] == ' ')
            {
                board[k][j] = 'x';

                child_weight = minimax(board, depth_max, 1, {k, j}, alpha, POSITIVE_INFINITE, 'o');

                if (weigth < child_weight)
                {
                    weigth = child_weight;
                    alpha = child_weight;
                    best_played = {k, j};
                }

                board[k][j] = ' ';
            }

            if (board[t - 1][j] != ' ')
                continue;

            board[t - 1][j] = 'x';

            child_weight = minimax(board, depth_max, 1, {t - 1, j}, alpha, POSITIVE_INFINITE, 'o');

            if (weigth < child_weight)
            {
                weigth = child_weight;
                alpha = child_weight;
                best_played = {t - 1, j};
            }

            board[t - 1][j] = ' ';
        }

        for (int i = k + 1; i < t - 1; i++)
        {
            if (board[i][k] == ' ')
            {
                board[i][k] = 'x';

                child_weight = minimax(board, depth_max, 1, {i, k}, alpha, POSITIVE_INFINITE, 'o');

                if (weigth < child_weight)
                {
                    weigth = child_weight;
                    alpha = child_weight;
                    best_played = {i, k};
                }

                board[i][k] = ' ';
            }

            if (board[i][t - 1] != ' ')
                continue;

            board[i][t - 1] = 'x';

            child_weight = minimax(board, depth_max, 1, {i, t - 1}, alpha, POSITIVE_INFINITE, 'o');

            if (weigth < child_weight)
            {
                weigth = child_weight;
                alpha = child_weight;
                best_played = {i, t - 1};
            }

            board[i][t - 1] = ' ';
        }
    }

    return best_played;
}

} // namespace ai
