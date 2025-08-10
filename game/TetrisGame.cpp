#include "TetrisGame.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

TetrisGame::TetrisGame()
    : game_over_(false),
      level_(1),
      score_(0),
      board_(8, 12),
      current_piece_(PieceType::I),
      next_piece_(PieceType::S)
{
    // Initialize random seed first
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(nullptr));
        seeded = true;
    }
    
    // Now create random pieces
    current_piece_ = Piece(GetRandomPieceType());
    next_piece_ = Piece(GetRandomPieceType());
    
    // Position the first piece
    int startX = board_.GetWidth() / 2 - 1;
    int startY = 0;
    current_piece_.SetPosition(startX, startY);
}

TetrisGame::~TetrisGame(){
    // std::cout << "TetrisGame: Destructor" << std::endl;
}

bool TetrisGame::IsGameOver(){
    return game_over_;
}

void TetrisGame::Update(){
    Piece movedPiece = current_piece_;
    movedPiece.Move(0, 1);

    if (IsValidPosition(movedPiece)) {
        // If valid, update the current piece's position
        current_piece_ = movedPiece;
    } else {
        // If not valid, lock the piece into the board
        board_.PlacePiece(current_piece_);

        // 2. Clear completed lines
        board_.ClearLines();

        // 3. Spawn a new piece
        SpawnNewPiece();

        // 4. Check for game over (if new piece collides immediately)
        if (!IsValidPosition(current_piece_)) {
            game_over_ = true;
        }
    }
    // Move current piece down
    // Check if piece has hit the bottom
    // If it has, add it to the board
    // If it has not, continue moving down
    // Check if any lines are complete
    // If they are, remove them
    // If they are not, continue
    // Spawn a new piece
}

bool TetrisGame::IsValidPosition(const Piece& piece) const {
        
    const auto& shape = piece.GetShape();
    int pieceX = piece.GetX();
    int pieceY = piece.GetY();
    for(int row = 0; row < static_cast<int>(shape.size()); ++row){
        for(int col = 0; col < static_cast<int>(shape[row].size()); ++col){

            if (shape[row][col] != 0){ // There is a block here
                int boardX = pieceX + col;
                int boardY = pieceY + row;

                // check bounds
                if(boardX < 0 || boardX >= board_.GetWidth() ||
                   boardY < 0 || boardY >= board_.GetHeight()){

                    return false;
                }

                // Check collision with board
                if(board_.GetCell(boardX, boardY) != 0){
                    return false;
                }
            }
        }
    }

    return true; // No collisions, inside bounds

}

const Board& TetrisGame::getBoard() const {
    return board_;
}

void TetrisGame::SpawnNewPiece(){
    // Move next piece to current
    current_piece_ = next_piece_;

    // Generate new next piece
    next_piece_ = Piece(GetRandomPieceType());

    int startX = board_.GetWidth() / 2 - 1;
    int startY = 0;
    current_piece_.SetPosition(startX, startY);

    // std::cout << "Spawned new piece " << static_cast<int>(next_piece_.GetType()) <<  " at (" << startX << ", " << startY << ")" << std::endl;
}

PieceType TetrisGame::GetRandomPieceType(){
    int random = std::rand() % 7;  // 7 different piece types
    // std::cout << "Random piece type: " << random << std::endl;
    return static_cast<PieceType>(random);
}

// Add getter for current piece
const Piece& TetrisGame::GetCurrentPiece() const {
    return current_piece_;
}

const Piece& TetrisGame::GetNextPiece() const {
    return next_piece_;
}

void TetrisGame::HandleInput(GameInput input){

    Piece movedPiece = current_piece_;

    switch (input)
    {
    case GameInput::MoveLeft:
        movedPiece.Move(-1,0);
        if(IsValidPosition(movedPiece)){
            current_piece_ = movedPiece;
        }
        break;
    
        case GameInput::MoveRight:
        movedPiece.Move(1, 0);
        if (IsValidPosition(movedPiece)) {
            current_piece_ = movedPiece;
        }
        break;

    // case GameInput::Rotate: // Usually rotate clockwise
    //     movedPiece.RotateClockwise();
    //     if (IsValidPosition(movedPiece)) {
    //         current_piece_ = movedPiece;
    //     }
    //     break;

    case GameInput::SoftDrop: // Soft drop
        movedPiece.Move(0, 1);
        if (IsValidPosition(movedPiece)) {
            current_piece_ = movedPiece;
        }
        break;

    // case ' ': // Space for hard drop
    //     while (IsValidPosition(movedPiece)) {
    //         current_piece_ = movedPiece;
    //         movedPiece.Move(0, 1);
    //     }
    //     // Piece can't move further down, so lock it immediately
    //     board_.PlacePiece(current_piece_);
    //     board_.ClearLines();
    //     SpawnNewPiece();
    //     break;
    }
}

