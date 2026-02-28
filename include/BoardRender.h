#ifndef BOARD_RENDER_H
#define BOARD_RENDER_H

#include <vector>

enum class Stone
{
    None,
    Black, 
    White
};

struct Intersection 
{
    unsigned x;
    unsigned y;
    unsigned liberties;
    Stone stone = Stone::None;
};

struct Group
{
    Stone color;
    std::vector<int> StonesInGroup;
    unsigned liberties;
};


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
};


#endif