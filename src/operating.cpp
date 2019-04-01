#include "operating.hh"

void WriteToStreamExample(std::ostream& output_stream, Rectangle R)
{
    for(int i=0; i<POINTS; i++){
        output_stream << R[i] << std::endl;
    }
    output_stream << R[0] << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}


bool WriteToFileExample(std::string filename, Rectangle R)
{
  std::fstream  file_stream;

  file_stream.open(filename);
  if (!file_stream.is_open())  {
    std::cerr << "Error: Open to write operation of file \"" << filename << "\"" << std::endl
	 << "failed." << std::endl;
    return false;
  }

  WriteToStreamExample(file_stream,R);

  file_stream.close();
  return !file_stream.fail();
}


int gnuPlotDraw(Rectangle rect)
{
  PzG::GnuplotLink  link;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  link.AddFilename("prostokat.dat",PzG::LS_CONTINUOUS,2);

   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  link.SetDrawingMode(PzG::DM_2D);


  link.Draw(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');
  return 0;
}
