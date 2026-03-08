#include <SFML/Graphics.hpp>
#include <iostream>

#include <Controllers/GameController.h>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Wczytac z menu
    int boardSize = 19;
    float cellSize = 40.f;
    float margin = 25.f;

    sf::RenderWindow window(sf::VideoMode((boardSize - 1) * cellSize + 2 * margin,(boardSize - 1) * cellSize + 2 * margin), "Go Prot", sf::Style::Close, settings);

    // window.setSize(sf::Vector2u(370,370));
    // while(window.isOpen())
    // {
    //     window.display();
    // }

    GameController gameController(cellSize, margin, boardSize, window);
    gameController.run();


    return 0;
}