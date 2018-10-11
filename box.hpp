#ifndef BOX_HPP
#define BOX_HPP

#include "color.hpp"
#include "point.hpp"
#include "bbox.hpp"
#include "shape.hpp"

class Box : public Shape {
public:
    Box( Point t_left, Point b_right, Color fill=Color(BLACK));

    // accessors
    Point top_l() const;
    Point bottom_r() const;

    //Color fill() const;

    bool test( Point pt );
};
#endif
