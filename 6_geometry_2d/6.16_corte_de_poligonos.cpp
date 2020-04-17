#include <cmath>
#include <vector>

using namespace std;

const double eps = 1e-9;
inline int diff(double lhs, double rhs)
{
    if (lhs - eps < rhs && rhs < lhs + eps) return 0;
    return (lhs < rhs) ? -1 : 1;
}
inline bool is_between(double check, double a, double b)
{
    if (a < b)
        return (a - eps < check && check < b + eps);
    else
        return (b - eps < check && check < a + eps);
}

struct Point
{
    double x, y;
    Point() {}
    Point(double x_, double y_): x(x_), y(y_) {}
    bool operator==(const Point& rhs) const
    {
        return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
    }
    const Point operator+(const Point& rhs) const
    {
        return Point(x + rhs.x, y + rhs.y);
    }
    const Point operator-(const Point& rhs) const
    {
        return Point(x - rhs.x, y - rhs.y);
    }
    const Point operator*(double t) const
    {
        return Point(x * t, y * t);
    }
};

struct Line
{
    Point pos, dir;
    Line() {}
    Line(const Point& pos_, const Point& dir_): pos(pos_), dir(dir_) {}
};

inline double inner(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y;
}

inline double outer(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}

inline int ccw_line(const Line& line, const Point& point)
{
    return diff(outer(line.dir, point - line.pos), 0);
}


bool get_cross(const Line& a, const Line& b, Point& ret)
{
    double mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) return false;
    double t2 = outer(a.dir, b.pos - a.pos) / mdet;
    ret = b.pos + b.dir * t2;
    return true;
}

inline double dist2(const Point &a, const Point &b)
{
    return inner(a - b, a - b);
}

// left side of a->b
vector<Point> cut_polygon(const vector<Point>& polygon, Line line)
{
    if (!polygon.size()) return polygon;
    typedef vector<Point>::const_iterator piter;
    piter la, lan, fi, fip, i, j;
    la = lan = fi = fip = polygon.end();
    i = polygon.end() - 1;
    bool lastin = diff(ccw_line(line, polygon[polygon.size() - 1]), 0) > 0;
    for (j = polygon.begin() ; j != polygon.end() ; j++)
    {
        bool thisin = diff(ccw_line(line, *j), 0) > 0;
        if (lastin && !thisin)
        {
            la = i;
            lan = j;
        }
        if (!lastin && thisin)
        {
            fi = j;
            fip = i;
        }
        i = j;
        lastin = thisin;
    }
    if (fi == polygon.end())
    {
        if (!lastin) return vector<Point>();
        return polygon;
    }
    vector<Point> result;
    for (i = fi ; i != lan ; i++)
    {
        if (i == polygon.end())
        {
            i = polygon.begin();
            if (i == lan) break;
        }
        result.push_back(*i);
    }
    Point lc, fc;
    get_cross(Line(*la, *lan - *la), line, lc);
    get_cross(Line(*fip, *fi - *fip), line, fc);
    result.push_back(lc);
    if (diff(dist2(lc, fc), 0) != 0) result.push_back(fc);
    return result;
}

int main()
{

}
