#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {
    // Código comentado porque los métodos fueron reemplazados
    // Se mantiene para consulta.
   // Matrix A(5,5);
   //
   // cout << "rows = " << A.rows() << endl;
   // cout << "cols = " << A.cols() << endl;
   //
   // A.set(0,0,1);
   // A.set(1,1,1);
   // A.set(2,2,1);
   // A.set(3,3,1);
   // A.set(4,4,1);
   //
   // A.print();
   Matrix A(2,3);
   Matrix B(3,2);
   cout << "rows = " << A.rows() << endl;
   cout << "cols = " << A.cols() << endl;
   for (int i = 0; i < 2; i++) {
     for (int j = 0; j < 3; j++) {
       A.at(i, j) = i+j+1;
     }
   }
   for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 2; j++) {
       B.at(i, j) = i+j+7;
     }
   }

   //Multiplicacion de Matrices
   A.print();
   cout << endl;
   B.print();
   cout << endl;
   Matrix X = A.dot(B);
   X.print();

   //Uso de at()
   cout << "\nEl elemento (0,0) es " << A.at(0,0) << "\n\n";
   A.at(0,0) = 9;
   A.print();

   //Uso del Constructor copia
   //Matrix copy = A;
   Matrix copy(A);
   copy.at(0, 0) = 10;
   cout << endl << "copia: "<< endl;
   copy.print();
   cout << endl << "original: "<<endl;
   A.print();
   return 0;


   return 0;
}
