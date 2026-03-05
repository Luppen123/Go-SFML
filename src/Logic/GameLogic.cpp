#include "GameLogic.h"

GameLogic::GameLogic(Board board) : m_board(board)
{
    m_currentPlayer = Stone::Black;
    m_groupVector.reserve(100);
}

Stone GameLogic::getCurrentPlayer() const
{
    return m_currentPlayer;
}

void GameLogic::placeStone(int index)
{
    if(m_board.isEmptyAt(index))
    {
        m_board.setStone(index, m_currentPlayer);
        this->changePlayer();
    }
}

void GameLogic::changePlayer()
{
    m_currentPlayer = (m_currentPlayer == Stone::Black) ? Stone::White : Stone::Black;
}

