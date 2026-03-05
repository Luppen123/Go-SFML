#ifndef BOARD_Hd
#define BOARD_Hd

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
    Stone m_currentPlayer;      //GameLogic Y
    int m_boardSize;            //Board Y
    int m_vectorWidth;          //Board, I guess can be taken via method
    std::vector<Intersection> m_boardVector;    //Board Y 
    std::vector<Group> m_groupVector;   //GameLogic Y

public:
    BoardLogic(int boardSize);

    int getBoardSize() const;   //Board Y
    int getInternalIndex(int x, int y) const;   //board Y
    Stone getCurrentPlayer() const; //GameLogic
    bool fieldEmptyAtIndex(int index) const;    //board Y
    std::vector<Intersection> getBoardVector() const;   //board Y
    void printBoardState(); // View???
    void placeStone(int index); //GameLogic
    std::pair<int, int> coordinatesLogicalToGraphical(int index) const;     //view


};

#endif