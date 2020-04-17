#include "head.h"

/*

    Aplicacoes:

        Encontra o ponto de intersecao das retas pq e rs.

    Parametros

        point p -> ponto inicial da reta pq
        point q -> ponto final da reta pq
        point r -> ponto inicial da reta rs
        point s -> ponto final da reta rs

    Devolve

        point p -> ponto de intersecao das retas pq e rs

*/
point line_intersect(point p, point q, point r, point s)
{
    point a = q - p, b = s - r, c = point(p % q, r % s);
    return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}

int main()
{
    return 0;
}
