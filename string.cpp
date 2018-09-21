#include "string.hpp"


String::String() : m_length(0), m_data(nullptr) {}
// {
//    m_length = 0;
//    m_data = nullptr;
// }

String::String( const char* str ) : String() {

   if ( str == nullptr ) return;

   // determinar la longitud

   // m_length = 0; esto ya lo hace el constructor String()
   // int i = 0;
   // while( str[i] != 0 ) i ++;
   // m_length = i;

   while( str[m_length] != 0 ) m_length ++;

   // reservamos memoria para la cadena
   m_data = new char[m_length+1];

   // incializamos con el contenido de str
   for ( int i=0; i<m_length+1; i++ ) m_data[i] = str[i];
}

String::~String() {
   if ( m_data != nullptr ) {
      delete [] m_data;
   }
}

// método de acceso
int String::length() const {
   return m_length;
}

void String::print() const {
   std::cout << m_data << std::endl;
}

