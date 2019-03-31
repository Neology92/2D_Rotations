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
                values[i][j] = (*this)[i][j] - (*this)[i+1][j];
           }
        }

        for(int i=0; i<POINTS/2; i++)
        {
            if( pow(values[i][0],2) + pow(values[i][1],2) != pow(values[i+2][0],2) + pow(values[i+2][1],2) )
            {
                fine = false;
            }
        }

        if(fine){
              std::cout << "\n The opposite sides are: Equal!" << std::endl;
        }else{
              std::cout << "\n The opposite sides are: Not equal!" << std::endl;
        }
        len();

        return fine;
    }


    void Rectangle::len()
    {
        double values[SIDES][DIMENSIONS];

        for(int i=0; i<SIDES; i++)
        {
           for(int j=0; j<DIMENSIONS; j++)
           {
                values[i][j] = (*this)[i][j] - (*this)[i+1][j];
           }
        }

        for(int i=0; i<POINTS/2; i++)
        {
            std::cout << " Length of " << i+1 << " & " << i+3 << ": " << std::endl;
            std::cout << std::setw(16) << std::fixed << std::setprecision(10) 
                      << pow(values[i][0],2) + pow(values[i][1],2) << std::endl 
                      << std::setw(16) << std::fixed << std::setprecision(10)
                      << pow(values[i+2][0],2) + pow(values[i+2][1],2) << std::endl << std::endl;
        }
    }


    void Rectangle::coord()
    {
        for(int i=0; i<POINTS; i++)
        {
            std::cout << (char)(65+i) << ": " << vertice[i] << std::endl;
        }
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