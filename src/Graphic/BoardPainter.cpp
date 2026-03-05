#include "BoardPainter.h"

BoardPainter::BoardPainter(sf::RenderWindow& window, const Board& board, const GameGeometry& gameGeometry) :
    m_window(window),
    m_board(board),
    m_gameGeometry(gameGeometry)
{
    m_linesArray = sf::VertexArray(sf::Lines, m_gameGeometry.getBoardSize() * 4);
    m_hoshiShape = sf::CircleShape(3.f);                                    //change to dynamically calculated later!!
    m_stoneShape = sf::CircleShape((m_gameGeometry.getCellSize() / 2) - 2);

    int boardSize = m_gameGeometry.getBoardSize();
    float cellSize = m_gameGeometry.getCellSize();
    float margin = m_gameGeometry.getMargin();
    float boardPixelSize = (boardSize - 1) * cellSize + 2 * margin; 
    m_boardShape = sf::RectangleShape(sf::Vector2f(boardPixelSize, boardPixelSize));
}

void BoardPainter::drawLines()
{
    int boardSize = m_gameGeometry.getBoardSize();
    float cellSize = m_gameGeometry.getCellSize();
    float margin = m_gameGeometry.getMargin();

    for(int i = 0; i < boardSize; ++i)
    {
        float lineStartY = margin + (i * cellSize);

        m_linesArray.append(sf::Vertex(sf::Vector2f(margin, lineStartY), sf::Color::Black)); 
        m_linesArray.append(sf::Vertex(sf::Vector2f(margin + (boardSize - 1) * cellSize, lineStartY), sf::Color::Black));

        m_linesArray.append(sf::Vertex(sf::Vector2f(lineStartY, margin), sf::Color::Black));
        m_linesArray.append(sf::Vertex(sf::Vector2f(lineStartY, margin + (boardSize - 1) * cellSize), sf::Color::Black));
    }
    
    m_window.draw(m_linesArray);
}

void BoardPainter::drawHoshi()
{
    m_hoshiShape.setFillColor(sf::Color::Black);
    m_hoshiShape.setOrigin(m_hoshiShape.getRadius(), m_hoshiShape.getRadius());

    int boardSize = m_gameGeometry.getBoardSize();
    float cellSize = m_gameGeometry.getCellSize();
    float margin = m_gameGeometry.getMargin();

    std::vector<sf::Vector2i> hoshiPoints;
    switch(boardSize)
    {
        case 9:
            hoshiPoints = {{2,2}, {6,2},
                              {4, 4}, 
                           {2,6}, {6,6}};
            break;
        case 13:
            hoshiPoints = {{3,3}, {9,3}, 
                              {6, 6},
                           {3,9}, {9,9}};
            break;
        case 19:
            hoshiPoints = {{3, 3}, {9, 3}, {15, 3},
                           {3, 9}, {9, 9}, {15, 9},
                           {3,15}, {9,15}, {15,15}}; 
            break;
        default:
            throw "wtf, this shouldn't have happend";
    }

    for (auto& p: hoshiPoints)
    {
        m_hoshiShape.setPosition(margin + p.x * cellSize, margin + p.y * cellSize);
        m_window.draw(m_hoshiShape);
    }
}

// for(int index = 0; const auto& i : m_logic.getBoardVector())

// {

// if(!(i.isEmpty() || i.isWall()))

// drawStone(i.convertIndexToCoordinates(index));

// ++index;

// } 

void BoardPainter::drawStone(Coordinate )
{
    std::pair<int, int> cords = m_logic.coordinatesLogicalToGraphical(index);

    
}

// void BoardPainter::drawStone()
// {
//     std::pair<int, int> cords = m_logic.coordinatesLogicalToGraphical(index);
//     sf::CircleShape stone((m_cellSize / 2) - 2);
//     stone.setOrigin(stone.getRadius(), stone.getRadius());

//     if(m_logic.getBoardVector()[index].stone == Stone::White)
//         stone.setFillColor(sf::Color(255, 255, 255, 255));
//     else
//         stone.setFillColor(sf::Color(0, 0, 0, 255));

//     stone.setPosition(m_margin + cords.first * m_cellSize, m_margin + cords.second * m_cellSize);

//     m_window.draw(stone);
    
// }

// void BoardRender::drawStoneHiglight()
// {
//     sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
//     std::pair<int, int> mouseCords = getCoordinatesGraphical(mousePos.x, mousePos.y);

//     int vectorIndex = getCoordinatesLogical(mousePos.x, mousePos.y);

//     if(m_logic.fieldEmptyAtIndex(vectorIndex))
//     {
//         sf::CircleShape stone((m_cellSize / 2) - 2);
//         stone.setOrigin(stone.getRadius(), stone.getRadius());

//         if(m_logic.getCurrentPlayer() == Stone::White)
//             stone.setFillColor(sf::Color(255, 255, 255, 128));
//         else
//             stone.setFillColor(sf::Color(0, 0, 0, 200));

//         stone.setPosition(m_margin + mouseCords.first * m_cellSize, m_margin + mouseCords.second * m_cellSize);
//         m_window.draw(stone);
//     }

// }