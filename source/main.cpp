#include <iostream>

#include "game.hpp"

/**
 * @brief main function of program where the game object is initialised and started
 */
int main(int argc, char const * argv[]) {

  Game game = Game(320, 180, 4);
  
  game.start();
 
  return EXIT_SUCCESS;
}