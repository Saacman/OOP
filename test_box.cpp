#include <iostream>
#include <vector>
#include "lodepng.h"
#include "color.hpp"
#include "point.hpp"
#include "image.hpp"
#include "box.hpp"

using namespace std;

int main() {

   Image im(800,600,Color(WHITE));

   vector<Box> vbox;
   vbox.push_back( Box(Point(100,100), Point(300,300), Color(TEAL))   );
   vbox.push_back( Box(Point(500,100), Point(700,300), Color(BLUE))    );
   vbox.push_back( Box(Point(100,400), Point(700,500), Color(NAVY)) );

   // Dibuja objetos tipo Box en la imagen
   Color temp;
   for ( int y=0; y<im.height(); y++ ) {
      for ( int x=0; x<im.width(); x++ ) {

         // prueba todos los objetos
         for ( int k=0; k<3; k++ ) {
            temp = vbox[k].ptcolor(Point(x,y));
            if ( temp != Color(CLEAR) ) break;
         }

         // determina el color del pixel (x,y)
         if ( temp != Color(CLEAR) ) im(x,y) = temp;
         else im(x,y) = im.bgcolor();

      }
   }

   im.save("box.png");
}
