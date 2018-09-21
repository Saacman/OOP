#include <iostream>
#include "string.hpp"

using namespace std;

int main() {

   String name("OOP");

   cout << "longitud = " << name.length() << endl;
   cout << "cadena = ";
   name.print();

   return 0;
}
