#include "head.h"

/*

    Aplicacoes:

        Calcula o centroide (centro de massa/gravidade) de um poligono

    Parametros

        polygon pts -> poligono a ser analisado

    Devolve

        point p -> centroide do poligono pts

*/

point centroide(polygon &pts)
{
    pts.push_back(pts[0]);

    int n = pts.size() - 1;
    double area = 0;

    for(int i=0; i<n; i++)
    {
        area += pts[i].x*pts[i+1].y-pts[i].y*pts[i+1].x;
    }

    double cx = 0, cy = 0;

    for(int i=0; i<n; i++)
    {
        cx += (pts[i].x+pts[i+1].x) * (pts[i].x*pts[i+1].y - pts[i+1].x*pts[i].y);
        cy += (pts[i].y+pts[i+1].y) * (pts[i].x*pts[i+1].y - pts[i+1].x*pts[i].y);
    }

    cx /= area*3.0;
    cy /= area*3.0;

    return point(cx,cy);
}

int main()
{
    return 0;
}

