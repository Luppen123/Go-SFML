#include "BoardPainter.h"

BoardPainter::BoardPainter(sf::RenderWindow window, const Board& board) :
    m_window(window), m_board(board) {}