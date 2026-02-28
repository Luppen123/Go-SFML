#ifndef BOARD_LOGIC_H
#define BOARD_LOGIC_H

#include <utility>
#include <vector>
#include "Stone.h"


struct Intersection 
{
    int liberties;
    Stone stone = Stone::None;
};

struct Group
{
    Stone color;
    std::vector<int> StonesInGroup;
    int liberties;
};

class BoardLogic
{
private:
    int m_BoardSize;
    std::vector<std::vector<Intersection>> m_boardVector;

public:
    BoardLogic(int bs) : m_BoardSize(bs) {}
    int CalculateX(const int& xPixel, const float& margin, const float& cellSize);
    int CalculateY(const int& yPixel, const float& margin);
    std::pair<int, int> CalculateXY(const int& xPixel, const int& yPixel, const float& margin);
};

#endif