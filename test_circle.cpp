#include <iostream>
#include <vector>
#include "lodepng.h"
#include "color.hpp"
#include "point.hpp"
#include "image.hpp"
#include "circle.hpp"

using namespace std;

int main() {

   Image im(800,600,Color(WHITE));

   vector<Circle> vcirc;
   vcirc.push_back( Circle(Point(100,300), 100, Color(GREEN))   );
   vcirc.push_back( Circle(Point(600,200), 50,  Color(BLUE))    );
   vcirc.push_back( Circle(Point(400,300), 150, Color(MAGENTA)) );

   // Dibuja objetos tipo Circle en la imagen
   Color temp;
   for ( int y=0; y<im.height(); y++ ) {
      for ( int x=0; x<im.width(); x++ ) {

         // prueba todos los objetos
         for ( int k=0; k<3; k++ ) {
            temp = vcirc[k].ptcolor(Point(x,y));
            if ( temp != Color(CLEAR) ) break;
         }

         // determina el color del pixel (x,y)
         if ( temp != Color(CLEAR) ) im(x,y) = temp;
         else im(x,y) = im.bgcolor();

      }
   }

   im.save("circle.png");
}

