#include "head.h"

double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }

bool seg_intersect(Point A, Point B, Point C, Point D)
{
    return cmpD(dot(cross(A-B,C-B),cross(A-B,D-B))) <= 0 &&
    cmpD(dot(cross(C-D,A-D),cross(C-D,B-D))) <= 0;
}

int main()
{

}
