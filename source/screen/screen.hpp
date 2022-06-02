/**
 * @file screen.hpp
 * @author Rza Ismayilov (rzaismail82@gmail.com)
 * @author Taleh Taghiyev (taleh.taghiyev@ufaz.az)
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <iostream>
#include <SDL.h>

class Screen {
private:
  /// main window
  SDL_Window * window;

  /// renderer for the window object
  SDL_Renderer * renderer;

  /// scaling coeff of renderer
  int scale;
  
public:
  /**
   * @brief Construct a new Screen object
   * 
   * @param width the width of window
   * @param height the height of window
   * @param scale the scaling coeff of renderer
   */
  Screen(int width, int height, int scale);

  /**
   * @brief Destroy the Screen object
   */
  ~Screen();

  /**
   * @brief render a cell at the position (x, y)
   * 
   * @param x the x axis of window
   * @param y the y axis of window
   */
  void render(int x, int y);

  /**
   * @brief Set the Draw Color object
   * 
   * @param r Red
   * @param g Green
   * @param b Blue
   * @param a Alpha
   */
  void setDrawColor(int r, int g, int b, int a);

  /**
   * @brief lear the window
   */
  void clear();

  /**
   * @brief display the rendered colors
   */
  void display();
};
