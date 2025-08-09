#include "Board.hpp"
#include <iostream>

Board::Board(int width, int height)
    :width_(width), height_(height), grid_(height, std::vector<int>(width, 0)){
}

Board::~Board(){}

int Board::GetWidth() const {
    return width_;
}

int Board::GetHeight() const {
    return height_;
}

int Board::GetCell(int x, int y) const {
    return grid_[y][x];
}

void Board::PrintGrid() const{
    for (int y = 0; y < height_; y++){
        for(int x = 0; x < width_; x++){
            std::cout << grid_[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::PlacePiece(const Piece& piece) {
    const auto& shape = piece.GetShape();
    int pieceX = piece.GetX();
    int pieceY = piece.GetY();

    for (int row = 0; row < static_cast<int>(shape.size()); ++row) {
        for (int col = 0; col < static_cast<int>(shape[row].size()); ++col) {
            if (shape[row][col] != 0) { // There's a block in the piece
                int boardX = pieceX + col;
                int boardY = pieceY + row;

                // Safety check — only place inside bounds
                if (boardX >= 0 && boardX < width_ &&
                    boardY >= 0 && boardY < height_) {
                    grid_[boardY][boardX] = shape[row][col];
                }
            }
        }
    }
}

void Board::ClearLines(){
    int linesCleared = 0;

    for (int y = height_ - 1; y >= 0; --y){
        bool fullLine = true;
        for(int x = 0; x < width_; ++x){
            if(grid_[y][x] == 0){ // emtpy cell - not ful
                fullLine = false;
                break;
            }
        }

        if (fullLine){
            // Remove this row
            grid_.erase(grid_.begin() + y);

            // Insert new empty row at the top
            grid_.insert(grid_.begin(), std::vector<int>(width_, 0));

            ++linesCleared;

            // Check same y again since we shifted rows down
            ++y;
        }
    }

    if(linesCleared >= 0){
        // std::cout << "Cleared " << linesCleared << " lines!" << std::endl;
    }
}