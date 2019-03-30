#pragma once

#include <iostream>
#include "Vector2D.hh"

#define POINTS 4      /* number of vertices */

/**
 * @brief Creates concept of rectangle, stores 4 vertices
 * 
 * Allows to access by [] operator
 * 
 */
class Rectangle {

private: 
  Vector2D vertice[POINTS];

public:
  Rectangle();                             /* Constructor */
  Rectangle(Vector2D[]);                   /* Calls Setter */
  Vector2D& operator[] (int);              /* (Setter) */
  Vector2D operator [] (int) const;        /* (Getter) - [] operator overload - allows to access to coordinate */
};


/**
 * @brief Allows to show rectangle vertices
 * 
 * @param stream - output stream
 * @param rect  - rectangle object
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& stream, Rectangle& rect);


/**
 * @brief Allows to multiply rectangle by matrix
 * 
 * @param matrix 
 * @param rectangle 
 * @return Rectangle 
 */
Rectangle operator * (Matrix2x2& matrix, Rectangle& rectangle);


/**
 * @brief Allows to move rectangle by the vector
 * 
 * @param rectangle - Rectangle to move
 * @param vector    - Vector, by which rectangle has to be moved
 * @return Rectangle - Moved Rectangle
 */
Rectangle operator + (Rectangle& rectangle, Vector2D& vector);