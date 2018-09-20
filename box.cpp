#include "box.hpp"

Box::Box() { }

Box::Box( Point t_left, Point b_right, Color fill ) {
    if (t_left.x == b_right.x && t_left.y == b_right.y) throw "That is a point";

    top_left = t_left;
    bottom_right = b_right;
    m_fill = fill;
}

// accessors
Point Box::top_l() const {
    return top_left;
}

Point Box::bottom_r() const {
    return bottom_right;
}

Color Box::fill() const {
    return m_fill;
}

// interfaz comun con otras figuras
bool Box::test( Point pt ) {
    if ( (pt.x >= top_left.x && pt.x <= bottom_right.x) && (pt.y >= top_left.y && pt.y <= bottom_right.y)) return true;
    return false;
}
Color Box::ptcolor( Point pt ) {
    if ( test(pt) ) return m_fill;
    return Color(CLEAR);
}
