#ifndef BOARD_LOGIC_H
#define BOARD_LOGIC_H

#include <utility>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include "Stone.h"

struct Intersection 
{
    Stone stone = Stone::None;

    bool isEmpty() const { return stone == Stone::None; }
    bool isWall() const { return stone == Stone::Wall; }
};

struct Group
{
    Stone color;
    std::vector<std::pair<int, int>> stonesCount;
    std::set<std::pair<int, int>> liberties;
};

class BoardLogic
{
private:
    Stone m_currentPlayer;
    int m_boardSize;
    int m_vectorWidth;
    std::vector<Intersection> m_boardVector;
    std::vector<Group> m_groupVector;

public:
    BoardLogic(int boardSize);

    int getBoardSize() const;
    Stone getCurrentPlayer() const;
    std::vector<Intersection> getBoardVector() const;
    void printBoardState();
    int getInternalIndex(int x, int y) const;
    bool fieldEmptyAtIndex(int index) const;

};

#endif