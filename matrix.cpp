#include "matrix.hpp"

// constructor por default
//Matrix::Matrix() {
//   m_rows = 0;
//   m_cols = 0;
//   m_data = nullptr;
//}

// constructor por defecto con lista de inicialización
// los atributos pueden inicializarse con un valor que se pasa al atributo
// como si se tratara de una función
Matrix::Matrix() : m_rows(0), m_cols(0), m_data(nullptr) { }

// constructor con argumentos r,c
// Aquí, la lista de inicialización llama al constructor por defecto Matrix()
// es la única forma de llamar a un constructor desde otro
// la notación indica que, antes de ejecutar el código de este constructor,
// primero se debe ejecutar el constructor por defecto.
// Esto permite que el objeto esté inicializado aún si este constructor falla.
Matrix::Matrix( int r, int c ) : Matrix() {

   // si los valores de r y c no tienen sentido, el constructor falla
   // se queda con los valores iniciales establecidos por Matrix()
   if ( r < 1 || c < 1 ) return;

   // en caso contrario, los atributos se inicializan, y se reserva la memoria
   m_rows = r;
   m_cols = c;
   m_data = new double[r*c];
   for ( int i=0; i<r*c; i++ ) m_data[i] = 0.0;
}

// destructor
// solo libera la memoria si m_data no es nulo
// m_data es nulo si se usa el constructor por defecto o si
// el segundo constructor falla
Matrix::~Matrix() {
   if ( m_data != nullptr ) {
      delete [] m_data;
   }
}

int Matrix::rows() {
   return m_rows;
}

int Matrix::cols() {
   return m_cols;
}

double Matrix::get( int r, int c ) {
   return m_data[m_cols*r+c];
}

void Matrix::print() {
   for ( int r=0; r<m_rows; r++ ) {
      for ( int c=0; c<m_cols; c++ ) {
         std::cout << get(r,c) << " ";
      }
      std::cout << std::endl;
   }
}

void Matrix::set( int r, int c, double value ) {
   m_data[m_cols*r+c] = value;
}

