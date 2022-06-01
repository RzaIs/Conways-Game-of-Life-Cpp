#include <iostream>
#include "game.hpp"

int main(int argc, char const * argv[]) {
  Game game = Game(200, 100, 3);
  game.start();
 
  return EXIT_SUCCESS;
}