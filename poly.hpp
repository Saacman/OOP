#ifndef POLY_HPP
#define POLY_HPP

#include <vector>
#include "point.hpp"
#include "segment.hpp"
#include "color.hpp"
#include "bbox.hpp"
#include "shape.hpp"

class Poly : public Shape {
public:
    Poly();
    ~Poly();
    Poly( std::vector<Point> edges , Color fill=Color(BLACK) );

    // accessors
    Point edge( int index) const;
    int sides() const;

    bool test( Point pt );

protected:
    std::vector<Point> m_edges;
};

#endif
