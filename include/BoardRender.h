#ifndef BOARD_RENDER_H
#define BOARD_RENDER_H

#include <vector>
#include "Stone.h"
#include "BoardLogic.h"

class BoardRender
{
private:
    const BoardLogic& m_logic; //render
    sf::RenderWindow& m_window;//render
    float m_cellSize;   //geometry  
    float m_margin;     //gemoetry

    void drawLines();   //render
    void drawHoshi();   //render
    int pixelToIndex(int pixel);    //geometry

public:
    BoardRender(sf::RenderWindow& w, float cs, float m, const BoardLogic& l) :
        m_window(w), m_cellSize(cs), m_margin(m), m_logic(l) {}
    //TO DO: Wywalic definicje konsturktora z hedeara

    void drawBoard();           //render
    void drawStone(int index);  //render
    void drawStoneHiglight();   //render

    int getCoordinatesLogical(int pixelX, int pixelY);      //gemoetry
    std::pair<int, int> getCoordinatesGraphical(int pixelX, int pixelY); //gemoetry
    std::pair<int, int> getMouseCords(); //gemoetry
    
};


#endif