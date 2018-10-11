#include "bbox.hpp"


BBox::BBox( Point topleft, Point bottomright ) {
   if ( topleft.x > bottomright.x || topleft.y > bottomright.y )
      throw "coordenadas incorrectas (bl, tr)";

   m_topleft = topleft;
   m_bottomright = bottomright;
}

BBox::BBox( std::vector<Point> edges ) {
   if ( edges.size() == 0 ) throw "vector vacío";

   double x_min = edges[0].x;
   double x_max = edges[0].x;
   double y_min = edges[0].y;
   double y_max = edges[0].y;

   for ( unsigned i=1; i<edges.size(); i++ ) {
      if ( edges[i].x < x_min ) x_min = edges[i].x;
      if ( edges[i].x > x_max ) x_max = edges[i].x;
      if ( edges[i].y < y_min ) y_min = edges[i].y;
      if ( edges[i].y > y_max ) y_max = edges[i].y;
   }

   m_topleft = Point(x_min, y_min);
   m_bottomright = Point(x_max, y_max);
}

Point BBox::topleft() const {
   return m_topleft;
}

Point BBox::bottomright() const {
   return m_bottomright;
}

bool BBox::test( Point pt ) {
   if ( m_bottomright.x < pt.x ) return false;
   if ( m_topleft.x     > pt.x ) return false;
   if ( m_topleft.y     > pt.y ) return false;
   if ( m_bottomright.y < pt.y ) return false;
   return true;
}

