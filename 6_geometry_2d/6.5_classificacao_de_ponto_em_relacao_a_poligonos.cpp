#include "head.h"


/*
    Aplicacoes:

        Classifica o ponto p em relacao ao poligono T.

    Parametros

        point p -> ponto a ser analisado
        polygon T -> poligono a ser analisado

    Devolve

        0 -> p esta no exterior do poligono T
        1 -> p esta na fronteira de T
        -1 -> p esta no interior de T

*/

bool between(point p, point q, point r)
{
    return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

double angle(point p, point q, point r)
{
    point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}

int in_poly(point p, polygon& T)
{
    double a = 0; int N = T.size();

    for (int i = 0; i < N; i++)
    {
        if (between(T[i], p, T[(i+1) % N])) return -1;
        a += angle(T[i], p, T[(i+1) % N]);
    }

    return cmp(a) != 0;
}


int main()
{
    return 0;
}
