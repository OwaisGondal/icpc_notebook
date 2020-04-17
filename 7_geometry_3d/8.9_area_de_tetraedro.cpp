#include "head.h"

double Length(Point a)
{
    return(sqrt(a.x*a.x + a.y*a.y + a.z*a.z));
}

double Area(triangle t)
{
        Point a, b, c;

        a = diff(t.v3,t.v1);
        b = diff(t.v2,t.v1);
        c = cross(a,b);

        return(Length(c)/2);
}

triangle Side(tetrahedron T,int i)
{
        triangle t;

        switch (i)
        {
        case 1: t.v1 = T.ver2;
                t.v2 = T.ver3;
                t.v3 = T.ver4;
                break;

        case 2: t.v1 = T.ver1;
                t.v2 = T.ver3;
                t.v3 = T.ver4;
                break;

        case 3: t.v1 = T.ver1;
                t.v2 = T.ver2;
                t.v3 = T.ver4;
                break;

        case 4: t.v1 = T.ver1;
                t.v2 = T.ver2;
                t.v3 = T.ver3;
                break;
        }

        return(t);
}

double area_tet(tetrahedron T)
{
    double area = 0;
    for(int i=0; i<4; i++) area = area + Area(Side(T,i));
    return area;
}

int main()
{

}
