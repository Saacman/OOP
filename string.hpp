#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String {
   public:
      String();
      String( const char* str );
      ~String();

      // método de acceso
      int length() const;
      void print() const;

   private:
      int m_length; // longitud de la cadena
      char* m_data; // caracteres de la cadena
};

#endif

