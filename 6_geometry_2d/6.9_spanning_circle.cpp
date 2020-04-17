#include "head.h"

/*
    Aplicacoes:

        Encontra o menor circulo que contem todos os pontos dados.

    Parametros

        point p -> ponto inicial da reta pq
        point q -> ponto final da reta pq
        point r -> ponto inicial da reta rs
        point s -> ponto final da reta rs

    Devolve

        circle c -> menor circulo que contém todos os pontos dados.

*/


bool in_circle(circle C, point p)
{
    return cmp(abs(p - C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r)
{
    point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

circle spanning_circle(vector<point>& T)
{
    int n = T.size();

    random_shuffle(ALL(T));

    circle C(point(), -INFINITY);

    for (int i = 0; i < n; i++) if (!in_circle(C, T[i]))
    {
        C = circle(T[i], 0);

        for (int j = 0; j < i; j++) if (!in_circle(C, T[j]))
        {
            C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);

            for (int k = 0; k < j; k++) if (!in_circle(C, T[k]))
            {
                point o = circumcenter(T[i], T[j], T[k]);
                C = circle(o, abs(o - T[k]));
            }
        }
    }

    return C;
}

int main()
{
    return 0;
}
