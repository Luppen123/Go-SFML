#ifndef BOARD_H
#define BOARD_H

#include "Common.h"
#include <vector>
#include <iostream>
#include <cmath>

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
    int convertCoordinatesToIndex(Coordinate coordinates) const;
    Coordinate convertIndexToCoordinates(int index) const;

    std::vector<Intersection> getBoardState() const;

    bool isEmptyAt(int index) const;
    bool isLegal(int index) const;
    bool isLegal(Coordinate coordinates) const;

    void setStone(int index, Stone color);
    void setStone(Coordinate coordinates, Stone color);

    Stone getStone(int index) const;
    Stone getStone(Coordinate coordinates) const;

    void deleteGroup(std::vector<Coordinate>& stones);

    //test function
    void printBoardState() const;
};


#endif