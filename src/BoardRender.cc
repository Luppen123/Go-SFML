#include <SFML/Graphics.hpp>
#include "BoardRender.h"


void BoardRender::drawLines(int boardSize)
{
    sf::VertexArray lines(sf::Lines, 9*4);
    for(int i = 0; i < boardSize; ++i)
    {
        float lineY = margin + (i * cellSize);

        lines.append(sf::Vertex(sf::Vector2f(margin, lineY), sf::Color::Black)); 
        lines.append(sf::Vertex(sf::Vector2f(margin + (boardSize - 1) * cellSize, lineY), sf::Color::Black));

        lines.append(sf::Vertex(sf::Vector2f(lineY, margin), sf::Color::Black));
        lines.append(sf::Vertex(sf::Vector2f(lineY, margin + (boardSize - 1) * cellSize), sf::Color::Black));
    }
    
    window.draw(lines);
}

void BoardRender::drawHoshi(int boardSize)
{
    sf::CircleShape hoshi(3.f);
    hoshi.setFillColor(sf::Color::Black);
    hoshi.setOrigin(hoshi.getRadius(), hoshi.getRadius());

    std::vector<sf::Vector2i> hoshiPoints;
    if(boardSize == 9)
        hoshiPoints = {{2,2}, {6,2}, {2,6}, {6,6}};
    
    for (auto& p: hoshiPoints)
    {
        hoshi.setPosition(margin + p.x * cellSize, margin + p.y * cellSize);
        window.draw(hoshi);
    }
}

void BoardRender::drawBoard(int boardSize)
{
    sf::RectangleShape board(sf::Vector2f(370.f, 370.f));
    board.setFillColor(sf::Color(245, 170, 59, 255));

    //origin set to the middle of the board itself
    board.setOrigin(board.getSize() / 2.f);
    board.setPosition(sf::Vector2f(window.getSize()) / 2.f);

    window.draw(board);

    this->drawLines(boardSize);
    this->drawHoshi(boardSize);
}
