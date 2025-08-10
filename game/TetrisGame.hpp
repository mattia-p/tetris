#ifndef TETRISGAME_HPP
#define TETRISGAME_HPP

#include "Board.hpp"
#include "Piece.hpp"

class TetrisGame{

public:
    TetrisGame();
    ~TetrisGame();

    // void HandleInput();
    void Update();
    bool IsGameOver();
    // void Reset();
    const Board& getBoard() const; 

    const Piece& GetCurrentPiece() const;
    const Piece& GetNextPiece() const;

    enum class GameInput {
        MoveLeft,
        MoveRight,
        Rotate,
        SoftDrop,
        HardDrop,
        Quit,
        None
    };

    void HandleInput(GameInput input);

    

private:
    bool game_over_;
    int level_;
    int score_;
    Board board_;
    Piece current_piece_;
    Piece next_piece_;

    void SpawnNewPiece();
    PieceType GetRandomPieceType();
    bool IsValidPosition(const Piece& piece) const;
    // void checkCollision(const Piece& piece);
    // void lockPiece();
    // void clearLines();

};

#endif // TETRISGAME_HPP