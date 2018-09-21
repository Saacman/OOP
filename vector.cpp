#include "vector.hpp"

Vector::Vector() : m_size(0), m_data(nullptr) { };

Vector::Vector( unsigned size ) : Vector() {
   if ( size == 0 ) return;

   //this->m_size = size;
   //(*this).m_size = size;
   m_size = size;
   m_data = new int[size];
   for ( unsigned i=0; i<size; i++ ) m_data[i] = 0;
}

Vector::Vector( unsigned size, const int* data ) : Vector() {
   if ( size == 0 ) return;

   m_size = size;
   m_data = new int[size];
   for ( unsigned i=0; i<size; i++ ) m_data[i] = data[i];
}

Vector::Vector( const Vector& original ) : Vector() { // Constructor Copia

   m_size = original.m_size;
   m_data = new int[m_size];
   for ( unsigned i=0; i<m_size; i++ ) m_data[i] = original.m_data[i];
}

Vector::~Vector() { // destructor
   if ( m_data != nullptr ) {
      delete [] m_data;
   }
}

// operador de asignación
Vector Vector::operator=( const Vector& original ) {
   m_size = original.m_size;
   m_data = new int[m_size];
   for ( unsigned i=0; i<m_size; i++ ) m_data[i] = original.m_data[i];
   return *this;
}

// accessors
unsigned Vector::size() const {
   return m_size;
}

void Vector::print() const {
   for ( unsigned i=0; i<m_size; i++ ) std::cout << m_data[i] << " ";
   std::cout << std::endl;
}

const int& Vector::at( unsigned index ) const {
   return m_data[index];
}

const int& Vector::operator[]( unsigned index ) const {
   return m_data[index];
}

// mutators
int& Vector::at( unsigned index ) {
   return m_data[index];
}

int& Vector::operator[]( unsigned index ) {
   return m_data[index];
}


// print con cout
std::ostream& operator<<( std::ostream& out, const Vector& vec ) {
   out << "[";
   for ( unsigned i=0; i<vec.m_size-1; i++ ) {
      out << vec.m_data[i] << ", ";
   }
   out << vec.m_data[vec.m_size-1] << "]";

   return out;
}

