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

int main()
{

}
