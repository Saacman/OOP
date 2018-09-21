#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix {
   public:
      // constructor por defecto
      // inicializa los atributos en cero
      // aunque es una matriz nula, es un objeto válido
      Matrix();

      // constructor con argumentos
      // crea una matriz de rows x cols
      // reserva la memoria necesaria
      Matrix( int rows, int cols );
      
      // Constructor copia
      // Recibe otro objeto matrix y copia adecuadamente los atributos en un nuevo objeto
      Matrix( const Matrix& original );

      // destructor
      // libera la memoria reservada, si la hubiera
      ~Matrix();

      // Métodos de acceso
      int rows(); // número de renglones
      int cols(); // número de columnas
   
      // get y set son reemplazados por at()
      //double get( int r, int c ); // regresa el valor r,c
      void print(); // imprime la matriz
   
      double& at( int row, int col ); // at() utiliza sobrecarga de funciones
      double& at( int row, int col ) const;

      // Métodos de mutación
      //void set( int r, int c, double value ); // cambia el valor r,c a value
   
      // Metodo para multiplicacion de matrices
      Matrix dot( const Matrix& other );

   // elementos privados de la clase
   // no son accesibles desde fuera de la clase
   // es decir, no se pueden llamar con el operador . como en A.m_rows
   private:
      int m_rows;     // número de renglones
      int m_cols;     // número de columnas
      double* m_data; // vector con los datos de la matriz
};

#endif

