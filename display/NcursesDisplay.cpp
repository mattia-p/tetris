#include "NcursesDisplay.hpp"

#include <iostream>

NcursesDisplay::NcursesDisplay(){
    // std::cout << "NcursesDisplay: Constructor" << std::endl;
    initscr();            // Initialize ncurses
    cbreak();             // Disable line buffering
    noecho();             // Don't echo keypresses
    keypad(stdscr, TRUE); // Enable function keys and arrows
    nodelay(stdscr, FALSE); // Make getch blocking, or set TRUE for non-blocking
    curs_set(0);          // Hide the cursor 
}

NcursesDisplay::~NcursesDisplay(){
    endwin();
    // std::cout << "NcursesDisplay: Destructor" << std::endl;
}

int NcursesDisplay::GetInput(){
    return getch();

    // int ch;
    // while ((ch = getch()) != 'q') { // Press 'q' to quit
    //     clear();  // Clear the screen
    //     mvprintw(0, 0, "Key code: %d", ch);   // Print the key code at top-left
    //     mvprintw(1, 0, "Character: %c", ch);  // Print character (if printable)
    //     refresh(); // Update the screen with new content
    // }
    // return 0;
}

void NcursesDisplay::Draw(const TetrisGame& game) {
    const Board& board = game.getBoard();
    const Piece& piece = game.GetCurrentPiece();

    // 1. Draw the board (locked pieces)
    for (int y = 0; y < board.GetHeight(); ++y) {
        for (int x = 0; x < board.GetWidth(); ++x) {
            if (board.GetCell(x, y) != 0) {
                // Draw locked piece
                mvprintw(y*2, x*2, "# ");
            } else {
                // Draw empty cell
                mvprintw(y*2, x*2, "o ");
            }
        }
    }

    // 2. Draw the current piece (on top of the board)
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
                    mvprintw(drawY * 2, drawX * 2, "* ");
                }
            }
        }
    }

    // Refresh the display
    refresh();
}