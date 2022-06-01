#pragma once

#include <iostream>
#include <SDL.h>

class Screen {
private:
  SDL_Window * window;
  SDL_Renderer * renderer;
  int scale;
public:
  Screen(int width, int height, int scale);
  ~Screen();

  void render(int x, int y);
  void setDrawColor(int r, int g, int b, int a);

  void clear();
  void display();
};
