#include "GameGeometry.h"

GameGeometry::GameGeometry(float cellSize, float margin, int boardSize) :
    m_cellSize(cellSize), 
    m_margin(margin),
    m_boardSize(boardSize) {}


Coordinate GameGeometry::pixelsToCoordinates(int px, int py)
{
    int x = std::round((static_cast<float>(px) - m_margin) / m_cellSize);
    int y = std::round((static_cast<float>(py) - m_margin) / m_cellSize);

    x = std::clamp(x, 0, m_boardSize);
    y = std::clamp(x, 0, m_boardSize);

    return {x, y};
}

float GameGeometry::getCellSize()
{
    return m_cellSize;
}

float GameGeometry::getMargin()
{
    return m_margin;
}
