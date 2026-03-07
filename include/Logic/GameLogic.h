#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "Logic/Board.h"
#include <set>
#include <queue>

struct Group
{
    //Stone color;
    int libertyCount;
    std::vector<Coordinate> stoneCoordinates;
};

class GameLogic
{
private:
    Board& m_board;
    Stone m_currentPlayer;
    std::vector<Group> m_groups; //usunac perhaps

public:
    GameLogic(Board& board);

    Stone getCurrentPlayer() const;
    const Board& getBoard() const;

    void placeStone(int index);
    void changePlayer();

    Group floodFill(Coordinate coordinates, Stone currentPlayer);

};

#endif