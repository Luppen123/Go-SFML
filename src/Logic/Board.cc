#include "Logic/Board.h"

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

int Board::convertCoordinatesToIndex(Coordinate coordinates) const
{
    return (m_vectorWidth * (coordinates.y + 1)) + (coordinates.x + 1);         
}

Coordinate Board::convertIndexToCoordinates(int index) const
{
    int y = std::floor(index / (m_vectorWidth));
    int x = index - ((m_vectorWidth) * y);

    return {x-1, y-1};
}

std::vector<Intersection> Board::getBoardState() const
{
    return m_boardState;
}

bool Board::isEmptyAt(int index) const
{
    return m_boardState[index].isEmpty();
}

bool Board::isLegal(int index) const
{
    int size = m_boardSize * m_boardSize;
    return index < 0 || index > size-1;
}

bool Board::isLegal(Coordinate coordinates) const
{
    return coordinates.x >= 0 && coordinates.y >= 0 && coordinates.x < m_boardSize  && coordinates.y < m_boardSize ;
}


void Board::setStone(int index, Stone color)
{
    m_boardState[index].stone = color;
}

void Board::setStone(Coordinate coordinates, Stone color)
{
    int index = this->convertCoordinatesToIndex(coordinates);
    m_boardState[index].stone = color;
}

Stone Board::getStone(int index) const
{
    return m_boardState[index].stone;
}

Stone Board::getStone(Coordinate coordinates) const
{
    int index = this->convertCoordinatesToIndex(coordinates);
    return m_boardState[index].stone;
}

void Board::deleteGroup(std::vector<Coordinate>& stones)
{
    for(auto& stone : stones)
    {
        this->setStone(stone, Stone::None);
    }
}

void Board::printBoardState() const
{
    int spaceCounter = 0;
    for(const auto& i : m_boardState)
    {
        if (i.isWall())
            std::cout << "*" << " ";
        else if (i.isEmpty())
            std::cout << "-" << " ";
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
