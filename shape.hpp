#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include "point.hpp"

//Clase base para la familia de figuras
class Shape {
public:
    // mutator
    void set_fill( Color fill );
    // void fill( Color fill );

    //accesor
    Color get_fill();
    // Color fill();

    bool test( Point pt );
    Color ptcolor( Point pt );
protected:
    Color m_fill;

};
