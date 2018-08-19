//! João Vicente Souto

#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include <limits>
#include <functional>

namespace ai::minimax
{

template <typename Data, typename Utility, typename Heuristic>
class Manipulator
{
public:
    using function_t = std::function<int(const &T)>;
    using min_value  = std::numeric_limits<int>::min;
    using max_value  = std::numeric_limits<int>::max;

    Manipulator(size_t max_depth) :
        _maximum_depth{max_depth}
    {
    }

    Manipulator(const Manipulator &) = default;
    Manipulator &operator=(const Manipulator &) = default;

    Manipulator(Manipulator &&) = default;
    Manipulator &operator=(Manipulator &&) = default;

private:
    class Node
    {
    public:
        Node(const T& data) : _data(data) {}

        Node(const Node &) = default;
        Node &operator=(const Node &) = default;

        Node(Node &&) = default;
        Node &operator=(Node &&) = default;

    private:
        int      _alfa{ min_value };
        int      _beta{ max_value };
        const T& _data;
    };

    size_t     _maximum_depth{-1};
    function_t _utility  { [](const T&){ return 0; } };
    function_t _heuristic{ [](const T&){ return 0; } };
};

}   // namespace ai::minimax

#endif // DESIMONETREE_H