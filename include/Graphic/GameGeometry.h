#ifndef GAME_GEOMETRY_H
#define GAME_GEOMETRY_H

#include <cmath>
#include <algorithm>
#include "Common.h"

class GameGeometry
{
private:
    float m_cellSize;
    float m_margin;
    int m_boardSize; //Not sure about that

public:
    GameGeometry(float cellSize, float margin, int boardSize);

    Coordinate pixelsToCoordinates(int px, int py) const; 
    float getCellSize() const;
    float getMargin() const;
    float getBoardSize() const;
};

#endif
