#include "BoardLogic.h"


BoardLogic::BoardLogic(int boardSize)
{
    m_currentPlayer = Stone::Black;

    m_boardSize = boardSize;

    m_vectorWidth = m_boardSize+2;

    int size = m_vectorWidth * m_vectorWidth;
    m_boardVector.reserve(size);

    for(int i = 0; i < size; i++)
    {
        int rowIndex = std::floor(i / (m_vectorWidth));
        int columnIndex = i - ((m_vectorWidth) * rowIndex);

        if(rowIndex == 0  || columnIndex == 0 || rowIndex == m_boardSize+1 || columnIndex == m_boardSize+1)
            m_boardVector.emplace_back(Intersection{Stone::Wall});
        else
            m_boardVector.emplace_back(Intersection{Stone::None});
    }
}

int BoardLogic::getBoardSize() const
{
    return m_boardSize;
}

Stone BoardLogic::getCurrentPlayer() const
{
    return m_currentPlayer;
}

std::vector<Intersection> BoardLogic::getBoardVector() const
{
    return m_boardVector;
}

void BoardLogic::printBoardState()
{
    int spaceCounter = 0;
    for(const auto& i : m_boardVector)
    {
        if (i.isWall())
            std::cout << "N" << " ";
        else if (i.isEmpty())
            std::cout << "E" << " ";
        else if (i.stone == Stone::Black)
            std::cout << "B" << " ";
        else
            std::cout << "W" << " ";

        spaceCounter = (spaceCounter + 1) % (m_boardSize+2);
        if (spaceCounter == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

int BoardLogic::getInternalIndex(int x, int y) const 
{
    int vectorWidth = m_boardSize + 2;              //+2 uwzglednia niewidzialny "wall" na krancach vektora, logiczna plansza ma wymiar 11*11
    return (vectorWidth * (y + 1)) + (x + 1);       //jako ze ignorujemy sciany, musimy przemiszczac sie 1-9 zamiast 0-8
}

bool BoardLogic::fieldEmptyAtIndex(int index) const
{
    if(m_boardVector[index].isEmpty())
        return true;
    else
        return false;
}

void BoardLogic::placeStone(int index)
{
    if(fieldEmptyAtIndex(index))
    {
        if(m_currentPlayer == Stone::Black)
        {
            m_boardVector[index].stone = Stone::Black;
            m_currentPlayer = Stone::White;
        }
        else
        {
            m_boardVector[index].stone = Stone::White;
            m_currentPlayer = Stone::Black;
        }
    }
}

std::pair<int, int> BoardLogic::coordinatesLogicalToGraphical(int index) const
{
    int y = std::floor(index / (m_vectorWidth));
    int x = index - ((m_vectorWidth) * y);

    return {x-1, y-1};
}


