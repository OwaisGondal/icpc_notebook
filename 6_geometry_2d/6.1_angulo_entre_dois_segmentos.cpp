#include "head.h"

/*

    Aplicacoes:

        Calcula o angulo em Radianos entre os segmentos qp e qr

*/

double angle(point p, point q, point r)
{
    point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}

double dist(point a, point b)
{
    point c = a-b;
    return sqrt(c.x*c.x+c.y*c.y);
}

int main()
{
    return 0;
}
