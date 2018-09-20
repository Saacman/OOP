#ifndef BOX_HPP
#define BOX_HPP

#include "color.hpp"
#include "point.hpp"

class Box {
public:
    Box();
    Box( Point t_left, Point b_right, Color fill=Color(BLACK));

    // accessors
    Point top_l() const;
    Point bottom_r() const;
    Color fill() const;

    // interfaz comun con otras figuras
    bool test( Point pt );
    Color ptcolor( Point pt );

private:
    Point top_left;
    Point bottom_right;
    Color m_fill;
};
#endif
