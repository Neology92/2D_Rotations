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


       double verts[4][2]={{1.0,1.0},{11.0,1.0},{11.0,6.0},{1.0,6.0}};

       Vector2D V[4];

       for(int i=0; i <POINTS; i++)
       {
              V[i] = verts[i];
       }

       Rectangle R;

       R = V;
       
       menu(R);

       return 1;


       std::cout << std::fixed << std::setprecision(10) << R << std::endl;

       if(R.check()){
              std::cout << "The opposite sides are: Equal!" << std::endl;
       }else{
              std::cout << "The opposite sides are: Not equal!" << std::endl;
       }
       R.len();

       R.rotate(1,3600000);

       if(R.check()){
              std::cout << "The opposite sides are: Equal!" << std::endl;
       }else{
              std::cout << "The opposite sides are: Not equal!" << std::endl;
       }
       R.len();
}