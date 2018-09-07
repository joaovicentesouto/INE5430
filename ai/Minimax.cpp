#include "Minimax.hpp"

//! João Vicente Souto and Bruno Bonotto

namespace ai
{

double get_utility_points(int points_amount, char player)
{
    bool is_computer = player == 'x';

    switch (points_amount)
    {
    case 1:  return is_computer ? 1         : -1;
    case 2:  return is_computer ? 250       : -250;
    case 3:  return is_computer ? 50000     : -50000;
    case 4:  return is_computer ? 3600000   : -3600000;
    case 5:  return is_computer ? 200000000 : -200000000;
    default: return 0;
    }
}

double get_heuristic_points(int points_amount, char player)
{
    bool is_computer = player == 'x';

    switch (points_amount)
    {
    case 1:  return is_computer ? 10    : -10;
    case 2:  return is_computer ? 100   : -100;
    case 3:  return is_computer ? 1000  : -1000;
    case 4:  return is_computer ? 10000 : -10000;
    default: return 0;
    }
}

double horizontal_utility(board_type board)
{
    double result = 0;

    for (int i = 0; i < 15; ++i)
    {
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 0; j < 15; ++j)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                result += get_utility_points(point, current);
                openned = board[i][j] == ' ';
                point = openned ? 0 : 1;
            }
            else
            {
                openned = current == ' ';
                point = 1;
            }

            current = board[i][j];
        }

        if ((openned && point) || point == 5)
            result += get_utility_points(point, current);
    }

    return result;
}

double vertical_utility(board_type board)
{
    double result = 0;

    for (int j = 0; j < 15; ++j)
    {
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int i = 0; i < 15; ++i)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                result += get_utility_points(point, current);

                openned = board[i][j] == ' ';
                point = openned ? 0 : 1;
            }
            else
            {
                openned = current == ' ';
                point = 1;
            }

            current = board[i][j];
        }

        if ((openned && point) || point == 5)
            result += get_utility_points(point, current);
    }

    return result;
}

double diagonal_right_utility(board_type board)
{
    double result = 0;

    for (int k = 0; k < 15; ++k)
    {
        int i = 0, point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 14 - k; j < 15; ++j)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                result += get_utility_points(point, current);

                openned = board[i][j] == ' ';
                point = openned ? 0 : 1;
            }
            else
            {
                point = 1;
                openned = current == ' ';
            }

            current = board[++i][j];
        }

        if ((openned && point) || point == 5)
            result += get_utility_points(point, current);
    }

    for (int k = 15; k < 29; ++k)
    {
        int i = 0, point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = k - 14; j < 15; ++j)
        {
            if (board[j][i] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[j][i] == ' ' || openned) && point) || point == 5)
            {
                result += get_utility_points(point, current);

                openned = board[i][j] == ' ';
                point = openned ? 0 : 1;
            }
            else
            {
                openned = current == ' ';
                point = 1;
            }

            current = board[j][++i];
        }

        if ((openned && point) || point == 5)
            result += get_utility_points(point, current);
    }

    return result;
}

double diagonal_left_utility(board_type board)
{
    double result = 0;

    for (int k = 0; k < 15; ++k)
    {
        int i = 0, point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = k; j > -1; --j)
        {
            if (board[i][j] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[i][j] == ' ' || openned) && point) || point == 5)
            {
                result += get_utility_points(point, current);

                openned = board[i][j] == ' ';
                point = openned ? 0 : 1;
            }
            else
            {
                openned = current == ' ';
                point = 1;
            }

            current = board[++i][j];
        }

        if ((openned && point) || point == 5)
            result += get_utility_points(point, current);
    }

    for (int k = 0; k < 15; ++k)
    {
        int i = k + 1;
        int point = 0;
        char current = ' ';
        bool openned = false;

        for (int j = 14; j > k + 1; --j)
        {
            if (board[j][i] == current)
            {
                if (current != ' ')
                    point++;
            }
            else if (((board[j][i] == ' ' || openned) && point) || point == 5)
            {
                result += get_utility_points(point, current);

                openned = board[i][j] == ' ';
                point = openned ? 0 : 1;
            }
            else
            {
                openned = current == ' ';
                point = 1;
            }

            current = board[j][++i];
        }

        if ((openned && point) || point == 5)
            result += get_utility_points(point, current);
    }

    return result;
}

double horizontal_heuristic(board_type board)
{
    double result = 0;

    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            int point = 0;
            char current = ' ';

            for (int k = j; k < j + 5; ++k)
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

            result += get_heuristic_points(point, current);
        }
    }

    return result;
}

double vertical_heuristic(board_type board)
{
    double result = 0;

    for (int j = 0; j < 15; ++j)
    {
        for (int i = 0; i < 11; ++i)
        {
            int point = 0;
            char current = ' ';

            for (int k = i; k < i + 5; ++k)
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

            result += get_heuristic_points(point, current);
        }
    }

    return result;
}

double diagonal_right_heuristic(board_type board)
{
    double result = 0;

    for (int k = 4; k < 15; ++k)
    {
        for (int j = 14 - k, i = 0; j < 11; ++j, ++i)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; ++m, ++n)
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

            result += get_heuristic_points(point, current);
        }
    }

    for (int k = 1; k < 11; ++k)
    {
        for (int i = k, j = 0; i < 11; ++i, ++j)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; ++m, ++n)
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

            result += get_heuristic_points(point, current);
        }
    }

    return result;
}

double diagonal_left_heuristic(board_type board)
{
    double result = 0;

    for (int k = 4; k < 15; ++k)
    {
        for (int j = k, i = 0; j > 3; --j, ++i)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; ++m, n--)
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

            result += get_heuristic_points(point, current);
        }
    }

    for (int k = 1; k < 11; ++k)
    {
        for (int i = k, j = 14; i < 11; ++i, --j)
        {
            int point = 0;
            char current = ' ';

            for (int m = i, n = j; m < i + 5; ++m, n--)
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

            result += get_heuristic_points(point, current);
        }
    }

    return result;
}

bool is_game_over(board_type board)
{
    double weight = std::abs(utility(board));
    return weight >= 102800000;
}

bool is_game_over(board_type board, pair_played last_played)
{
    int point = 0;
    int x = last_played.first;
    int y = last_played.second;
    char player = board[x][y];

    for (int i = y - 4; i < y + 5 && i < 15; ++i)
    {
        if (i < 0)
            continue;

        if (board[x][i] == player)
        {
            if (++point == 5)
                return true;
        }
        else
            point = 0;
    }

    point = 0;
    for (int i = x - 4; i < x + 5 && i < 15; ++i)
    {
        if (i < 0)
            continue;

        if (board[i][y] == player)
        {
            if (++point == 5)
                return true;
        }
        else
            point = 0;
    }

    point = 0;
    for (int i = x - 4, j = y - 4; i < x + 5 && i < 15 && j < 15; ++i, ++j)
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
    for (int i = x - 4, j = y + 4; i < x + 5 && i < 15 && j > -1; ++i, --j)
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

double utility(board_type board)
{
    return horizontal_utility(board)
         + vertical_utility(board)
         + diagonal_right_utility(board)
         + diagonal_left_utility(board);
}

double heuristic(board_type board)
{
    return utility(board)
         + horizontal_heuristic(board)
         + vertical_heuristic(board)
         + diagonal_right_heuristic(board)
         + diagonal_left_heuristic(board);
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
        for (int j = k; j < t && alpha < beta; ++j)
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
                else if (weigth > child_weight)
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
            else if (weigth > child_weight)
            {
                weigth = child_weight;
                beta = child_weight;
            }

            board[t - 1][j] = ' ';
        }

        for (int i = k + 1; i < t - 1 && alpha < beta; ++i)
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
                else if (weigth > child_weight)
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
            else if (weigth > child_weight)
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
        for (int j = k; j < t; ++j)
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

        for (int i = k + 1; i < t - 1; ++i)
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
