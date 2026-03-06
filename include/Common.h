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
};

#endif