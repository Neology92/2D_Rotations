#include "Rectangle.hh"

    // Constructor
    Rectangle::Rectangle(){}
    // Constructor overload
    Rectangle::Rectangle(Vector2D arg[])
    {
        for(int i=0; i < POINTS; i++){
            vertice[i] = arg[i];
        }
    }


    Vector2D Rectangle::operator[] (int index) const
    {
        return vertice[index];
    }


    Vector2D& Rectangle::operator[] (int index) 
    {
        return vertice[index];
    }


    std::ostream& operator << (std::ostream& stream,  Rectangle& rectangle)
    {

        for(int i=0; i<POINTS; i++)
        {
            Vector2D vec = rectangle[i];
            stream << vec << std::endl;
        }
    
        return stream;
    }


    Rectangle operator * (Matrix2x2& matrix, Rectangle& rectangle)
    {
        Vector2D rotated[4];

        for(int i=0; i<POINTS; i++)
        {
            rotated[i] = matrix * rectangle[i];
        }

        Rectangle result(rotated);
        return result;
    }


    Rectangle operator + (Rectangle& rectangle, Vector2D& vector)
    {
        Vector2D moved[4];

        for(int i=0; i<POINTS; i++)
        {
            moved[i] = rectangle[i] + vector;
        }

        Rectangle result(moved);

        return result;
    }