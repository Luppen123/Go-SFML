#include <SFML/Graphics.hpp>
#include <iostream>

#include "BoardRender.h"
#include "BoardLogic.h"

int main()
{

    //DODAC JAKO CZESC WIDOKU
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(370,370), "Go Prot", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    sf::RectangleShape boardShape(sf::Vector2f(370.f, 370.f));
    boardShape.setFillColor(sf::Color(245, 170, 59, 255));

    //origin set to the middle of the board itself
    boardShape.setOrigin(boardShape.getSize() / 2.f);
    boardShape.setPosition(sf::Vector2f(window.getSize()) / 2.f);
    //DODAC JAKO CZESC WIDKOU


    //Zrobic z tego stale albo wczytac jako input
    int boardSize = 9;
    float cellSize = 40.f;
    float margin = 25.f;
    //Zrobic z tego stale albo wczytac jako input
    

    BoardLogic bl(boardSize);
    bl.printBoardState();
    BoardRender br(window, cellSize, margin, bl);

    Stone player = Stone::Black;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                std::pair<int, int> mouseCords = br.getCoordinatesGraphical(mousePos.x, mousePos.y);

                int index = br.getCoordinatesLogical(mousePos.x, mousePos.y);
                bl.placeStone(index);
                bl.printBoardState();

            }
                
        }

        window.clear();
        br.drawBoard();
        br.drawStone(12);
        br.drawStoneHiglight();
        window.display();
    }

    return 0;
}