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

        Move(int x, int y, Move * left, Move * right, bool valid) :
            _x(x), _y(y), _left(left), _right(right), _valid(valid)
        {

        };

        int _x{-1}, _y{-1};

    private:
        Move *_left{nullptr};
        Move *_right{nullptr};
        bool _valid{true};
    };

    template<int width, int height>
    class MovesList
    {
    public:
        MovesList();

        Move* remove_first();
        Move* next(Move * previous);

        void put_back(Move * move);
        void remove(Move * move);
        Move * remove(int x, int y);

        bool empty() { return _moves.empty(); };

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

    _moves[0] = {height/2, width/2, nullptr, &_moves[1], true};

    int index = 1, max_index = width * height;

    for (int k = _moves[0]._x - 1, t = k + 3; k > -1; k--, t++)
    {
        for (int j = k; j < t; ++j)
        {
            _moves[index] = {  k, j, &_moves[index - 1], &_moves[index + 1], true};
            index++;
            _moves[index] = {t-1, j, &_moves[index - 1], &_moves[index + 1], true};
            index++;
        }

        for (int i = k + 1; i < t - 1; ++i)
        {
            _moves[index] = {i,   k, &_moves[index - 1], &_moves[index + 1], true};
            index++;

            ai::Move * next = index + 1 < max_index ? &_moves[index + 1] : nullptr;
            _moves[index] = {i, t-1, &_moves[index - 1], next, true};
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

    if (first->_left)
        first->_left->_right = first->_right;
    
    if (_head)
        _head->_left = nullptr;

    first->_valid = false;

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
        
        next->_valid = false;
    }

    previous->_valid = true;

    return next;
}

template<int width, int height>
void ai::MovesList<width, height>::put_back(Move * move)
{
    if (move->_left)
        move->_left->_right = move;

    if (move->_right)
    {
        move->_right->_left = move;

        if (move->_right == _head)
            _head = move;
    }

    move->_valid = true;
}

template<int width, int height>
void ai::MovesList<width, height>::remove(Move * move)
{
    if (!move->_valid)
           return;

    if (move->_left)
        move->_left->_right = move->_right;

    if (move->_right)
    {
        move->_right->_left = move->_left;

        if (move == _head)
            _head = move->_right;
    }

    move->_valid = false;
}

template<int width, int height>
ai::Move * ai::MovesList<width, height>::remove(int x, int y)
{
    for (auto i = 0; i < _moves.size(); ++i)
        if (_moves[i]._x == x && _moves[i]._y == y)
        {
            this->remove(&_moves[i]);
            _moves[i]._valid = false;
            return &_moves[i];
        }

    return nullptr;
}

#endif // MOVESLIST_HPP
