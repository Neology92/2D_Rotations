#pragma once

#include <iostream>
#include <cmath>
#include <assert.h>

#define SIZE 2      /* of matrix */

/**
 * @brief Stores matrix 2x2
 * 
 *  Allows to access by () operator
 */
class Matrix2x2 {
  
private:
  double value[SIZE][SIZE];

public:
  Matrix2x2(double);                       /* Constructor counts matrix rely on angle*/
  double operator() (int,int) const;       /* (Getter) - [] operator overload - allows to access to values */

};


/**
 * @brief allows to show matrix values
 * 
 * @param stream - output stream
 * @param matrix - Matrix2x2 object which values have to be wirten
 * @return std::ostream&
 */
std::ostream& operator << (std::ostream & stream, const Matrix2x2 & matrix);

