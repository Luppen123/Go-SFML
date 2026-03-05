#ifndef GAME_GEOMETRY_H
#define GAME_GEOMETRY_H

#include <cmath>
#include <algorithm>


struct Coordinate
{
    int x;
    int y;
};

class GameGeometry
{
private:
    float m_cellSize;
    float m_margin;

public:
    GameGeometry(float cellSize, float margin);

    //int coordinatesToIndex(Coordinate coordinates);
    Coordinate pixelsToCoordinates(int px, int py);

};

#endif


// class BoardRender
// {
// private:
//     const BoardLogic& m_logic; //render
//     sf::RenderWindow& m_window;//render
//     float m_cellSize;   //geometry  
//     float m_margin;     //gemoetry

//     void drawLines();   //render
//     void drawHoshi();   //render
//     int pixelToIndex(int pixel);    //geometry

// public:
//     BoardRender(sf::RenderWindow& w, float cs, float m, const BoardLogic& l) :
//         m_window(w), m_cellSize(cs), m_margin(m), m_logic(l) {}
//     //TO DO: Wywalic definicje konsturktora z hedeara

//     void drawBoard();           //render
//     void drawStone(int index);  //render
//     void drawStoneHiglight();   //render

//     int getCoordinatesLogical(int pixelX, int pixelY);      //gemoetry
//     std::pair<int, int> getCoordinatesGraphical(int pixelX, int pixelY); //gemoetry
//     std::pair<int, int> getMouseCords(); //gemoetry
// };