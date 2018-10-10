#include "circle.hpp"

Circle::Circle() : m_radius(0.0) { }

Circle::Circle( Point center, double radius, Color fill ) {
   if ( radius < 0.0 ) throw "negative radius";

   m_center = center;
   m_radius = radius;
   m_fill = fill;
   
}

// accessors
Point Circle::center() const {
   return m_center;
}

double Circle::radius() const {
   return m_radius;
}

Color Circle::fill() const {
   return m_fill;
}


// interfaz común con otras figuras
bool Circle::test( Point pt ) {
   double d2;
   // distancia = (x - x_c)^2 + (y - y_c)^2
   d2 =  (m_center.x - pt.x)*(m_center.x - pt.x);
   d2 += (m_center.y - pt.y)*(m_center.y - pt.y);
   if ( d2 <= m_radius*m_radius ) return true;
   return false;
}

Color Circle::ptcolor( Point pt ) {
   if ( test(pt) ) return m_fill;
   return Color(CLEAR);
}
