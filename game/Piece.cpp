#include "Piece.hpp"

// Piece::Piece(){
// }

Piece::Piece(PieceType type): x_(0), y_(0), rotation_(0), type_(type){
    InitializeShape();
}

Piece::~Piece(){}

void Piece::SetPosition(int x, int y){
    x_ = x;
    y_ = y;
}

void Piece::Move(int dx, int dy){
    x_ += dx;
    y_ += dy;
}

void Piece::Rotate(){
    rotation_ = (rotation_ + 1) % 4;
    // TODO: Implement shape rotation logic
}

void Piece::InitializeShape(){
    switch (type_)
    {
    case PieceType::I:
        current_shape_ = {
            {1, 1, 1, 1}
        };
        break;
    case PieceType::O:
        current_shape_ = {
            {1, 1},
            {1, 1}
        };
        break;
    case PieceType::T:
        current_shape_ = {
            {0, 1, 0},
            {1, 1, 1}
        };
        break;
    case PieceType::S:
        current_shape_ = {
            {0, 1, 1},
            {1, 1, 0}
        };
        break;
    case PieceType::Z:
        current_shape_ = {
            {1, 1, 0},
            {0, 1, 1}
        };
        break;
    case PieceType::J:
        current_shape_ = {
            {1, 0, 0},
            {1, 1, 1}
        };
        break;
    case PieceType::L:
        current_shape_ = {
            {0, 0, 1},
            {1, 1, 1}
        };
        break;
    }
}