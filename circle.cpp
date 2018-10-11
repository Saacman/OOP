#include "circle.hpp"

Circle::Circle() : m_radius(0.0) { }

Circle::Circle( Point center, double radius, Color fill ) {
   if ( radius < 0.0 ) throw "negative radius";
   m_bbox = BBox( Point(center.x-radius, center.y-radius), Point(center.x+radius, center.y+radius) );
   m_center = center;
   m_radius = radius;
   set_fill(fill);
}

// accessors
Point Circle::center() const {
   return m_center;
}

double Circle::radius() const {
   return m_radius;
}


// OVERRIDE
// interfaz común con otras figuras
bool Circle::test( Point pt ) {
   double d2;
   if ( !m_bbox.test(pt) ) return false;

   d2 =  (m_center.x - pt.x)*(m_center.x - pt.x);
   d2 += (m_center.y - pt.y)*(m_center.y - pt.y);
   if ( d2 <= m_radius*m_radius ) return true;
   return false;
}
