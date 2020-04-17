#include "head.h"

double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }
Point project(Point W, Point V) { return V * dot(W,V) / dot(V,V); }

double dist_point_seg(Point P, Point A, Point B)
{
    Point PP = A + project(P-A,B-A);
    if (cmpD(!(A-PP)+!(PP-B),!(A-B)) == 0) return !(P-PP);//distance point-line!
    return min(!(P-A),!(P-B));
}

// point-triangle distance. dps = dist_point_seg
double dist_point_tri(Point P, Point A, Point B, Point C)
{
    Point N = cross(A-C,B-C);
    Point PP = P + project(C-P,N);
    Point V1 = cross(PP-A,B-A);
    Point V2 = cross(PP-B,C-B);
    Point V3 = cross(PP-C,A-C);

    if (cmpD(dot(V1,V2)) >= 0 && cmpD(dot(V1,V3)) >= 0 && cmpD(dot(V2,V3)) >= 0)
    return !(PP-P); // distance point-plane!
    return min(dist_point_seg(P,A,B),min(dist_point_seg(P,A,C),dist_point_seg(P,B,C)));
}

int main()
{

}
