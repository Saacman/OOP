#ifndef BBOX_HPP
#define BBOX_HPP

#include <vector>
#include "point.hpp"

class BBox {
   public:
      BBox() { }
      BBox( Point topleft, Point bottomright );
      BBox( std::vector<Point> edges );

      Point topleft() const;
      Point bottomright() const;

      bool test( Point pt );

   private:
      Point m_topleft;
      Point m_bottomright;
};

#endif

