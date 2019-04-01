#include "Rectangle.hh"

#define SIDES POINTS       // SIDES are equal do POINTS
#define TIME 3             // time of animation (in seconds)

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

    
    void Rectangle::rotate(double angle, int times, PzG::GnuplotLink &link)
    {
        Matrix2x2 matrix(angle);

        for(int i=0; i<times; i++)
        {
            (*this) = matrix * (*this);
        }

//   if (!WriteToFileExample("prostokat.dat",rect)) return 1;
//   link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    }

    void Rectangle::move(Vector2D vector, PzG::GnuplotLink &link)
    {
        Vector2D lpf;                  // length per frame
        double fps = 60;               //frame per sec
        Rectangle buff = *this;

        for(int i=0; i <DIMENSIONS; i++)
        {
            lpf[i] = vector[i]/(fps*TIME);
        }

        link.Draw();
        for(int i=0; i < fps*TIME; i++)
        {
            (*this) = (*this) + lpf;
            if (!WriteToFileExample("prostokat.dat")) return;
            link.Draw();
        }

        (*this) = buff + vector;
        if (!WriteToFileExample("prostokat.dat")) return;
        link.Draw();
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

// ========================================================================
//  GnuPlot - Drawing =====================================================

int Rectangle::gnuPlotDraw(PzG::GnuplotLink link)
{
  link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');
  return 0;
}

void Rectangle::WriteToStreamExample(std::ostream& output_stream)
{
    for(int i=0; i<POINTS; i++){
        output_stream << vertice[i] << std::endl;
    }
    output_stream << vertice[0] << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}


bool Rectangle::WriteToFileExample(std::string filename)
{
  std::fstream  file_stream;

  file_stream.open(filename);
  if (!file_stream.is_open())  {
    std::cerr << "Error: Open to write operation of file \"" << filename << "\"" << std::endl
	 << "failed." << std::endl;
    return false;
  }

  WriteToStreamExample(file_stream);

  file_stream.close();
  return !file_stream.fail();
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