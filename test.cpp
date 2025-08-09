#include <iostream>
#include <ncurses.h>

#include <unistd.h> // For sleep

// DIMENSIONS

void setup(){
    // Draw contours

    for(int y = 1; y < 10; y++){
        mvprintw(y, 1, "#");
        mvprintw(y, 10, "#");
    }

    for(int x = 1; x < 11; x++){
        mvprintw(10, x, "#");
    }
}

int main(){

    // Initializes screen
    initscr();

    // Prevents typed characters from appearing on the screen
    noecho();

    // Disables line buffering — input is available immediately
    cbreak();

    // Hides (0), normal (1), or very visible (2) cursor
    curs_set(0);

    // Draw a box around the entire screen
    box(stdscr, 0, 0);  // 0 uses default ACS characters

    // Draw contours
    setup();

    bool gameover = false;
    int x_pos = 4;
    int y_pos = 1;
    mvprintw(y_pos, x_pos, "o");

    while(!gameover){
        y_pos++;
        mvprintw(y_pos, x_pos, "o");

        usleep(1000000);

        refresh();

        if(y_pos > 10){
            gameover = true;
        }
    }

    // Moves the cursor and prints text at (y, x).
    // mvprintw(1, 2, "This is inside the box.");
    // refresh();

    mvprintw(5, 5, "Game Over");

    getch();
    endwin();
    return 0;

    // TetrisGame game;
    // NcursesDisplay display;
    // while(running){
        // game.handleInput()
        // game.update()
        // display.draw(game)
    // }
}


