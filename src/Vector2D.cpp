#include "Vector2D.hh"


// Constructor
Vector2D::Vector2D()
{
    for (int i=0; i < DIMENSIONS; i++){
        coordinate[i] = 0.0;
    }
}
// Constructor overload
Vector2D::Vector2D(double x, double y)
{
    coordinate[0] = x;
    coordinate[1] = y;
}
// Constructor overload
Vector2D::Vector2D(double arg[])
{
    Set(arg);
}



void Vector2D::Set(double arg[])
{
    for(int i=0; i < DIMENSIONS; i++){
        coordinate[i] = arg[i];
    }
}


double Vector2D::operator[] (int index) const
{
    return coordinate[index]; 
}


std::istream& operator >> (std::istream& stream, Vector2D& vector)
{
    double list[DIMENSIONS];
    
    for(int i=0; i<DIMENSIONS; i++){
        stream >> list[i];
    }

    vector.Set(list);

    return stream;
}


std::ostream& operator << (std::ostream& stream, Vector2D& vector)
{
    for (int i=0; i < DIMENSIONS; i++){
     std::cout << vector[i];
     std::cout << " ";
    }

    return stream;
}


Vector2D operator * (Matrix2x2& matrix, Vector2D& vector)
{
    double XY[2];

    XY[0] = matrix(0,0)*vector[0] + matrix(0,1)*vector[1];
    XY[1] = matrix(1,0)*vector[0] + matrix(1,1)*vector[1];
    
    Vector2D result(XY);

    return result;
}


Vector2D operator + (Vector2D& v1, Vector2D& v2)
{
    Vector2D result(v1[0]+v2[0], v1[1]+v2[1]);
    return result;
}