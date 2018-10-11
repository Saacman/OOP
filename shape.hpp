#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include "point.hpp"
#include "bbox.hpp"

//Clase base para la familia de figuras
class Shape {
public:
    Shape();
    virtual ~Shape();

    // mutator
    void set_fill( Color fill );
    // void fill( Color fill );

    //accesor
    Color get_fill();
    // Ya que test es un metodo virtual, las clases derivadas pueden llamar a sus propios metodos antes
    virtual bool test( Point pt );

    Color ptcolor( Point pt );
protected:
    Color m_fill;
    BBox m_bbox; //Ahora cada figura tendrá su propio contenedor.

};
#endif
