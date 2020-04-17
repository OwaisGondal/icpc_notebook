#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <sstream>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))

using namespace std;

const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

int cmpD(double a, double b = 0.0) { return a+EPS < b ? -1 : a-EPS > b; }


/*

8.1 Ponto 3D

Estrutura de dados que define um ponto 3D

*/

struct Point
{
    double x, y, z;
    Point(double a=0.0,double b=0.0,double c=0.0){x=a,y=b,z=c;}
    Point operator+(const Point &P) const {return Point(x+P.x,y+P.y,z+P.z);}
    Point operator-(const Point &P) const {return Point(x-P.x,y-P.y,z-P.z);}
    Point operator*(double c) const {return Point(x*c,y*c,z*c);}
    Point operator/(double c) const {return Point(x/c,y/c,z/c);}
    double operator!() const {return sqrt(x*x+y*y+z*z);}
};

typedef struct
{
        Point ver1;
        Point ver2;
        Point ver3;
        Point ver4;

} tetrahedron;

typedef struct
{
        Point v1;
        Point v2;
        Point v3;

} triangle;

Point cross(Point A, Point B)
{
    return Point(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}

Point diff(Point a, Point b)
{
        Point c;

        c.x = a.x - b.x;
        c.y = a.y - b.y;
        c.z = a.z - b.z;

        return(c);
}

/*


// do the segments A-B and C-D intersect? (assumes coplanar)
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

double dist_tet_tet(Point T1[4], Point T2[4])
{
    double ans = INF;

    for (int i=0; i < 4; i++) // arestas -> arestas
        for (int j=i+1; j < 4; j++)
            for (int ii=0; ii < 4; ii++)
                for (int jj=ii+1; jj < 4; jj++)
                    ans = min( ans, dist_seg_seg(T1[i],T1[j],T2[ii],T2[jj]) );


    // pontos -> planos
    for (int i=0; i < 4; i++)
        for (int j=i+1; j < 4; j++)
            for (int k=j+1; k < 4; k++)
                for (int x=0; x < 4; x++)
                    ans = min( ans, dist_point_tri(T1[x],T2[i],T2[j],T2[k]) ),
                    ans = min( ans, dist_point_tri(T2[x],T1[i],T1[j],T1[k]) );

    return ans;
}

double volume(Point T[4])
{
    return fabs(dot(T[3],cross(T[1]-T[0],T[2]-T[0]))/6.);
}

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
    return 0;
}
*/
