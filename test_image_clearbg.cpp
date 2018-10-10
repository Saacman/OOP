#include <iostream>
#include <vector>
#include <math.h>
#include "image.hpp"

using namespace std;

int main() {
    // Este test funciona con una imagen png "orignal.png" incluida en el repo
    // Prueba de load()
    Image im;
    im.load("original.png");

    for ( int y=0; y<im.height(); y++ ) {
       for ( int x=0; x<im.width(); x++ ) {
          if ( im(x,y) == Color(WHITE) ) im(x,y) = Color(CLEAR);
       }
    }

    im.save("clear_bg.png");

    return 0;
}
