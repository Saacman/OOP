#include "shape.hpp"

Shape::Shape() {}
Shape::~Shape() {}


//Establece el color de la figura
void Shape::set_fill( Color fill ) {
    m_fill = fill;
}

// Retorna el color de la figura
Color Shape::get_fill() {
    return m_fill;
}

bool Shape::test( Point pt ) {
    return false;
}

Color Shape::ptcolor( Point pt ) {
    if(test(pt)) return m_fill;
    return Color(CLEAR);
}
