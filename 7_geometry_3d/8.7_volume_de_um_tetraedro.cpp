#include "head.h"

double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }

double volume(Point T[4])
{
    return fabs(dot(T[3],cross(T[1]-T[0],T[2]-T[0]))/6.);
}

int main()
{

}
