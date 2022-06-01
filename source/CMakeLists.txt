# setting minumum version for cmake
cmake_minimum_required(VERSION 3.23.1)

#setting project name
project(GAME_OF_LIFE)

# setting C/C++ version
set (CMAKE_CXX_STANDARD 14)

# setting executable name
add_executable(${PROJECT_NAME} main.cpp)

# adding subdirectories
add_subdirectory(cell)
add_subdirectory(point)
add_subdirectory(board)
add_subdirectory(screen)