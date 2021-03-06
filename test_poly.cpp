#include <iostream>
#include <vector>
#include "lodepng.h"
#include "color.hpp"
#include "point.hpp"
#include "image.hpp"
#include "poly.hpp"

using namespace std;

int main() {

   Image im(800,600,Color(CLEAR));
   // Vector de los vertices del
   vector<Point> edges_oct;
   edges_oct.push_back( Point(106,169) );
   edges_oct.push_back( Point( 59,254) );
   edges_oct.push_back( Point( 85,348) );
   edges_oct.push_back( Point(170,396) );
   edges_oct.push_back( Point(264,369) );
   edges_oct.push_back( Point(312,284) );
   edges_oct.push_back( Point(286,190) );
   edges_oct.push_back( Point(200,142) );

   Poly shape( edges_oct, Color(AQUA) );

   // Dibuja objetos tipo Box en la imagen
   Color temp;
   for ( int y=0; y<im.height(); y++ ) {
      for ( int x=0; x<im.width(); x++ ) {

         temp = shape.ptcolor(Point(x,y));
         // if ( temp == Color(CLEAR) ) im(x,y) = im.bgcolor();
         // else im(x,y) = temp;
         if ( temp != Color(CLEAR) ) im(x,y) = temp;

         // prueba todos los objetos
         // for ( int k=0; k<3; k++ ) {
         //    cout << "DEBUG 1" << endl;
         //    temp = vpoly[k].ptcolor(Point(x,y));
         //    cout << "DEBUG 2" << endl;
         //    if ( temp != Color(CLEAR) ) break;
         // }

         // // determina el color del pixel (x,y)
         // if ( temp != Color(CLEAR) ) im(x,y) = temp;
         // else im(x,y) = im.bgcolor();

      }
   }

   im.save("poly2.png");
}
