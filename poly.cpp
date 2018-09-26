#include "poly.hpp"

Poly::Poly( std::vector<Point> edges , Color fill) : m_fill(fill) {
    m_edges = edges; // No se puede inicializar el vector en la lista de inicialización
}

Color Poly::fill() const {
    return m_fill;
}

Point Poly::edge( int index) const {
    return m_edges[index];
}
// Test verifica si un punto esta dentro del poligono.
bool Poly::test( Point pt ) {
    // La clase puede utilizar todos los puntos del plano, pero en las imagenes solo se dibuja en el cuadrante positivo
    // El punto de referencia t no interfiere en el plano de cualquier imagen
    Segment t(Point(-1.0, -1.0), pt);
    Segment s;

    int count = 0;
    int n = m_edges.size();
    for (unsigned i = 0; i < m_edges.size() - 1; i++) {
        s = Segment(m_edges[i], m_edges[i+1]);
        if( t.intersection(s) ) count++;
    }
    s = Segment(m_edges[n-1], m_edges[0]);
    if ( t.intersection(s) ) count++;
    // Si cruza un numero impar de segmentos el punto esta dentro del poligono.
    // Utiliza un verificador de paridad.
    // if ( count % 2 != 0 s)
    if( count & 1) return true;
    return false;
}

Color Poly::ptcolor( Point pt ) {
    if ( test(pt) ) return m_fill;
    return Color(CLEAR);
}
