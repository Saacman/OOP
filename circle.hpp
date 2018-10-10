#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "color.hpp"
#include "point.hpp"
#include "shape.hpp"

class Circle {
   public:
      Circle();
      Circle( Point center, double radius, Color fill=Color(BLACK) );

      // accessors
      Point center() const;
      double radius() const;
      //Color fill() const;

      // interfaz común con otras figuras
      bool test( Point pt );  override
      // Color ptcolor( Point pt );

   private:
      Point  m_center;
      double m_radius;
      //Color  m_fill;
};

#endif
