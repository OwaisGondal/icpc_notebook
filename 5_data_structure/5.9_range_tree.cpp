#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAXN 1000 //numero maximo de pontos

using namespace std;

/*

    RANGE TREE

    Aplicacoes:

        Dado um conjunto de pontos do plano cartesiano,
        determinar de forma eficiente quantos pontos
        estao dentro do retangulo delimitado pelos pontos
        (x1,y1) e (x2,y2), onde (x1,y1) eh a coordenada
        do canto inferior esquerdo e (x2,y2) eh a
        coordenada do cando superior direito do retangulo.

    Como chamar a funcao:

        1) Armazenar os pontos em vector<pt> pts

        2) Chamar a funcao build() pra montar a arvore

        3) Realizar as queries chamando:

            query (0, 0, xs.size() - 1, x1, x2, y1, y2) onde:

            (x1,y1) -> coordenada do canto inferior esquerdo
            (x2,y2) -> coordenada do canto superior direito

    Resultado da funcao:

        A funcao query() retorna o numero de pontos contidos
        no retangulo definido pelos pontos (x1,y1) e (x2,y2)

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/


const double EPS = 1e-9, INF = 1e9;

inline int sgn(double a)
{
    return a > EPS ? 1 : (a < -EPS ? -1 : 0);
}

inline int cmp(double a, double b)
{
    return sgn(a - b);
}

struct pt
{
    double x, y;
    pt(double x = 0, double y = 0) : x(x), y(y) { }
    bool operator==(pt p)
    {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }
    bool operator < (pt p) const
    {
        return cmp (x, p.x) ? cmp (x, p.x) < 0 : cmp(y, p.y) < 0;
    }
    bool operator<= (pt p)
    {
        return *this < p || *this == p;
    }
    double operator|| (pt p)
    {
        return x*p.x + y*p.y;
    }
    double operator% (pt p)
    {
        return x*p.y - y*p.x;
    }
    pt operator~ ()
    {
        return pt(x, -y);
    }
    pt operator+ (pt p)
    {
        return pt(x + p.x, y + p.y);
    }
    pt operator- (pt p)
    {
        return pt(x - p.x, y - p.y);
    }
    pt operator* (pt p)
    {
        return pt(x*p.x - y*p.y, x*p.y + y*p.x);
    }
    pt operator/ (double t)
    {
        return pt(x/t, y/t);
    }
    pt operator/ (pt p)
    {
        return (*this * ~p)/(p||p);
    }
};

bool compy(pt a, pt b)
{
    return cmp(a.y, b.y) ? cmp(a.y, b.y) < 0 : cmp(a.x, b.x) < 0;
}

vector <pt> pts; //conjunto de pontos
vector <pt> tree[MAXN];
vector <double> xs;
vector <int> lnk[MAXN][2];

int recurse (int root, int left, int right)
{
    lnk[root][0].clear();
    lnk[root][1].clear();
    tree[root].clear();
    if(left == right)
    {
        vector<pt>::iterator it;
        it = lower_bound(pts.begin(), pts.end(), pt(xs[left], -INF));
        for(; it != pts.end() && cmp(it->x, xs[left]) == 0; ++it)
            tree[root].push_back(*it);
        return tree[root].size();
    }
    int mid = (left + right)/2, cl = 2*root + 1, cr = cl + 1;
    int sz1 = recurse(cl, left, mid);
    int sz2 = recurse(cr, mid + 1, right);
    lnk[root][0].reserve(sz1+sz2+1);
    lnk[root][1].reserve(sz1+sz2+1);
    tree[root].reserve(sz1+sz2);
    int l = 0, r = 0, llink = 0, rlink = 0;
    pt last;
    while (l < sz1 || r < sz2)
    {
        if (r == sz2 || (l < sz1 && compy(tree[cl][l], tree[cr][r])))
            tree[root].push_back(last = tree[cl][l++]);
        else
            tree[root].push_back(last = tree[cr][r++]);
        while (llink < sz1 && compy(tree[cl][llink], last))
            ++llink;
        while (rlink < sz2 && compy(tree[cr][rlink], last))
            ++rlink;
        lnk[root][0].push_back(llink);
        lnk[root][1].push_back(rlink);
    }
    lnk[root][0].push_back(tree[cl].size());
    lnk[root][1].push_back(tree[cr].size());
    return tree[root].size();
}

void build()
{
    sort(pts.begin(), pts.end());
    xs.clear();
    for (int i = 0; i < pts.size(); ++i)
        xs.push_back(pts[i].x);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    recurse(0, 0, xs.size() - 1);
}

//query (0, 0, xs.size() - 1, x1, x2, y1, y2)
int query (int root, int l, int r, double x1, double x2, double y1, double y2,
           int posl = -1, int posr = -1)
{
    if (root == 0 && posl == -1)
    {
        posl = lower_bound(tree[0].begin(), tree[0].end(), pt(x1, y1), compy)
               - tree[0].begin();
        posr = upper_bound(tree[0].begin(), tree[0].end(), pt(x2, y2), compy)
               - tree[0].begin();
    }
    if (posl == posr)
        return 0;
    if (x1 <= xs[l] && xs[r] <= x2)
        return posr - posl;
    int mid = (l+r)/2, ret = 0;
    if (cmp(x1, xs[mid]) <= 0)
        ret += query(2*root+1, l, mid, x1, x2, y1, y2,
                     lnk[root][0][posl], lnk[root][0][posr]);
    if (cmp(xs[mid+1], x2) <= 0)
        ret += query(2*root+2, mid+1, r, x1, x2, y1, y2,
                     lnk[root][1][posl], lnk[root][1][posr]);
    return ret;
}

int main()
{
    return 0;
}
