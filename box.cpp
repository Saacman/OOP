#include "box.hpp"

Box::Box() { }

Box::Box( Point t_left, Point b_right, Color fill ) {
    m_bbox = BBox(t_left, b_right);
    m_fill = fill;

// accessors
Point Box::top_l() const {
    return m_bbox.topleft();
}

Point Box::bottom_r() const {
    return m_bbox.bottomright();
}

// interfaz comun con otras figuras
bool Box::test( Point pt ) {
    return m_bbox.test(pt);
}
