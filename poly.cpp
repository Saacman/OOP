#include "poly.hpp"
Poly::Poly() {}
Poly::~Poly() {}
Poly::Poly( std::vector<Point> edges , Color fill) {
    m_bbox = BBox(edges);
    m_edges = edges;
    set_fill( fill );
}

Point Poly::edge( int index) const {
    return m_edges[index];
}

int Poly::sides() const {
    return m_edges.size();
}

// Test verifica si un punto esta dentro del poligono.
bool Poly::test( Point pt ) {
    // La clase puede utilizar todos los puntos del plano, pero en las imagenes solo se dibuja en el cuadrante positivo
    // El punto de referencia t no interfiere en el plano de cualquier imagen
    if ( !m_bbox.test(pt) ) return false;
    Segment t( Point( m_bbox.topleft().x-1.0, m_bbox.topleft().y-1.0 ), pt );
    Segment s;

    int count = 0;
    int n = m_edges.size();
    for (unsigned i = 0; i < m_edges.size() - 1; i++) {
        s = Segment(m_edges[i], m_edges[i+1]);
        if( t.intersection(s) ) count++;
    }
    s = Segment(m_edges[n-1], m_edges[0]);
    if ( t.intersection(s) ) count++;

    if( count & 1) return true;
    return false;
}
