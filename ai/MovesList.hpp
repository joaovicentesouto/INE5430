//! João Vicente Souto and Bruno Bonotto

#ifndef MOVESLIST_HPP
#define MOVESLIST_HPP

#include <limits>
#include <functional>
#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

namespace ai
{
    template<int width, int height>
    class MovesList;

    class Move
    {
    public:
        template<int width, int height>
        friend class MovesList;

        Move() = default;
        ~Move() = default;

        Move(const Move&) = default;
        Move& operator=(const Move&) = default;

        Move(Move&&) = default;
        Move& operator=(Move&&) = default;

        Move(int x, int y, Move * left, Move * right) :
            _x(x), _y(y), _left(left), _right(right)
        {

        };

        int _x{-1}, _y{-1};

    private:
        Move *_left{nullptr};
        Move *_right{nullptr};
    };

    template<int width, int height>
    class MovesList
    {
    public:
        MovesList();

        Move* remove_first();
        Move* next(Move * previous);

    private:
        std::vector<Move> _moves;
        Move * _head;
    };
}   // namespace ai

template<int width, int height>
ai::MovesList<width, height>::MovesList() :
    _moves(width * height),
    _head{&_moves[0]}
{
    assert(width % 2 == 1 && height % 2 == 1);

    _moves[0] = {height/2, width/2, nullptr, &_moves[1]};

    int index = 1, max_index = width * height;

    for (int k = _moves[0]._x - 1, t = k + 3; k > -1; k--, t++)
    {
        for (int j = k; j < t; ++j)
        {
            _moves[index] = {  k, j, &_moves[index - 1], &_moves[index + 1]};
            index++;
            _moves[index] = {t-1, j, &_moves[index - 1], &_moves[index + 1]};
            index++;
        }

        for (int i = k + 1; i < t - 1; ++i)
        {
            _moves[index] = {i,   k, &_moves[index - 1], &_moves[index + 1]};
            index++;

            ai::Move * next = index + 1 < max_index ? &_moves[index + 1] : nullptr;
            _moves[index] = {i, t-1, &_moves[index - 1], next};
            index++;
        }
    }
}

template<int width, int height>
ai::Move* ai::MovesList<width, height>::remove_first()
{
    if (!_head)
        return nullptr;

    auto first = _head;
    _head = first->_right;
    
    if (first->_right)
        first->_right->_left = nullptr;

    return first;
}

template<int width, int height>
ai::Move* ai::MovesList<width, height>::next(Move * previous)
{
    if (previous->_left)
        previous->_left->_right = previous;

    auto next = previous->_right;

    if (next)
    {
        next->_left = previous;
        previous->_right = next->_right;

        if (next == _head)
            _head = previous;
    }

    return next;
}

#endif // MOVESLIST_HPP
