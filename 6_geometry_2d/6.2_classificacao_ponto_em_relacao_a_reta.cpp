#include "head.h"

/*
    Aplicacoes:

        Decide se um ponto p esta sobre um segmento de reta pr

    Parametros

        point p -> ponto inicial da reta pq
        point q -> ponto a ser analisado
        point r -> ponto final da reta pq

    Devolve

        true -> se q esta sobrea reta pq
        false -> se q nao esta sobre a reta pq

*/
bool between(point p, point q, point r)
{
    return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

int main()
{
    return 0;
}
