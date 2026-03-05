#ifndef GAME_GEOMETRY_H
#define GAME_GEOMETRY_H

#include <cmath>
#include <algorithm>


struct Coordinate
{
    int x;
    int y;
};

class GameGeometry
{
private:
    float m_cellSize;
    float m_margin;
    int m_boardSize; //Not sure about that

public:
    GameGeometry(float cellSize, float margin, int boardSize);

    Coordinate pixelsToCoordinates(int px, int py); 
    float getCellSize();
    float getMargin();
};

#endif
