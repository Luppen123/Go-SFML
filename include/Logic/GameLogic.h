#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "Logic/Board.h"
#include <set>

struct Group
{
    Stone color;
    std::vector<std::pair<int, int>> stonesCount;
    std::set<std::pair<int, int>> liberties;
};

class GameLogic
{
private:
    Board& m_board;
    Stone m_currentPlayer;
    std::vector<Group> m_groupVector;

public:
    GameLogic(Board& board);

    Stone getCurrentPlayer() const;
    const Board& getBoard() const;

    void placeStone(int index);
    void changePlayer();

};

#endif