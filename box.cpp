#include "box.hpp"


Box::Box( Point topleft, Point bottomright, Color fill ) {
   m_bbox = BBox(topleft, bottomright);
   m_fill = fill;
}

// accessors
Point Box::topleft() const {
   return m_bbox.topleft();
}

Point Box::bottomright() const {
   return m_bbox.bottomright();
}

bool Box::test( Point pt ) {
   return m_bbox.test(pt);
}
