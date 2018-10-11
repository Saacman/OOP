#ifndef BOX_HPP
#define BOX_HPP

#include "color.hpp"
#include "point.hpp"
#include "bbox.hpp"
#include "shape.hpp"

class Box : public Shape {
public:
   Box( Point topleft, Point bottomright, Color fill=Color(BLACK) );

   // accessors
   Point topleft() const;
   Point bottomright() const;

   bool test( Point pt );

   //Color ptcolor( Point pt );
};
#endif
