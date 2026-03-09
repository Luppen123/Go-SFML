#ifndef BOARD_H
#define BOARD_H

#include "Common.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>

struct Group
{
    int libertyCount;
    std::vector<Coordinate> stoneCoordinates;
};

struct Intersection 
{
    Stone stone = Stone::None;

    bool isEmpty() const { return stone == Stone::None; }
    bool isWall() const { return stone == Stone::Wall; }

    bool operator==(const Intersection& i) const {return stone == i.stone; }
};

class Board
{
private:
    int m_boardSize;
    int m_vectorWidth;
    std::vector<Intersection> m_boardState;
    std::vector<Intersection> m_previousBoardState;

public:
    Board(int boardSize);

    int getBoardSize() const;
    int convertCoordinatesToIndex(Coordinate coordinates) const;
    Coordinate convertIndexToCoordinates(int index) const;

    std::vector<Intersection> getBoardState() const;
    void setBoardState(const std::vector<Intersection>& newBoardState);

    bool isEmptyAt(int index) const;
    bool isLegal(int index) const;
    bool isLegal(Coordinate coordinates) const;

    void setStone(int index, Stone color);
    void setStone(Coordinate coordinates, Stone color);

    void setPreviousBoardState(std::vector<Intersection> boardState);
    std::vector<Intersection> getPreviousBoardState() const;

    Stone getStone(int index) const;
    Stone getStone(Coordinate coordinates) const;

    // void deleteGroup(std::vector<Coordinate>& stones);
    Group floodFill(Coordinate coordinates, Stone currentPlayer) const;

    //test function
    void printBoardState() const;
};


#endif