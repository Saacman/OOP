#include <iostream>
#include "fraction.hpp"

using namespace std;

int main() {
    Fraction a(2, 3);
    Fraction b(1, 2);

    Fraction C;

    C = a + b;
    cout << C << '\n';

    C = a * b;
    cout << C << '\n';

    C = a / b;
    cout << C << '\n';

    a++;
    cout << a << '\n';

    b--;
    cout << b << '\n';

    if ( b <= a ) cout << "b <= a" << '\n';

    return 0;
}
