#include <SFML/Graphics.hpp>
#include <iostream>

#include "BoardRender.h"
#include "BoardLogic.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(370,370), "Go Prot", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    sf::RectangleShape boardShape(sf::Vector2f(370.f, 370.f));
    boardShape.setFillColor(sf::Color(245, 170, 59, 255));

    //origin set to the middle of the board itself
    boardShape.setOrigin(boardShape.getSize() / 2.f);
    boardShape.setPosition(sf::Vector2f(window.getSize()) / 2.f);

    while (window.isOpen())
    {
        BoardLogic bl(9);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                std::cout << bl.CalculateX(event.mouseButton.x, 25.f);
        }
        
        int boardSize = 9;
        float cellSize = 40.f;
        float margin = 25.f;
        
        window.clear();

        
        BoardRender br(window, cellSize, margin);
        br.drawBoard(boardSize);
        window.display();
    }

    return 0;
}