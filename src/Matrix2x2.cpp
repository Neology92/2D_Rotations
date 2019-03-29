#include "Matrix2x2.hh"



Matrix2x2::Matrix2x2()
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            value[i][j] = 0.0;
        }
        
    }
}


void Matrix2x2::Set(double angle)
{
    double rad = angle * M_PI/180.0;

    value[0][0] = cos(rad);
    value[0][1] = -sin(rad);
    value[1][0] = sin(rad);
    value[1][1] = cos(rad);
}


double Matrix2x2::operator() (int x,int y) const
{
    return value[x][y];
}


std::ostream& operator << (std::ostream& stream, const Matrix2x2& matrix)
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
           stream << matrix(i,j) << " ";
        }
        stream << std::endl;
    }

    return stream;
}