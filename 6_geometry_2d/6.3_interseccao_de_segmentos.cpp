#include "head.h"

/*
    Aplicacoes:

        Decide se os segmentos fechados pq e rs tem pontos em comum.

    Parametros

        point p -> ponto inicial da reta pq
        point q -> ponto final da reta pq
        point r -> ponto inicial da reta rs
        point s -> ponto final da reta rs

    Devolve

        true -> se os segmentos de retas pq e rs se cruzam
        false -> se os segmentos de retas pq e rs nao se cruzam

*/
bool seg_intersect(point p, point q, point r, point s)
{
    point A = q - p, B = s - r, C = r - p, D = s - q;

    int a = cmp(A % C) + 2 * cmp(A % D);

    int b = cmp(B % C) + 2 * cmp(B % D);

    if (a == 3 || a == -3 || b == 3 || b == -3) return false;

    if (a || b || p == r || p == s || q == r || q == s) return true;

    int t = (p < r) + (p < s) + (q < r) + (q < s);

    return t != 0 && t != 4;
}


int main()
{
    return 0;
}
