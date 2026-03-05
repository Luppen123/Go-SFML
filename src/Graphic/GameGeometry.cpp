#include "GameGeometry.h"

GameGeometry::GameGeometry(float cellSize, float margin) :
    m_cellSize(cellSize), 
    m_margin(margin) {}

int GameGeometry::pixelsToCoordinates(int px, int py)
{
    return 1;
}


    // int coordinatesToIndex(Coordinate coordinates);
    // Coordinate indexToCoordinates(int index);
