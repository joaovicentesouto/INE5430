
#include <iostream>

#include <ai/Minimax.hpp>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "Please inform the depth!" << std::endl;
        return -1;
    }

    int depth = std::stoi(argv[1]);

    ai::board_type board = { [0 ... 14] = { [0 ... 14] = ' ' } };
    ai::moves_list_type moves;

    auto x = ai::minimax(board, moves, depth);

    std::cout << x->_x << " " << x->_y << std::endl;    

    return 0;
}
