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
#include <math.h>
#include <sstream>
#include <assert.h>
#include <numeric>
#include <limits>
#define INF 0x3f3f3f3f

using namespace std;

struct matriz
{
    int n,m;
    long long **mat;

    matriz(int n_, int m_)
    {
        n = n_;
        m = m_;
        mat = (long long **)calloc(n_, sizeof(long long *));
        for(int i=0; i<n_; i++) mat[i] = (long long *)calloc(m_, sizeof(long long));
    }

    matriz operator + (matriz MAT)
    {
        if(MAT.n != n || MAT.m != m) return matriz(0,0);
        else
        {
            matriz answer(n,m);
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++) answer.mat[i][j] = mat[i][j]+MAT.mat[i][j];
            }
        }
    }

    matriz operator - (matriz MAT)
    {
        if(MAT.n != n || MAT.m != m) return matriz(0,0);
        else
        {
            matriz answer(n,m);
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++) answer.mat[i][j] = mat[i][j]-MAT.mat[i][j];
            }
        }
    }

    matriz operator * (matriz MAT)
    {
        if(m != MAT.n) { printf("Invalid Sizes...\n"); return matriz(0,0); }
        else
        {
            matriz answer(n,MAT.m);
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<MAT.m; j++)
                {
                    for(int k=0; k<m; k++)
                    {
                        answer.mat[i][j] += mat[i][k]*MAT.mat[k][j];
                    }
                }
            }
            return answer;
        }
    }

    void set(int i, int j, long long val)
    {
        mat[i][j] = val;
    }

    long long get(int i, int j)
    {
        return mat[i][j];
    }
};

std::ostream& operator<<(std::ostream& o, matriz f)
{
    for(int i=0; i<f.n; i++)
    {
        for(int j=0; j<f.m; j++)
        {
            o << f.get(i,j) << " ";
        }
        o << endl;
    }
    return o;
}

int main()
{
    matriz a(2,3);
    matriz b(3,2);

    a.set(0,0,2); a.set(0,1,5); a.set(0,2,9);
    a.set(1,0,3); a.set(1,1,6); a.set(1,2,8);

    b.set(0,0,2); b.set(0,1,7);
    b.set(1,0,4); b.set(1,1,3);
    b.set(2,0,5); b.set(2,1,2);

    matriz c = a*b;

    cout << c << endl;

    return 0;
}
