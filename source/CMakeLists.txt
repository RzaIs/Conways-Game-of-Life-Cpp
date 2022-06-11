# setting minumum version for cmake
cmake_minimum_required(VERSION 3.0.0)

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
add_subdirectory(game)

#importing include directory
target_include_directories(${PROJECT_NAME}
  PRIVATE game
)

#linking included libraries
target_link_libraries(${PROJECT_NAME}
  game
)

enable_testing()

set(TEST tests)

add_executable(${TEST} test.cpp)

target_include_directories(${TEST}
  PRIVATE cell
  PRIVATE point
  PRIVATE board
)

target_link_libraries(${TEST}
  cunit
  cell
  point
  board
)

add_test(test ${TEST})