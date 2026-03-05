#ifndef BOARD_PAINTER_H
#define BOARD_PAINTER_H

#include "GameGeometry.h"
#include "Logic/Board.h"
#include <SFML/Graphics.hpp>



class BoardPainter
{
private:
    sf::RenderWindow& m_window;
    const Board& m_board;

    void drawLines();
    void drawHoshi(); 

public:
    BoardPainter(sf::RenderWindow& window, const Board& board);

    

};

#endif