#include "Logic/GameLogic.h"

GameLogic::GameLogic(Board& board) : m_board(board)
{
    m_currentPlayer = Stone::Black;
    m_groups.reserve(100);
}

Stone GameLogic::getCurrentPlayer() const
{
    return m_currentPlayer;
}

const Board& GameLogic::getBoard() const
{
    return m_board;
}

void GameLogic::placeStone(int index)
{
    if(!m_board.isEmptyAt(index))
        return;

    int boardSize = m_board.getBoardSize();
    std::vector<bool> visited(boardSize*boardSize, false);

    m_board.setStone(index, m_currentPlayer);
    Coordinate stoneCoordinates = m_board.convertIndexToCoordinates(index);


    for(const auto& direction : DIRECTIONS)
    {
        Coordinate neighbourCoordinates = {stoneCoordinates.x + direction.x, stoneCoordinates.y + direction.y};
        if(!m_board.isLegal(neighbourCoordinates))
            continue;

        Stone stone = m_board.getStone(neighbourCoordinates);
        int index = m_board.convertCoordinatesToIndex(neighbourCoordinates);

        if(stone != m_currentPlayer && stone != Stone::None && !visited[index])
        {
            Group enemyGroup = floodFill(neighbourCoordinates, stone);

            for(const auto& stone : enemyGroup.stoneCoordinates)
            {
                visited[m_board.convertCoordinatesToIndex(stone)] = true;
            }

            if(enemyGroup.libertyCount == 0)
                m_board.deleteGroup(enemyGroup.stoneCoordinates);
        }
    }

    Group selfGroup = floodFill(stoneCoordinates, m_currentPlayer);
    if(selfGroup.libertyCount == 0)
    {
        m_board.setStone(stoneCoordinates, Stone::None);
        return;
    }

    m_board.setStone(index, m_currentPlayer);
    this->changePlayer();
}

void GameLogic::changePlayer()
{
    m_currentPlayer = (m_currentPlayer == Stone::Black) ? Stone::White : Stone::Black;
}

Group GameLogic::floodFill(Coordinate startCoordinates, Stone groupColor)
{
    int boardSize = m_board.getBoardSize();

    std::vector<bool> visited(boardSize*boardSize, false);
    std::vector<Coordinate> stones;
    std::set<Coordinate> liberties;
    std::queue<Coordinate> queue;

    int startIndex = m_board.convertCoordinatesToIndex(startCoordinates);
    visited[startIndex] = true;
    queue.push(startCoordinates);
    stones.push_back(startCoordinates);

    while(!queue.empty())
    {
        Coordinate currentStoneCoordinates = queue.front();
        queue.pop();


        for(const auto& direction : DIRECTIONS)
        {
            Coordinate neighbourCoordinates = {currentStoneCoordinates.x + direction.x, currentStoneCoordinates.y + direction.y};
            std::cout << neighbourCoordinates.x << " " << neighbourCoordinates.y << std::endl;
            if(!m_board.isLegal(neighbourCoordinates))
                continue;

            Stone neighbourColor = m_board.getStone(neighbourCoordinates);
            int index = m_board.convertCoordinatesToIndex(neighbourCoordinates);

            if(neighbourColor == groupColor && !visited[index])
            {
                visited[index] = true;
                stones.push_back(neighbourCoordinates);
                queue.push(neighbourCoordinates);
            }
            else if(neighbourColor == Stone::None)
            {
                liberties.insert(neighbourCoordinates);
            }
        }
    }
    return {(int)liberties.size(), stones};
}