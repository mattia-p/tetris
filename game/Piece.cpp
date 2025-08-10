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
    current_shape_ = GetShapeForRotation(type_, rotation_);
}

void Piece::InitializeShape(){
    current_shape_ = GetShapeForRotation(type_, rotation_);
}

Shape Piece::GetShapeForRotation(PieceType type, int rotation) {
    switch (type) {
        case PieceType::I:
            switch (rotation) {
                case 0: return {{1, 1, 1, 1}};
                case 1: return {{1}, {1}, {1}, {1}};
                case 2: return {{1, 1, 1, 1}};
                case 3: return {{1}, {1}, {1}, {1}};
            }
            break;
            
        case PieceType::O:
            // O piece doesn't rotate
            return {{1, 1}, {1, 1}};
            
        case PieceType::T:
            switch (rotation) {
                case 0: return {{0, 1, 0}, {1, 1, 1}};
                case 1: return {{1, 0}, {1, 1}, {1, 0}};
                case 2: return {{1, 1, 1}, {0, 1, 0}};
                case 3: return {{0, 1}, {1, 1}, {0, 1}};
            }
            break;
            
        case PieceType::S:
            switch (rotation) {
                case 0: return {{0, 1, 1}, {1, 1, 0}};
                case 1: return {{1, 0}, {1, 1}, {0, 1}};
                case 2: return {{0, 1, 1}, {1, 1, 0}};
                case 3: return {{1, 0}, {1, 1}, {0, 1}};
            }
            break;
            
        case PieceType::Z:
            switch (rotation) {
                case 0: return {{1, 1, 0}, {0, 1, 1}};
                case 1: return {{0, 1}, {1, 1}, {1, 0}};
                case 2: return {{1, 1, 0}, {0, 1, 1}};
                case 3: return {{0, 1}, {1, 1}, {1, 0}};
            }
            break;
            
        case PieceType::J:
            switch (rotation) {
                case 0: return {{1, 0, 0}, {1, 1, 1}};
                case 1: return {{1, 1}, {1, 0}, {1, 0}};
                case 2: return {{1, 1, 1}, {0, 0, 1}};
                case 3: return {{0, 1}, {0, 1}, {1, 1}};
            }
            break;
            
        case PieceType::L:
            switch (rotation) {
                case 0: return {{0, 0, 1}, {1, 1, 1}};
                case 1: return {{1, 0}, {1, 0}, {1, 1}};
                case 2: return {{1, 1, 1}, {1, 0, 0}};
                case 3: return {{1, 1}, {0, 1}, {0, 1}};
            }
            break;
    }
    
    // Fallback - should never reach here
    return {{1}};
}