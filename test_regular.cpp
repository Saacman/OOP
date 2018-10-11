#include <iostream>
#include <vector>
#include "lodepng.h"
#include "color.hpp"
#include "point.hpp"
#include "image.hpp"
#include "regular.hpp"

using namespace std;

int main() {

   Image im(800,600,Color(WHITE));

   Regular penta( Point(400, 300), 100.0, 5, Color(AQUA) );

   // Dibuja objetos tipo Box en la imagen
   Color temp;
   for ( int y=0; y<im.height(); y++ ) {
      for ( int x=0; x<im.width(); x++ ) {

         temp = penta.ptcolor(Point(x,y));
         if ( temp != Color(CLEAR) ) im(x,y) = temp;

      }
   }

   im.save("regular5.png");
}
