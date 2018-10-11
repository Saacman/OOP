#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "poly.hpp"
#include "point.hpp"
#include <cmath>

class Regular : public Poly {
public:
    Regular( Point center, double radius, int sides, Color fill=Color(BLACK) );
    Point center() const;
    double radius() const;
    int sides() const;
private:
    Point m_center;
    double m_radius;
    int m_sides;
};
#endif
