#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Rectangle.hh"
#include "gnuplot_link.hh"
#include "operating.hh"



using namespace std;



int main()
{
       double verts[4][2]={{1.3,1.3},{1.3,2.3},{2.3,2.3},{2.3,1.3}};

       Vector2D V[4];

       for(int i=0; i <POINTS; i++)
       {
              V[i] = verts[i];
       }

       Matrix2x2 M;
       Rectangle R;

       R = V;
       std::cout << std::fixed << std::setprecision(10) << R << std::endl;

       M.Set(1);

       for(int i=0; i < 3600000; i++)
       R = M*R;
       std::cout << std::fixed << std::setprecision(10) << R << std::endl;

}