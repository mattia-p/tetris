#include "NcursesDisplay.hpp"

#include <iostream>
#include "TetrisGame.hpp"

NcursesDisplay::NcursesDisplay(){
    // std::cout << "NcursesDisplay: Constructor" << std::endl;
    initscr();            // Initialize ncurses
    cbreak();             // Disable line buffering
    noecho();             // Don't echo keypresses
    keypad(stdscr, TRUE); // Enable function keys and arrows
    nodelay(stdscr, TRUE); // Make getch blocking, or set TRUE for non-blocking
    curs_set(0);          // Hide the cursor 
    // box(stdscr, 0, 0);  // 0 uses default ACS characters
}

NcursesDisplay::~NcursesDisplay(){
    endwin();
    // std::cout << "NcursesDisplay: Destructor" << std::endl;
}

void NcursesDisplay::DrawBorder(int width, int height) {
    // Draw top border
    mvprintw(0, 0, "+");
    for (int x = 1; x <= width * 2; ++x) {
        mvprintw(0, x, "-");
    }
    mvprintw(0, width * 2 + 1, "+");
    
    // Draw side borders
    for (int y = 1; y < height * 2 + 1; ++y) {
        mvprintw(y, 0, "|");                        // Left wall
        mvprintw(y, width * 2 + 1, "|");            // Right wall
    }
    
    // Draw bottom border
    mvprintw(height * 2 + 1, 0, "+");
    for (int x = 1; x <= width * 2; ++x) {
        mvprintw(height * 2 + 1, x, "-");
    }
    mvprintw(height * 2 + 1, width * 2 + 1, "+");
}


TetrisGame::GameInput NcursesDisplay::GetInput(){
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:  return TetrisGame::GameInput::MoveLeft;
        case KEY_RIGHT: return TetrisGame::GameInput::MoveRight;
        case KEY_UP:    return TetrisGame::GameInput::Rotate;
        case KEY_DOWN:  return TetrisGame::GameInput::SoftDrop;
        case ' ':       return TetrisGame::GameInput::HardDrop;
        case 'q':       return TetrisGame::GameInput::Quit;
        default:        return TetrisGame::GameInput::None;
    }
}

void NcursesDisplay::Draw(const TetrisGame& game) {
    const Board& board = game.getBoard();
    const Piece& piece = game.GetCurrentPiece();

    // Clear the screen
    clear();
    
    // Draw the border first
    DrawBorder(board.GetWidth(), board.GetHeight());

    // 1. Draw the board (locked pieces) - offset by 1 to account for border
    for (int y = 0; y < board.GetHeight(); ++y) {
        for (int x = 0; x < board.GetWidth(); ++x) {
            if (board.GetCell(x, y) != 0) {
                // Draw locked piece
                mvprintw(y*2 + 1, x*2 + 1, "# ");
            } else {
                // Draw empty cell
                mvprintw(y*2 + 1, x*2 + 1, ". ");
            }
        }
    }

    // 2. Draw the current piece (on top of the board) - offset by 1 to account for border
    const Shape& shape = piece.GetShape();
    int px = piece.GetX();
    int py = piece.GetY();
    for (int i = 0; i < shape.size(); ++i) {
        for (int j = 0; j < shape[i].size(); ++j) {
            if (shape[i][j]) {
                int drawY = py + i;
                int drawX = px + j;
                if (drawY >= 0 && drawY < board.GetHeight() && drawX >= 0 && drawX < board.GetWidth()) {
                    // Draw current piece cell at (drawY, drawX)
                    mvprintw(drawY * 2 + 1, drawX * 2 + 1, "* ");
                }
            }
        }
    }

    // Refresh the display
    refresh();
}