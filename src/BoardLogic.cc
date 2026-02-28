#include "BoardLogic.h"
#include <cmath>

int BoardLogic::CalculateX(const int& xPixel, const float& margin, const float& cellSize)
{
    int roundedX = std::round((static_cast<float>(xPixel) - margin) / cellSize);
    
    if(roundedX < 0)
        return 0;
    
    else if(roundedX > m_BoardSize-1)
        return m_BoardSize-1;
    
    else 
        return roundedX;
}