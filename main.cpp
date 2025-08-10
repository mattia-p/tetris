#include <iostream>
#include <ncurses.h>

#include <unistd.h> // For sleep
#include "game/TetrisGame.hpp"
#include "display/NcursesDisplay.hpp"

#include <vector>
#include <chrono>
#include <thread>


int main(){

    TetrisGame game;

    NcursesDisplay display;

    auto lastFall = std::chrono::steady_clock::now();

    while(!game.IsGameOver()){

        // Handle input
        TetrisGame::GameInput input = display.GetInput();

        if (input != TetrisGame::GameInput::None){
            game.HandleInput(input);
        }

        auto now = std::chrono::steady_clock::now();
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now - lastFall).count() >= 500){
            game.Update();
            lastFall = now;
        }
            
        
        display.Draw(game);

        // Small delay so CPU doesn't spike
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60fps
    }

    return 0;
}


