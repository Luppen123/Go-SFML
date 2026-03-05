#ifndef BOARD_H
#define BOARD_H

#include "Stone.h"
#include <vector>

struct Intersection 
{
    Stone stone = Stone::None;

    bool isEmpty() const { return stone == Stone::None; }
    bool isWall() const { return stone == Stone::Wall; }
};

class Board
{
private:
    int m_boardSize;
    std::vector<Intersection> m_boardState;

public:
    Board(int boardSize);

    int getBoardSize() const;
    int convertToVectorIndex(int x, int y) const;

    std::vector<Intersection> getBoardState() const;

    bool isEmptyAt(int index) const;
};


#endif