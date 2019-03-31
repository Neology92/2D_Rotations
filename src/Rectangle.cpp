#include "Rectangle.hh"

#define SIDES POINTS       // SIDES are equal do POINTS

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

    
    void Rectangle::rotate(double angle, int times)
    {
        Matrix2x2 matrix(angle);

        for(int i=0; i<times; i++)
        {
            (*this) = matrix * (*this);
        }
    }

    void Rectangle::move(Vector2D vector)
    {
        (*this) = (*this) + vector;
    }


    bool Rectangle::check()
    {
        bool fine = true;

        double values[SIDES][DIMENSIONS];

        for(int i=0; i<SIDES; i++)
        {
           for(int j=0; j<DIMENSIONS; j++)
           {
                values[i][j] = abs((*this)[i][j] - (*this)[i+1][j]);
           }
        }

        for(int i=0; i<SIDES; i++)
        {
           for(int j=0; j<DIMENSIONS; j++)
           {
               std::cout << "[" << i << "][" <<j << "] :" << values[i][j] << std::endl;
           }
        }

        



        // if(pow(values[0],2) + pow(values[1],2) != pow(values[2],2) + pow(values[3],2))
            // fine = false;


        return fine;
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