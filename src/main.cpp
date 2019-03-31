#include <iostream>
#include <fstream>
#include <string>

#include "Rectangle.hh"
#include "gnuplot_link.hh"
#include "operating.hh"



using namespace std;



int main()
{
       Vector2D V[4];
       double verts[4][2]={{1.0,1.0},{11.0,1.0},{11.0,6.0},{1.0,6.0}};
       
       for(int i=0; i <POINTS; i++){
              V[i] = verts[i];
       }

       Rectangle R;
       R = V;

       menu(R);
}