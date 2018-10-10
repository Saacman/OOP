#include "image.hpp"

// Se eliminó el constructor por defecto, porque no queremos imágenes con 0
// elementos. Esto forza al cliente/usuario a utilizar alguno de los otros dos
// constructores.
Image::Image() : m_width(0), m_height(0) { }

// Constructor. Crea una imagen nueva con el ancho y el alto especificados, y
// opcionalmente, un color de fondo.

// width  = ancho de la imagen
// height = alto de la imagen
// bg     = color de fondo
Image::Image( int width, int height, Color bg ) {

   // verificamos que las dimensiones sean válidas
   if ( width < 1 || height < 1 ) throw "Wrong image dimensions";

   m_bg = bg;
   m_width = width;
   m_height = height;
   m_pixel.resize(width*height);
   m_pixel.shrink_to_fit();

   for ( int i=0; i<width*height; i++ ) m_pixel[i] = bg;
}

// Constructor. Carga la imagen de un archivo
// filename = nombre del archivo
Image::Image( const char* filename ) {
   load(filename);
}

//==============================================================================
// accessors
//==============================================================================

// regresa el ancho de la imagen
int Image::width() const {
   return m_width;
}

// regresa el alto de la imagen
int Image::height() const {
   return m_height;
}

// obtiene el color del fondo
Color Image::bgcolor() const {
   return m_bg;
}

// regresa una referencia no modificable al pixel (x,y)
const Color& Image::at( int x, int y ) const {
   return m_pixel[m_width*y+x];
}

// regresa una referencia no modificable al pixel (x,y)
const Color& Image::operator()( int x, int y ) const {
   return m_pixel[m_width*y+x];
}

//==============================================================================
// mutators
//==============================================================================

// establece el color del fondo
void Image::bgcolor( const Color& bg ) {
   m_bg = bg;
}

// borra la imagen usando el color del fondo
void Image::clear() {
   for ( int i=0; i<m_width*m_height; i++ ) m_pixel[i] = m_bg;
}

// regresa una referencia modificable al pixel (x,y)
Color& Image::at( int x, int y ) {
   return m_pixel[m_width*y+x];
}

// regresa una referencia modificable al pixel (x,y)
Color& Image::operator()( int x, int y ) {
   return m_pixel[m_width*y+x];
}


//==============================================================================
// File I/O
//==============================================================================

// carga una imagen desde un archivo PNG
void Image::load( const char* filename ) {
   std::vector<unsigned char> image;
   unsigned width, height;

   unsigned error = lodepng::decode(image, width, height, filename);
   if ( error ) throw "Wrong file name";

   m_width = width;
   m_height = height;
   m_pixel.clear(); // borra el vector y lo deja con 0 elementos
   m_pixel.resize(m_width*m_height);

   int k = 0;
   for ( int i=0; i<m_width*m_height; i++ ) {
      m_pixel[i].r = image[k++];
      m_pixel[i].g = image[k++];
      m_pixel[i].b = image[k++];
      m_pixel[i].a = image[k++];
   }
}

// guarda la imagen en un archivo PNG
void Image::save( const char* filename ) {
   std::vector<unsigned char> image;

   for ( int i=0; i<m_width*m_height; i++ ) {
      image.push_back( m_pixel[i].r );
      image.push_back( m_pixel[i].g );
      image.push_back( m_pixel[i].b );
      image.push_back( m_pixel[i].a );
   }

   unsigned error = lodepng::encode(filename, image, m_width, m_height);

   if ( error ) throw "Cannot save the file";
}
