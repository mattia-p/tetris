#ifndef NCURSESDISPLAY_HPP
#define NCURSESDISPLAY_HPP

#include <ncurses.h>
#include <iostream>
#include "TetrisGame.hpp"

class NcursesDisplay{

public:
    NcursesDisplay();
    ~NcursesDisplay();

    TetrisGame::GameInput GetInput();
    void Draw(const TetrisGame& game);
    void DrawBorder(int width, int height);
    void DrawGameOver(const TetrisGame& game);

private:


};

#endif // NCURSESDISPLAY_HPP