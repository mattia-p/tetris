#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>

using Shape = std::vector<std::vector<int>>;

enum class PieceType{
    I,
    O,
    T,
    S,
    Z,
    J,
    L,
};

class Piece{

public:
    // Piece();
    Piece(PieceType type);
    ~Piece();

    // Getters
    int GetX() const {return x_;}
    int GetY() const {return y_;}
    PieceType GetType() const {return type_;}
    const Shape& GetShape() const { return current_shape_;}

    // Movement
    void SetPosition(int x, int y);
    void Move(int dx, int dy);
    void Rotate();

private:
    int x_;
    int y_;
    int rotation_;
    PieceType type_;
    Shape current_shape_;

    void InitializeShape();

};

struct PieceData{
    std::vector<Shape> rotations; // One shape for each rotation
    char symbol; // Symbol to use
};

#endif // PIECE_HPP