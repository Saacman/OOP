#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include "lodepng.h"
#include "color.hpp"

class Image {
   public:
      Image();
      Image( int width, int height, Color bg=Color(CLEAR) );
      Image( const char* filename );

      // accessors
      int width() const;
      int height() const;
      Color bgcolor() const;
      const Color& at( int x, int y ) const;
      const Color& operator()( int x, int y ) const;

      // mutators
      void clear();
      void bgcolor( const Color& bg );
      Color& at( int x, int y );
      Color& operator()( int x, int y );

      // File I/O
      void load( const char* filename );
      void save( const char* filename );

   private:
      Color m_bg;
      int m_width;
      int m_height;
      std::vector<Color> m_pixel;
};

#endif
