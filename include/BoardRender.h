#ifndef BOARD_RENDER_H
#define BOARD_RENDER_H

#include <vector>
#include "Stone.h"
#include "BoardLogic.h"

class BoardRender
{
private:
    const BoardLogic& m_logic;
    sf::RenderWindow& m_window;
    float m_cellSize;
    float m_margin;

    void drawLines();
    void drawHoshi();
    int pixelToIndex(int pixel);

public:
    BoardRender(sf::RenderWindow& w, float cs, float m, const BoardLogic& l) :
        m_window(w), m_cellSize(cs), m_margin(m), m_logic(l) {}
    //TO DO: Wywalic definicje konsturktora z hedeara

    void drawBoard();
    void drawStone(std::pair<int, int> coordinates, Stone player);
    void drawStoneHiglight(Stone player);

    int GetCoordinatesLogical(int pixelX, int pixelY);
    std::pair<int, int> GetCoordinatesGraphical(int pixelX, int pixelY);
};


#endif