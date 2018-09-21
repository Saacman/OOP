#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <ostream>

class Vector {
   public:
      Vector();
      Vector( unsigned size );
      Vector( unsigned size, const int* data );
      Vector( const Vector& original ); // Constructor Copia
      ~Vector(); // destructor

      // asignación
      Vector operator=( const Vector& original );

      // accessor
      unsigned size() const;
      void print() const;
      const int& at( unsigned index ) const;
      const int& operator[]( unsigned index ) const;

      // mutators
      int& at( unsigned index );
      int& operator[]( unsigned index );

      friend std::ostream& operator<<( std::ostream& out, const Vector& vec );

   private:
      unsigned m_size;
      int* m_data;
};

std::ostream& operator<<( std::ostream& out, const Vector& vec );

#endif

