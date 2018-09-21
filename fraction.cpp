#include "fraction.hpp"

// Constructor por defecto
Fraction::Fraction() : num(0), den(0) { }

//Constructor con valores de inicialización
Fraction::Fraction( int n, int d) : Fraction() /*: num(n), den(d)*/{
    //this->num = num;
    num = n;
    den = d;
    simplify();
}

// Suma +
Fraction Fraction::operator+( Fraction b ) {
    Fraction C( num * b.den + b.num * den, den * b.den);
    C.simplify();
    return C;
}

// Resta -
Fraction Fraction::operator-( Fraction b ) {
    Fraction C( num * b.den - b.num * den, den * b.den );
    C.simplify();
    return C;
}

// Multiplicacion *
Fraction Fraction::operator*( Fraction b ) {
    Fraction C( num * b.num, den * b.den );
    C.simplify();
    return C;
}

// Division /
Fraction Fraction::operator/( Fraction b ) {
    Fraction C( num * b.den, den * b.num );
    C.simplify();
    return C;
}

// Se utiliza <return *this> porque las funciones indican un tipo de retorno.
// Incremento ++
Fraction Fraction::operator++(int) {
    num += den;
    simplify();
    return *this;
}

// Decremento --
Fraction Fraction::operator--(int) {
    num -= den;
    simplify();
    return *this;
}

// asignación
// Funciona como un constructor copia
Fraction Fraction::operator=( const Fraction& original ) {
    num = original.num;
    den = original.den;
    return *this;
}
// Comparadores booleanos
// utilizan const a la derecha porque no modifican los atributos
// Igual ==
bool Fraction::operator==( Fraction b ) const {
    if ( num == b.num && den == b.den ) return true;
    return false;
}

// Diferente !=
bool Fraction::operator!=( Fraction b ) const {
    if (num != b.num || den != b.den) return true;
    return false;
}

// mayor que >
bool Fraction::operator>( Fraction b ) const {
    if (num/den > b.num/b.den) return true;
    return false;
}

// menor que <
bool Fraction::operator<( Fraction b ) const {
    if (num/den < b.num/b.den) return true;
    return false;
}

// mayor que o igual >=
bool Fraction::operator>=( Fraction b ) const {
    if (num/den >= b.num/b.den) return true;
    return false;
}

// menor que o igual <=
bool Fraction::operator<=( Fraction b ) const {
    // if () return true;
    // return false;
    // Este retorno funciona, pero no es recomendable.
    // Se mantiene para consulta.
    return num/den <= b.num/b.den;
}

// accessors
int Fraction::numerador() const {
   return num;
}

int Fraction::denominador() const {
   return den;
}

// print con cout
std::ostream& operator<<( std::ostream& out, const Fraction& a ) {
   out << "[" << a.num <<"/"<< a.den << "]\n";

   return out;
}

// void Fraction::simplify() {
//     //Comprueba si es divisible por algun numero del 1 al 9
//     for (size_t i = 2; i < 10; i++) {
//         while(num%i != 0 || den %i != 0) {
//             num = num/i;
//             den = den/i;
//         }
//     }
// }

void Fraction::simplify() {
    // Encuentra el máximo comun multiplo
    int a, b, t;
    a = num;
    b = den;
    while( b!= 0 ) {
        t = b; b = a % b;
        a = t;
    }
    num = num / a;
    den = den / a;
    // Llamar a simplify en todos los metodos
}
