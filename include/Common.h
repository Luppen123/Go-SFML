#ifndef COMMON_H
#define COMMON_H

enum class Stone {
    None,
    Wall,
    Black,
    White,
};

struct Coordinate
{
    int x;
    int y;

    bool operator<(const Coordinate& other) const 
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

static constexpr Coordinate DIRECTIONS[4] = 
{
    {0,  1}, {0, -1}, {-1, 0}, {1, 0}
};


#endif