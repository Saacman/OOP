#include <iostream>
#include <vector>
#include <math.h>
#include "image.hpp"

using namespace std;

int main() {
    // Este test funciona con una imagen png "orignal.png" incluida en el repo
    // Prueba de load()
    Image original;
    original.load("original.png");
    original.save("copia.png");

    // Prueba de background() y clear()
    original.bgcolor(LIME);
    original.clear();

    original.save("lime-bgnd.png");

    // Dibujando un triangulo
    // Uso del constructor con background
    Image triangulo( 300, 300, AQUA );

    for (int i = 100; i <=200; i++) {
        for(int j = 100; j<=200; j++) {
            if ( j >= -2*i+400 && i<150 ){
                triangulo.at(i,j) = Color(FUCHSIA);
            } else if ( j >= 2*i -200 && i >=150) {
                triangulo.at(i,j) = Color(FUCHSIA);
            }
        }
    }
    triangulo.save("triangulo.png");

    return 0;
}
