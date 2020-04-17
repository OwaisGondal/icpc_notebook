#include "head.h"

double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }
Point project(Point W, Point V) { return V * dot(W,V) / dot(V,V); }

double dist_point_seg(Point P, Point A, Point B)
{
    Point PP = A + project(P-A,B-A);
    if (cmpD(!(A-PP)+!(PP-B),!(A-B)) == 0) return !(P-PP);//distance point-line!
    return min(!(P-A),!(P-B));
}

int main()
{

}
