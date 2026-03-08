#include "Controllers/GameController.h"

// GameController::GameController(float cellSize, float margin, int boardSize, sf::ContextSettings windowSettings) :
//     m_window(sf::VideoMode((boardSize - 1) * cellSize + 2 * margin,(boardSize - 1) * cellSize + 2 * margin), "Go Prot", sf::Style::Close, windowSettings),
//     m_board(boardSize),
//     m_gameLogic(m_board),
//     m_gameGeometry(cellSize, margin, boardSize),
//     m_boardPainter(m_window, m_board, m_gameGeometry)
// {
//     m_window.setFramerateLimit(60);
// }

GameController::GameController(float cellSize, float margin, int boardSize, sf::RenderWindow& window) :
    m_window(window),
    m_board(boardSize),
    m_gameLogic(m_board),
    m_gameGeometry(cellSize, margin, boardSize),
    m_boardPainter(m_window, m_board, m_gameGeometry)
{
    m_window.setFramerateLimit(60);
}

void GameController::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        //Todo Switch case
        if (event.type == sf::Event::Closed)
            m_window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
            Coordinate coordinates = m_gameGeometry.pixelsToCoordinates(mousePosition.x, mousePosition.y);

            int index = m_board.convertCoordinatesToIndex(coordinates);
            m_gameLogic.placeStone(index);
            m_board.printBoardState(); //DEBUG
        }
    }
}

void GameController::render()
{
    m_window.clear();
    m_boardPainter.drawBoard();
    m_boardPainter.drawStoneHighlight(m_gameLogic.getCurrentPlayer());
    m_window.display();
}

void GameController::run()
{
    while(m_window.isOpen())
    {
        this->processEvents();
        this->render();
    }
}