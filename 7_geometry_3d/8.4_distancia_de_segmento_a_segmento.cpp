#include "head.h"

double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }
Point project(Point W, Point V) { return V * dot(W,V) / dot(V,V); }

bool seg_intersect(Point A, Point B, Point C, Point D)
{
    return cmpD(dot(cross(A-B,C-B),cross(A-B,D-B))) <= 0 &&
    cmpD(dot(cross(C-D,A-D),cross(C-D,B-D))) <= 0;
}

double dist_point_seg(Point P, Point A, Point B)
{
    Point PP = A + project(P-A,B-A);
    if (cmpD(!(A-PP)+!(PP-B),!(A-B)) == 0) return !(P-PP);//distance point-line!
    return min(!(P-A),!(P-B));
}

// segment-segment distance (lines too!)
double dist_seg_seg(Point A, Point B, Point C, Point D)
{
    Point E = project(A-D,cross(B-A,D-C)); // distance between lines!
    if (seg_intersect(A,B,C+E,D+E)) return !E;
    return min( min( dist_point_seg(A,C,D), dist_point_seg(B,C,D) ),
    min( dist_point_seg(C,A,B), dist_point_seg(D,A,B) ) );
}

int main()
{

}
