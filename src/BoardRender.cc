#include <SFML/Graphics.hpp>
#include "BoardRender.h"
#include <cmath>
#include <algorithm>

void BoardRender::drawLines()
{
    sf::VertexArray lines(sf::Lines, 9*4);
    for(int i = 0; i < m_logic.getBoardSize(); ++i)
    {
        float lineY = m_margin + (i * m_cellSize);

        lines.append(sf::Vertex(sf::Vector2f(m_margin, lineY), sf::Color::Black)); 
        lines.append(sf::Vertex(sf::Vector2f(m_margin + (m_logic.getBoardSize() - 1) * m_cellSize, lineY), sf::Color::Black));

        lines.append(sf::Vertex(sf::Vector2f(lineY, m_margin), sf::Color::Black));
        lines.append(sf::Vertex(sf::Vector2f(lineY, m_margin + (m_logic.getBoardSize() - 1) * m_cellSize), sf::Color::Black));
    }
    
    m_window.draw(lines);
}

void BoardRender::drawHoshi()
{
    sf::CircleShape hoshi(3.f);
    hoshi.setFillColor(sf::Color::Black);
    hoshi.setOrigin(hoshi.getRadius(), hoshi.getRadius());

    std::vector<sf::Vector2i> hoshiPoints;
    if(m_logic.getBoardSize() == 9)
        hoshiPoints = {{2,2}, {6,2}, {2,6}, {6,6}};
    
    for (auto& p: hoshiPoints)
    {
        hoshi.setPosition(m_margin + p.x * m_cellSize, m_margin + p.y * m_cellSize);
        m_window.draw(hoshi);
    }
}

int BoardRender::pixelToIndex(int pixel) //GRAPHICAL
{
    int index = std::round((static_cast<float>(pixel) - m_margin) / m_cellSize);
    return std::clamp(index, 0, m_logic.getBoardSize() - 1);
}

// int pixelToIndexLogical(int pixel)
// {
//     int index = 
// }

void BoardRender::drawBoard()
{
    sf::RectangleShape board(sf::Vector2f(370.f, 370.f));
    board.setFillColor(sf::Color(245, 170, 59, 255));

    //origin set to the middle of the board itself
    board.setOrigin(board.getSize() / 2.f);
    board.setPosition(sf::Vector2f(m_window.getSize()) / 2.f);

    m_window.draw(board);

    this->drawLines();
    this->drawHoshi();
}

void BoardRender::drawStone(std::pair<int, int> coordinates, Stone player)
{

}

void BoardRender::drawStoneHiglight(Stone player)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    std::pair<int, int> mouseCords = GetCoordinatesGraphical(mousePos.x, mousePos.y);

    int vectorIndex = GetCoordinatesLogical(mousePos.x, mousePos.y);

    if(m_logic.fieldEmptyAtIndex(vectorIndex))
    {
        sf::CircleShape stone((m_cellSize / 2) - 2);
        stone.setOrigin(stone.getRadius(), stone.getRadius());

        if(player == Stone::White)
            stone.setFillColor(sf::Color(255, 255, 255, 128));
        else
            stone.setFillColor(sf::Color(0, 0, 0, 200));

        stone.setPosition(m_margin + mouseCords.first * m_cellSize, m_margin + mouseCords.second * m_cellSize);
        m_window.draw(stone);
    }

}

int BoardRender::GetCoordinatesLogical(int pixelX, int pixelY)
{                                                           
    int x = pixelToIndex(pixelX);                           
    int y = pixelToIndex(pixelY);

    return m_logic.getInternalIndex(x,y);
}

std::pair<int, int> BoardRender::GetCoordinatesGraphical(int pixelX, int pixelY)
{
    return {pixelToIndex(pixelX), pixelToIndex(pixelY)};
}
