#include "color.hpp"

Color::Color() : r(0), g(0), b(0), a(0) { }
   // r = 0;
   // g = 0;
   // b = 0;
   // a = 0;
// }

Color::Color( uchar gray )
   : r(gray), g(gray), b(gray), a(255) { }
//   r = gray;
//   g = gray;
//   b = gray;
//   a = 255;
//}

Color::Color( uchar gray, uchar alpha )
   : r(gray), g(gray), b(gray), a(alpha) { }

Color::Color( uchar red, uchar green, uchar blue )
   : r(red), g(green), b(blue), a(255) { }

Color::Color( uchar red, uchar green, uchar blue, uchar alpha )
   : r(red), g(green), b(blue), a(alpha) { }

Color::Color( ColorName name ) {
   switch ( name ) {
      case CLEAR:   r = 0x00; g = 0x00; b = 0x00; a = 0x00; break;
      case WHITE:   r = 0xFF; g = 0xFF; b = 0xFF; a = 0xFF; break;
      case SILVER:  r = 0xC0; g = 0xC0; b = 0xC0; a = 0xFF; break;
      case GRAY:    r = 0x80; g = 0x80; b = 0x80; a = 0xFF; break;
      case BLACK:   r = 0x00; g = 0x00; b = 0x00; a = 0xFF; break;
      case RED:     r = 0xFF; g = 0x00; b = 0x00; a = 0xFF; break;
      case MAROON:  r = 0x80; g = 0x00; b = 0x00; a = 0xFF; break;
      case YELLOW:  r = 0xFF; g = 0xFF; b = 0x00; a = 0xFF; break;
      case OLIVE:   r = 0x80; g = 0x80; b = 0x00; a = 0xFF; break;
      case LIME:    r = 0x00; g = 0xFF; b = 0x00; a = 0xFF; break;
      case GREEN:   r = 0x00; g = 0x80; b = 0x00; a = 0xFF; break;
      case AQUA:
      case CYAN:    r = 0x00; g = 0xFF; b = 0xFF; a = 0xFF; break;
      case TEAL:    r = 0x00; g = 0x80; b = 0x80; a = 0xFF; break;
      case BLUE:    r = 0x00; g = 0x00; b = 0xFF; a = 0xFF; break;
      case NAVY:    r = 0x00; g = 0x00; b = 0x80; a = 0xFF; break;
      case FUCHSIA:
      case MAGENTA: r = 0xFF; g = 0x00; b = 0xFF; a = 0xFF; break;
      case PURPLE:  r = 0x80; g = 0x00; b = 0x80; a = 0xFF; break;
   }
}

bool Color::operator==( Color other ) {
   if ( r != other.r ) return false;
   if ( g != other.g ) return false;
   if ( b != other.b ) return false;
   if ( a != other.a ) return false;
   return true;
}

bool Color::operator!=( Color other ) {
   return !operator==(other);
}

