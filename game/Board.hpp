#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Piece.hpp"

const int WIDTH = 10;
const int HEIGHT = 15;

class Board{

public:
    Board(int width, int height);
    ~Board();

    void PlacePiece(const Piece& piece);

    int GetWidth() const;
    int GetHeight() const;
    int GetCell(int x, int y) const;
    void ClearLines();

    void PrintGrid() const;

private:
    int width_;
    int height_;

    std::vector<std::vector<int>> grid_;

};

#endif // BOARD_HPP