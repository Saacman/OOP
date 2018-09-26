#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "point.hpp"
class Segment {
public:
    Segment();
    Segment(Point pt1, Point pt2);
    //determina el punto de cruce de las rectas
    //Determina si hay intersección entre los elementos this y other
    bool intersection(Segment other);


private:
    Point m_pt1;
    Point m_pt2;
    double m_slope;
    double m_bias;
    Point solve(Segment other);
};

#endif
