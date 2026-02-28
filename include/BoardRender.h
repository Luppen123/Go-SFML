#ifndef BOARD_RENDER_H
#define BOARD_RENDER_H

#include <vector>
#include "Stone.h"

class BoardRender
{
private:
    sf::RenderWindow& window;
    float cellSize;
    float margin;

    void drawLines(int boardSize);
    void drawHoshi(int boardSize);
public:
    BoardRender(sf::RenderWindow& w, float cs, float m) :
        window(w), cellSize(cs), margin(m) {}

    void drawBoard(int boardSize);
    void drawStone();
};


#endif