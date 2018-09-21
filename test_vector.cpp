#include <iostream>
#include "vector.hpp"

using namespace std;

int main() {
   Vector v1(5);

   v1[0] = 1;
   v1[1] = 2;
   v1[2] = 3;
   v1[3] = 4;
   v1[4] = 5;

   // creo una copia
   //Vector v2 = v1;
   Vector v2;
   v2 = v1;
   v2[0] = 9;

   cout << "v1 = " << v1 << endl;
   cout << "v2 = " << v2 << endl;
   //cout << "el elemento 2 es " << vec[2] << endl;
   // la expresión anterior es equivalente a:
   //cout << "el elemento 2 es " << m_data[2] << endl;

   //vec[2] = 9;
   //la expresión anterior es equivalente a: m_data[2] = 9;
   //vec.print();

   return 0;
}
