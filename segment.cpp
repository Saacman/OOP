#include "segment.hpp"

Segment::Segment() : m_slope(0.0), m_bias(0.0) { }

Segment::Segment(Point pt1, Point pt2) : m_pt1(pt1), m_pt2(pt2) {
    // Ajuste para rectas verticales
    const double epsilon = 0.000001;

    m_slope = (pt1.y - pt2.y) / (pt1.x - pt2.x + epsilon); //Evita la division entre 0
    m_bias = pt1.y - (m_slope * pt1.x);
}
// determina el punto de cruce de las rectas
Point Segment::solve(Segment other) {
    Point p;
    //if ( !intersection(other) ) throw "There is not intersection";
    p.x = (other.m_bias - m_bias) / (m_slope - other.m_slope);
    p.y = (m_slope * p.x) + m_bias;
    return p;
}
//Determina si hay intersección entre los elementos this y other
// La intersección debe ser entre los segmentos, no entre las rectas de los segmentos.
bool Segment::intersection(Segment other) {
    if (m_slope == other.m_slope) return false;

    Point sol = solve(other);
    double x_min = (m_pt1.x < m_pt2.x) ? m_pt1.x : m_pt2.x;
    double x_max = (m_pt1.x > m_pt2.x) ? m_pt1.x : m_pt2.x;
    double y_min = (m_pt1.y < m_pt2.y) ? m_pt1.y : m_pt2.y;
    double y_max = (m_pt1.y > m_pt2.y) ? m_pt1.y : m_pt2.y;

    //if (( sol.x < x_min || sol.x > x_max ) || (sol.y < y_min || sol.y > y_max)) return false;
    if (x_min != x_max) {
        if ( sol.x < x_min || sol.x > x_max ) return false;
        // if ( sol.x < x_min ) return false;
        // if ( sol.x > x_min ) return false;
    }
    if (y_min != y_max) {
        if ( sol.y < y_min || sol.y > y_max ) return false;
        // if ( sol.y < y_min ) return false;
        // if ( sol.y > y_max ) return false;
    }
    // Verificar other

    x_min = (other.m_pt1.x < other.m_pt2.x) ? other.m_pt1.x : other.m_pt2.x;
    x_max = (other.m_pt1.x > other.m_pt2.x) ? other.m_pt1.x : other.m_pt2.x;
    y_min = (other.m_pt1.y < other.m_pt2.y) ? other.m_pt1.y : other.m_pt2.y;
    y_max = (other.m_pt1.y > other.m_pt2.y) ? other.m_pt1.y : other.m_pt2.y;

    //if ( sol.x < x_min || sol.x > x_max ) || (sol.y < y_min || sol.y > y_max) return false;
    if (x_min != x_max) {
        if ( sol.x < x_min || sol.x > x_max ) return false;
        // if ( sol.x < x_min ) return false;
        // if ( sol.x > x_min ) return false;
    }
    if (y_min != y_max) {
        if ( sol.y < y_min || sol.y > y_max ) return false;
        // if ( sol.y < y_min ) return false;
        // if ( sol.y > y_max ) return false;
    }

    return true;
}
