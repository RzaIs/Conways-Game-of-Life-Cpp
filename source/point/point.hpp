/**
 * @file point.hpp
 * @author Rza Ismayilov (rzaismail82@gmail.com)
 * @author Taleh Taghiyev (taleh.taghiyev@ufaz.az)
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

class Point
{
public:
  /// x axis or column of a point
  int x;

  /// y axis or row of a point
  int y;

  /**
   * @brief Construct a new Point object
   * 
   * @param x x axis or column of a point
   * @param y y axis or row of a point
   */
  Point(int x, int y);

  /**
   * @brief Destroy the Point object
   */
  ~Point();
};
