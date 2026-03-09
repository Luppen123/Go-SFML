#include "Logic/GameLogic.h"

GameLogic::GameLogic(Board& board) : m_board(board)
{
    m_currentPlayer = Stone::Black;
    m_score = {6.5, 0};
}

void GameLogic::incrementScore(Stone color)
{
    color == Stone::Black ? m_score.Black++ : m_score.White++;
}

Score GameLogic::getScore() const
{
    std::cout << "Current Score:" << '\n';
    std::cout << "White: " << m_score.White << '\n' << "Black: " << m_score.Black << '\n';
    return m_score;
}

Stone GameLogic::getCurrentPlayer() const
{
    return m_currentPlayer;
}

const Board& GameLogic::getBoard() const
{
    return m_board;
}

void GameLogic::checkNeighbours(const Coordinate& stoneCoordinates, std::vector<bool>& visited)
{
    for(const auto& direction : DIRECTIONS)
    {
        Coordinate neighbourCoordinates = {stoneCoordinates.x + direction.x, stoneCoordinates.y + direction.y};
        if(!m_board.isLegal(neighbourCoordinates))
            continue;

        Stone stone = m_board.getStone(neighbourCoordinates);
        int index = m_board.convertCoordinatesToIndex(neighbourCoordinates);

        if(stone != m_currentPlayer && stone != Stone::None && !visited[index])
        {
            Group enemyGroup = m_board.floodFill(neighbourCoordinates, stone);

            for(const auto& stone : enemyGroup.stoneCoordinates)
            {
                visited[m_board.convertCoordinatesToIndex(stone)] = true;
            }

            if(enemyGroup.libertyCount == 0)
                this->captureGroup(enemyGroup.stoneCoordinates);
        }
    }
}

bool GameLogic::isSuicide(const Coordinate& stoneCoordinates)
{
    Group selfGroup = m_board.floodFill(stoneCoordinates, m_currentPlayer);
    return selfGroup.libertyCount == 0;
}

bool GameLogic::isKoViolation()
{
    return m_board.getPreviousBoardState() == m_board.getBoardState();
}

void GameLogic::placeStone(int index)
{
    if(!m_board.isEmptyAt(index))
        return;

    int boardSize = m_board.getBoardSize();
    std::vector<bool> visited(boardSize*boardSize, false);

    Coordinate stoneCoordinates = m_board.convertIndexToCoordinates(index);
    std::vector<Intersection> boardStateBeforePlacement = m_board.getBoardState();
    m_board.setStone(index, m_currentPlayer);

    this->checkNeighbours(stoneCoordinates, visited);

    if(this->isSuicide(stoneCoordinates))
    {
        m_board.setStone(stoneCoordinates, Stone::None);
        return;
    }

    if(this->isKoViolation())
    {
        m_board.setBoardState(boardStateBeforePlacement);
        return;
    }

    this->changePlayer();
    m_board.setPreviousBoardState(boardStateBeforePlacement);
}

void GameLogic::captureGroup(std::vector<Coordinate>& group)
{
    for(auto& stone : group)
    {
        m_board.setStone(stone, Stone::None);
        this->incrementScore(m_currentPlayer);
    }
}

void GameLogic::changePlayer()
{
    m_currentPlayer = (m_currentPlayer == Stone::Black) ? Stone::White : Stone::Black;
}

