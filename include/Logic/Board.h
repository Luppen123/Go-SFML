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
    int m_vectorWidth;
    std::vector<Intersection> m_boardState;

public:
    Board(int boardSize);

    int getBoardSize() const;
    int convertCoordinatesToIndex(int x, int y) const;

    std::vector<Intersection> getBoardState() const;

    bool isEmptyAt(int index) const;

    void setStone(int index, Stone color);
};


#endif