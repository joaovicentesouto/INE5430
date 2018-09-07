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

            current = board[i++][j];
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

            current = board[j][i++];
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

            current = board[i++][j];
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

            current = board[j][i++];
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
    int x = last_played->_x;
    int y = last_played->_y;
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

double minimax(board_type board, moves_list_type& moves, const int depth_max, int depth, pair_played last_played, double alpha, double beta, char player)
{
    if (is_game_over(board, last_played) || moves.empty())
        return utility(board) / depth;

    if (depth == depth_max)
        return heuristic(board) / depth;

    double weigth = player == 'x' ? NEGATIVE_INFINITE : POSITIVE_INFINITE;
    double child_weight;

    for (auto move = moves.remove_first(); move != nullptr; move = moves.next(move))
    {
        if (alpha >= beta)
        {
            moves.put_back(move);
            return weigth;
        }

        if (board[move->_x][move->_y] != ' ')
        {
            std::cout << move->_x << " " << move->_y << " d= " << depth << std::endl;
        }
        board[move->_x][move->_y] = player;

        child_weight = minimax(board, moves, depth_max, depth + 1, move, alpha, beta, player == 'x' ? 'o' : 'x');

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

        board[move->_x][move->_y] = ' ';
    }

    return weigth;
}

pair_played minimax(board_type board, moves_list_type& moves, const int depth_max)
{
    if (is_game_over(board))
        return nullptr;

    double alpha = NEGATIVE_INFINITE;
    double weigth = NEGATIVE_INFINITE;
    pair_played best_played = nullptr;
    double child_weight;

    for (auto move = moves.remove_first(); move != nullptr; move = moves.next(move))
    {
        board[move->_x][move->_y] = 'x';

        child_weight = minimax(board, moves, depth_max, 1, move, alpha, POSITIVE_INFINITE, 'o');

        if (weigth < child_weight)
        {
            weigth = child_weight;
            alpha = child_weight;
            best_played = move;
        }

        board[move->_x][move->_y] = ' ';
    }

    moves.remove(best_played);

    return best_played;
}

} // namespace ai
    
