#include <iostream>
#include "point.hpp"
#include "segment.hpp"

using namespace std;

int main() {
    // Prueba 1 : EN un ámbito aparte
    {
        Segment s1( Point(1.0, 1.0), Point(2.0, 2.0) );
        Segment s2( Point(1.0, 2.0), Point(2.0, 1.0) );

        if ( s1.intersection(s2) ) cout << "prueba 1: OK" <<endl;
        else cout << "prueba 1: ERROR" << endl;
    }

    // Prueba 2
    {
        Segment s1( Point(-1.0, 0.0), Point(1.0, 0.0) );
        Segment s2( Point(0.0, -1.0), Point(0.0, 1.0) );

        if ( s1.intersection(s2) ) cout << "prueba 2: OK" <<endl;
        else cout << "prueba 2: ERROR" << endl;
    }


}
