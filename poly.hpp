#ifndef POLY_HPP
#define POLY_HPP

#include <vector>
#include "point.hpp"
#include "segment.hpp"
#include "color.hpp"

class Poly {
public:
    Poly( std::vector<Point> edges , Color fill=Color(BLACK) );

    // accessors
    Color fill() const;
    Point edge( int index) const;

    bool test( Point pt );
    Color ptcolor( Point pt );

private:
    Color m_fill;
    std::vector<Point> m_edges;
};

#endif
