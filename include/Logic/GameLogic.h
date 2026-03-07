#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "Logic/Board.h"
#include <set>
#include <queue>

struct Group
{
    int libertyCount;
    std::vector<Coordinate> stoneCoordinates;
};

struct Score
{
    float White;
    float Black;
};

class GameLogic
{
private:
    Board& m_board;
    Stone m_currentPlayer;
    Score m_score;    

public:
    GameLogic(Board& board);

    void incrementScore(Stone color);
    Score getScore() const;

    Stone getCurrentPlayer() const;
    const Board& getBoard() const; //probably not needed

    void checkNeighbours(const Coordinate& stoneCoordinates, std::vector<bool>& visited);
    bool isSuicide(const Coordinate& stoneCoordinates );
    bool isKoViolation();

    Group floodFill(Coordinate coordinates, Stone currentPlayer) const;
    void placeStone(int index);
    void captureGroup(std::vector<Coordinate>& group);


    void changePlayer();

};

#endif