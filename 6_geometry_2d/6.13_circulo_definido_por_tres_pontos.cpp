#include "head.h"



/*

    Aplicacoes:

        Acha o circulo definido pelos pontos p1, p2 e p3

    Parametros

        point p1;
        point p2;
        point p3;

    Devolve

        double x,y -> Pontos do centro do circulo
        double r -> Raio do circulo

*/

double x, y, r;

void find_circle(point *p1, point *p2, point *p3)
{
    double x1, y1, x2, y2, x3, y3, temp;

    x1 = p1->x, y1 = p1->y;
    x2 = p2->x, y2 = p2->y;
    x3 = p3->x, y3 = p3->y;

    if (x1 == x2) swap(y3,y2), swap(x3,x2);

    y = ((x1-x2)*(x1*x1+y1*y1-x3*x3-y3*y3)-(x1-x3)*(x1*x1+y1*y1-x2*x2-y2*y2)) / (2*((y2-y1)*(x1-x3)-(y3-y1)*(x1-x2)));

    x = (x1*x1+y1*y1-x2*x2-y2*y2+2*y*(y2-y1)) / (2*(x1-x2));

    r = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}



int main()
{
    return 0;
}
