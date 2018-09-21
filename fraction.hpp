#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <ostream>

class Fraction {

public:
    Fraction();
    Fraction( int n, int d);

    Fraction operator+( Fraction b );// Se gasta más memoria, porque es una copia. en este caso no importa es un objeto muy pequeño

    // Resta -
    Fraction operator-( Fraction b );

    // Multiplicacion *
    Fraction operator*( Fraction b );

    // Division /
    Fraction operator/( Fraction b );


    // Incremento ++
    Fraction operator ++ (int);

    // Decremento --
    Fraction operator -- (int);

    // asignación
    Fraction operator=( const Fraction& original );

    // Igual ==
    bool operator==( Fraction b ) const;

    // Diferente !=
    bool operator!=( Fraction b ) const;

    // mayor que >
    bool operator>( Fraction b ) const;

    // menor que <
    bool operator<( Fraction b ) const;
    // mayor que o igual >=
    bool operator>=( Fraction b ) const;

    // menor que o igual <=
    bool operator<=( Fraction b ) const;

    // accessors
    int numerador() const;

    int denominador() const;

    // print con cout
    friend std::ostream& operator<<( std::ostream& out, const Fraction& a );

    //Simplificar
    void simplify();

private:
    int num;
    int den;

};

#endif
