cmake_minimum_required(VERSION 3.10)
project(CANary)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find ncurses
find_package(Curses REQUIRED)

# Create library target for the game source files
add_library(game_library
    game/Board.cpp
    game/Piece.cpp
    game/TetrisGame.cpp
    display/NcursesDisplay.cpp
)

# Specify include directories for the library target
target_include_directories(game_library PUBLIC
    ${PROJECT_SOURCE_DIR}/game
    ${PROJECT_SOURCE_DIR}/display
    ${CURSES_INCLUDE_DIR} 
)

# Link ncurses to the game_library
target_link_libraries(game_library
    PRIVATE
    ${CURSES_LIBRARIES} 
)

# Include ncurses headers
# include_directories(${CURSES_INCLUDE_DIR})

# Build the main executable
add_executable(tetris main.cpp)

# Link game_library to executable
target_link_libraries(tetris PRIVATE
    game_library
)

