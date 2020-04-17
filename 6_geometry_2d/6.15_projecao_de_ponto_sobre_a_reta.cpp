#include "head.h"

double escalar(point a, point b)
{
    return a.x*b.x+a.y*b.y;
}

point getProjecaoPontoNaReta(point a, point b, point c)
{
    point u(b.x-a.x, b.y-a.y);
    point v(c.x-a.x, c.y-a.y);
    double k = escalar(u, v)/escalar(u, u);
    point w((int)(k*u.x), (int)(k*u.y));
    point d(a.x+w.x, a.y+w.y);
    return d;
}

point getPontoDeslocadoNaReta(point a, point b, double dist)
{
    int dx = a.x-b.x;
    int dy = a.y-b.y;
    double normaAB = distancia(a,b);
    double razao = dist/normaAB;
    return point((int)(a.x-dx*razao), (int)(a.y-dy*razao));
}

point getPontoDeslocadoEmDirecaoAReta(point a, point b, point c, double dist)
{
    point d = getProjecaoPontoNaReta(a, b, c);
    point e = getPontoDeslocadoNaReta(c, d, dist);
    return e;
}

int main()
{
    point a(-1,2);
    point b(2,1);
    point c(1,3);

    point d = getProjecaoPontoNaReta(a,b,c);

    cout << d << endl;
}
