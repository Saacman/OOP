#include "regular.hpp"

Regular::Regular( Point center, double radius, int sides, Color fill) : m_radius(radius), m_sides(sides) {
    if ( radius < 0.0 || sides <= 0 ) throw "Invalid values";
    // Definiendo el contenedor
    m_bbox = BBox( Point(center.x-radius, center.y-radius), Point(center.x+radius, center.y+radius) );

    m_center = center;

    double theta = (2 * M_PI) / double(sides);
    for (int i = 0; i < sides; i++) {

        m_edges.push_back(Point(center.x + radius * sin(i*theta), center.y + radius * cos(i*theta) ));
    }

    set_fill(fill);

}
int Regular::sides() const {
    return m_sides;
}
double Regular::radius() const {
    return m_radius;
}

Point Regular::center() const {
    return m_center;
}
