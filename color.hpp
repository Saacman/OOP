#ifndef COLOR_HPP
#define COLOR_HPP

typedef unsigned char uchar;

// HTML Colors
// -----------------------
// WHITE    0xFF 0xFF 0xFF
// SILVER   0xC0 0xC0 0xC0
// GRAY     0x80 0x80 0x80
// BLACK    0x00 0x00 0x00
// RED      0xFF 0x00 0x00
// MAROON   0x80 0x00 0x00
// YELLOW   0xFF 0xFF 0x00
// OLIVE    0x80 0x80 0x00
// LIME     0x00 0xFF 0x00
// GREEN    0x00 0x80 0x00
// AQUA     0x00 0xFF 0xFF
// TEAL     0x00 0x80 0x80
// BLUE     0x00 0x00 0xFF
// NAVY     0x00 0x00 0x80
// FUCHSIA  0xFF 0x00 0xFF
// PURPLE   0x80 0x00 0x80

enum ColorName { CLEAR, WHITE, SILVER, GRAY, BLACK, RED, MAROON, YELLOW, OLIVE,
                 LIME, GREEN, AQUA, CYAN, TEAL, BLUE, NAVY, FUCHSIA, MAGENTA,
                 PURPLE };

// class Color {
//    public:
struct Color {

   Color();
   Color( uchar gray );
   Color( uchar gray, uchar alpha );
   Color( uchar red, uchar green, uchar blue );
   Color( uchar red, uchar green, uchar blue, uchar alpha );
   Color( ColorName name );

   bool operator==( Color other );
   bool operator!=( Color other );

   uchar r;
   uchar g;
   uchar b;
   uchar a;
};

#endif

