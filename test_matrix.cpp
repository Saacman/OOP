#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {

   Matrix A(5,5);

   cout << "rows = " << A.rows() << endl;
   cout << "cols = " << A.cols() << endl;

   A.set(0,0,1);
   A.set(1,1,1);
   A.set(2,2,1);
   A.set(3,3,1);
   A.set(4,4,1);

   A.print();

   return 0;
}

