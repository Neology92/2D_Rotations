#pragma once

#include "Matrix2x2.hh"
#include <iostream>
#include <cstdarg>
#include <assert.h>
#include <iomanip>

#define DIMENSIONS 2               // Number of dimensions for Vector.. class

/**
 * @brief Stores 2D coordinates
 *
 * Allows to have an access to coordinates by [] operator
 */
class Vector2D {
  
private:
  double coordinate[DIMENSIONS];           /* Wskaźnik na którym zostanie zalokowana pamięć na tablicę koordynatów */

public:
  Vector2D(double, double);                           /* Initializes coordinate arr (by 0) */
  Vector2D();                                         /* Initializes coordinate arr (by 0) */  
  Vector2D(double []);                                         /* Initializes coordinate arr (by 0) */  
  /**
   * @brief Sets vaulues of coordinates
   * 
   * @param arg - array of coordinates
   */
  double operator [] (int) const;       /* (Getter) - [] operator overload - allows to show coordinate */
  double& operator[] (int index);       /* (Setter) - ---------||--------- - allows to rewrite coordinate */

  Vector2D operator * (Vector2D& v2);   /* Allows to multiply Vector2D by Vector 2D */
  Vector2D operator + (Vector2D& v2);   /* Allows to add two vectors */

};


/**
 * @brief allows do pass values to vector by input stream
 * 
 * @param stream - input stream
 * @param vector - vector to write
 * @return std::istream& 
 */
std::istream& operator >> (std::istream& stream, Vector2D& vector);

/**
 * @brief allows to pass vector values to ostream and show
 * 
 * @param stream - output stream
 * @param vector - vector to show
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& stream, Vector2D& vector);


/**
 * @brief Allows to multiply Vector2D by Matrix2x2
 * 
 * @param matrix - Matrix2x2 object
 * @param vector - Vector2D object
 * @return Vector2D   - result of multiplication
 */
Vector2D operator * (Matrix2x2& matrix, Vector2D& vector);