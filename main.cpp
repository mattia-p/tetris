#include <iostream>
#include <ncurses.h>

#include <unistd.h> // For sleep
#include "game/TetrisGame.hpp"
#include "display/NcursesDisplay.hpp"

#include <vector>

int main(){

    TetrisGame game;

    game.Update();

    NcursesDisplay display;
    // display.Draw(game);
    // getch();


    while(!game.IsGameOver()){
    //     int input = display.GetInput();

        // game.handleInput()
            
        game.Update();

        display.Draw(game);
        usleep(500000);
    }

    return 0;
}


