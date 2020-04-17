#include "head.h"

/*

    Aplicacoes:

        Determina o fecho convexo de um conjunto de pontos

    Parametros:

        vector<point> pts -> pontos a serem analisados

    Devolve

        vector<point> pts -> devolve o fecho convexo no proprio container pts

    ATENCAO: A funcao destroi o conjunto de pontos pts
             deixando somente o fecho convexo

*/

#define REMOVE_REDUNDANT

double cross(point p, point q)
{
    return p.x*q.y-p.y*q.x;
}
double area2(point a, point b, point c)
{
    return cross(a,b) + cross(b,c) + cross(c,a);
}

#ifdef REMOVE_REDUNDANT
bool bet(const point &a, const point &b, const point &c)
{
    //Para considerar pontos colineares troque o <= por <
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<point> &pts)
{
    sort(pts.begin(), pts.end());

    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    vector<point> up, dn;

    for (int i = 0; i < pts.size(); i++)
    {
        //Para considerar pontos colineares troque o >= por >
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();

        //Para considerar pontos colineares troque o <= por <
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();

        up.push_back(pts[i]);

        dn.push_back(pts[i]);
    }

    pts = dn;

    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT

    if (pts.size() <= 2) return;

    dn.clear();

    dn.push_back(pts[0]);
    dn.push_back(pts[1]);

    for (int i = 2; i < pts.size(); i++)
    {
        if (bet(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }

    if (dn.size() >= 3 && bet(dn.back(), dn[0], dn[1]))
    {
        dn[0] = dn.back();
        dn.pop_back();
    }

    pts = dn;

#endif
}

//Função alternativa - PUC-RIO

bool radial_lt(point p, point q)
{
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

polygon convex_hull(vector<point>& T)
{
    int j = 0, k, n = T.size();
    polygon U(n);
    point::pivot = *min_element(ALL(T));
    sort(ALL(T), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + ALL(T));
    for (int i = 0; i < n; i++)
    {
// troque o >= por > para manter pontos colineares
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + ALL(U));
    return U;
}

int main()
{
    return 0;
}
