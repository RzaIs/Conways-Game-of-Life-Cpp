#include "screen.hpp"

Screen::Screen(int width, int height, int scale) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    std::cout << "SDL init failed. Error: " << SDL_GetError() << std::endl;

  this->window = SDL_CreateWindow(
    "Game of Life",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width * scale, height * scale,
    SDL_WINDOW_SHOWN
  );
  
  if (this->window == NULL)
    std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  
  if (this->renderer == NULL)
    std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
  
  this->scale = scale;
}

Screen::~Screen() {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
}

void Screen::render(int x, int y) {
  SDL_Rect rect = {
    .x = x * this->scale,
    .y = y * this->scale,
    .w = this->scale,
    .h = this->scale
  };
  SDL_RenderFillRect(this->renderer, &rect);
}

void Screen::setDrawColor(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void Screen::clear() {
  this->setDrawColor(0, 0, 0, 0);
  SDL_RenderClear(this->renderer);
}

void Screen::display() {
  SDL_RenderPresent(this->renderer);
}