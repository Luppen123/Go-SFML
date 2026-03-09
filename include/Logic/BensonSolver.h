#ifndef BENSON_h
#define BENSON_H

#include "Logic/Board.h"

struct BensonGroup
{
    //Stone color; //not needed?
    //int healthyEyesCount; //just check BorderingRegionIds.size() bruh
    std::set<int> borderingRegionIds;
    //To marked automatically marked stones
    std::vector<Coordinate> stoneCoordinates;

    bool isAlive;
};

struct BensonRegion
{
    std::set<int> borderingGroupIds;
    //To draw cute field squares for debuging 
    std::vector<Coordinate> emptyCoordinates;
    bool isHealthy = true;
};

class BensonSolver
{
private:
    const Board& m_board;
    std::vector<bool> m_visited; //(m_board.getBoardSize() + 2 * m_board.getBoardSize() + 2, false)
    std::vector<BensonGroup> m_groups;
    std::vector<BensonRegion> m_regions;

public:
    BensonSolver(const Board& board);

    void scanBoard();

};

#endif