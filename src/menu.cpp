#include "menu.hh"


void show_options()
{
    std::cout << "==========================================" << std::endl;
    std::cout << "================ M E N U =================" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "|----------------------------------------|" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "| r - rotate rectangle by angle          |" << std::endl;
    std::cout << "| m - move rectangle by vector           |" << std::endl;
    std::cout << "| d - draw rectangle (GnuPlot)           |" << std::endl;
    std::cout << "| c - show rectangle coordintes          |" << std::endl;
    std::cout << "| o - show options                       |" << std::endl;
    std::cout << "| q - quit                               |" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "|----------------------------------------|" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}


void menu( Rectangle& rec)
{
    std::string line;
    char c;

/* GNUPLOT =================================================================*/
/* ========================================================================= */
    PzG::GnuplotLink  link;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    link.AddFilename("prostokat.dat",PzG::LS_CONTINUOUS,2);

    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    link.SetDrawingMode(PzG::DM_2D);

    // [DEBUG]
    // WriteToStreamExample(std::cout, rect);
    
    if (!rec.WriteToFileExample("prostokat.dat")) return;

/* ========================================================================= */
/* GNUPLOT ================================================================= */

    system("clear");
    rec.check();
    show_options();

    do
    {   
        std::cout << "\n Your choice: ";
        std::getline(std::cin, line);
        std::cout << std::endl;

        if(std::cin.fail() || line.length() != 1)
        {
            std::cout << " Failed, please enter your choice again: ";
            std::cin.clear();
            continue;
        }
        else
        {
            c = line[0];
        }
        
        double angle;
        int count;
        Vector2D vector;
        
        switch (c)
        {
            case 'r':
                std::cout << "------------------------------------------" << std::endl;
                std::cout << " Angle: ";
                std::cin >> angle;

                std::cout << " How many rotates: ";
                std::cin >> count;
                std::cin.ignore(1,'\n');


                rec.rotate(angle, count, link);
                rec.check();
                std::cout << "------------------------------------------" << std::endl;
                break;

            case 'm':
                std::cout << "------------------------------------------" << std::endl;
                std::cout << " Vector (x y): ";
                std::cin >> vector;
                std::cin.ignore(1,'\n');
                rec.move(vector, link);
                std::cout << "\n New coordinates: " << std::endl;
                rec.coord();
                std::cout << "------------------------------------------" << std::endl;
                break;

            case 'c':
                std::cout << "------------------------------------------" << std::endl;
                rec.coord();
                std::cout << "------------------------------------------" << std::endl;
                break;

            case 'o':
                system("clear");
                rec.check();
                show_options();
                break;

            case 'd':
                std::cout << "------------------------------------------" << std::endl;
                rec.gnuPlotDraw(link);
                std::cout << "------------------------------------------" << std::endl;
                break;

            case 'q':
                break;

            default:
                std::cout << " Unknown option, try again: ";
                break;
        }

    } while (c != 'q');
}