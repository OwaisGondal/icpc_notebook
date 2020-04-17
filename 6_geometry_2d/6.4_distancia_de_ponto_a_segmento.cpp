#include "head.h"


/*
    Aplicacoes:

        Calcula a distancia do ponto r ao segmento pq.

    Parametros

        point p -> ponto inicial da reta pq
        point q -> ponto final da reta pq
        point r -> ponto a ser analisado

    Devolve

        A distancia do segmento pq a reta r

*/

double seg_distance(point p, point q, point r)
{
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, b + c) >= 0) return sqrt(b);
    else return fabs(A % B) / sqrt(c);
}


int main()
{
    return 0;
}
