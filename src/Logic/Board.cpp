#include "Board.h"
#include <cmath>

Board::Board(int boardSize)
{
    m_boardSize = boardSize;
    m_vectorWidth = m_boardSize+2;

    int size = m_vectorWidth * m_vectorWidth;
    m_boardState.reserve(size);

    for(int i = 0; i < size; i++)
    {
        int rowIndex = std::floor(i / (m_vectorWidth));
        int columnIndex = i - ((m_vectorWidth) * rowIndex);

        if(rowIndex == 0  || columnIndex == 0 || rowIndex == m_boardSize+1 || columnIndex == m_boardSize+1)
            m_boardState.emplace_back(Intersection{Stone::Wall});
        else
            m_boardState.emplace_back(Intersection{Stone::None});
    }
}

int Board::getBoardSize() const
{
    return m_boardSize;
}

int Board::convertToVectorIndex(int x, int y) const
{
    return (m_vectorWidth * (y + 1)) + (x + 1);         
}

std::vector<Intersection> Board::getBoardState() const
{
    return m_boardState;
}

bool Board::isEmptyAt(int index) const
{
    return m_boardState[index].isEmpty();
}

void Board::setStone(int index, Stone color)
{
    m_boardState[index].stone = color;
}