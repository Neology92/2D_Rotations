#include "Vector2D.hh"


// Constructor
Vector2D::Vector2D()
{
    for (int i=0; i < DIMENSIONS; i++){
        coordinate[i] = 0.0;
    }
}

// Constructor overload
Vector2D::Vector2D(double arg[])
{
    for(int i=0; i < DIMENSIONS; i++){
        coordinate[i] = arg[i];
    }
}


double Vector2D::operator[] (int index) const
{
    assert(index>=0 && index < DIMENSIONS);
        return coordinate[index]; 
}


double& Vector2D::operator[] (int index)
{
    assert(index>=0 && index < DIMENSIONS);

    return coordinate[index]; 
}


std::istream& operator >> (std::istream& stream, Vector2D& vector)
{
    double list[DIMENSIONS];
    
    for(int i=0; i<DIMENSIONS; i++){
        stream >> list[i];
    }

    for(int i=0; i < DIMENSIONS; i++){
        vector[i] = list[i];
    }

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
    double XY[DIMENSIONS];

    for(int i=0; i < DIMENSIONS; i++)
    {
        XY[i] = matrix(i,0)*vector[0] + matrix(i,1)*vector[1];
    }
    
    Vector2D result(XY);

    return result;
}


Vector2D operator * (Vector2D& v1, Vector2D& v2)
{
    Vector2D result;

    for(int i=0; i<DIMENSIONS; i++)
    {
        result[i] = v1[i] * v2[i];
    }

    return result;
}


Vector2D operator + (Vector2D& v1, Vector2D& v2)
{
    Vector2D result;

    for(int i=0; i < DIMENSIONS; i++)
    {
        result[i] = v1[i] + v2[i];
    }

    return result;
}