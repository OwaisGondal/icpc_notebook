#include "head.h"

/*
    Aplicacoes:

        Retorna a area orientada de um poligono T

    Parametros

        polygon T -> Poligono a ser analisado

    Devolve

        double area -> Area orientada do poligono T

*/
double poly_area(polygon& T)
{
    double s = 0; int n = T.size();

    for (int i = 0; i < n; i++) s += T[i] % T[(i+1) % n];

    return s / 2;
}


int main()
{
    return 0;
}
