#ifndef NCURSESDISPLAY_HPP
#define NCURSESDISPLAY_HPP

#include <ncurses.h>
#include <iostream>
#include "TetrisGame.hpp"

class NcursesDisplay{

public:
    NcursesDisplay();
    ~NcursesDisplay();

    int GetInput();
    void Draw(const TetrisGame& game);

private:


};

#endif // NCURSESDISPLAY_HPP