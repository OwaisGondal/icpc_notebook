#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    3.19 Simplex

    Aplicacoes:

        determinar (x0, x1, ..., xn) de forma a maximizar
        P = c[0]*x0 + c[1]*x1 + ... + c[n]*xn, com as seguintes restricoes

        A[0][0]*x0 + A[0][1]*x1 + ... + A[0][n]*xn <= b0
        A[1][0]*x0 + A[1][1]*x1 + ... + A[1][n]*xn <= b1
        .......................................... <= ..
        A[n][0]*x0 + A[n][1]*x1 + ... + A[n][n]*xn <= bn

        x0 >= 0, x1 >= 0, ..., xn >= 0

        obs: se o problema consistir em minimizar P, sujeito a inequacoes do tipo >=,
        basta adicionar a equacao c[0]*x0 + c[1]*x1 + ... + c[n]*xn = 0
        ao final do sistema e calcular a transposta deste. a ultima equacao
        passa a ser a nova restricao do sistema (c[i]) e tem-se um novo sistema
        com A[i] e b[i] diferentes do anterior. calcula-se o simplex deste novo sistema
        e o valor maximo do sistema equivalente (transposta) consiste no valor minimo
        do sistema original.

    Retorna:

        um vetor {x0, x1, ..., xn} com os valores que maximizam o valor
        da equacao P.

    Problemas:

        UVA 802
        UVA 10498
*/

typedef long double T;
typedef vector <T> VT;
typedef vector <int> VI;
const double EPS = 1e-9;
vector <VT> A; //matriz A do sistema
VT b, c; //vetores b e c do sistema, respectivamente
VT res;
VI kt, N;
int m,n;

void initialize()
{

}

inline void pivot (int k, int l, int e)
{
    int x = kt[l];
    T p = A[l][e];

    for (int i = 0; i < k; ++i)
        A[l][i] /= p;

    b[l] /= p;
    N[e] = 0;

    for (int i = 0; i < m; ++i)
        if (i != l)
            b[i] -= A[i][e] * b[l], A[i][x] = A[i][e] * -A[l][x];

    for (int j = 0; j < k; ++j)
    {
        if (N[j])
        {
            c[j] -= c[e] * A[l][j];
            for (int i = 0; i < m; ++i)
                if (i != l)
                    A[i][j] -= A[i][e] * A[l][j];
        }
    }

    kt[l] = e;
    N[x] = 1;
    c[x] = c[e] * -A[l][x];
}

VT doit (int k)
{
    VT res;
    T best;

    while (1)
    {
        int e = -1, l = -1;

        for (int i = 0; i < k; ++i)
        {
            if (N[i] && c[i] > EPS)
            {
                e = i;
                break;
            }
        }

        if (e == -1)
            break;

        for (int i = 0; i < m; ++i)
            if (A[i][e]>EPS && (l == -1 || best > b[i] / A[i][e]))
                best = b[l = i] / A[i][e];

        if (l == -1) /*ilimitado*/
            return VT();

        pivot(k, l, e);
    }

    res.resize(k, 0);

    for (int i = 0; i < m; ++i)
        res[kt[i]] = b[i];

    return res;
}

VT simplex (vector<VT> &AA, VT &bb, VT &cc)
{
    int n = AA[0].size(), k;
    m = AA.size();
    k = n + m + 1;
    kt.resize(m);
    b = bb;
    c = cc;
    c.resize(n + m);
    A = AA;

    for (int i = 0; i < m; ++i)
    {
        A[i].resize(k);
        A[i][n + i] = 1;
        A[i][k - 1] = -1;
        kt[i] = n + i;
    }

    N = VI(k, 1);

    for (int i = 0; i < m; ++i)
        N[kt[i]] = 0;

    int pos = min_element(b.begin(), b.end()) - b.begin();

    if (b[pos] < -EPS)
    {
        c = VT(k,0);
        c[k - 1] = -1;
        pivot(k, pos, k - 1);
        res = doit(k);

        if (res[k - 1] > EPS) /*impossivel*/
            return VT();

        for (int i = 0; i < m; ++i)
            if (kt[i] == k - 1)
                for (int j = 0; i < k - 1; ++j)
                    if (N[j] && (A[i][j] < -EPS || EPS < A[i][j]))
                    {
                        pivot(k, i, j);
                        break;
                    }

        c = cc;
        c.resize(k, 0);

        for (int i = 0; i < m; ++i)
            for (int j = 0; i < k; ++j)
                if (N[j])
                    c[j] -= c[kt[i]] * A[i][j];
    }

    res = doit(k - 1);

    if (!res.empty())
        res.resize(n);

    return res;
}

/*
int main()
{
    int m = 2; //numero de linhas do sistema
    int n = 2; //numero de colunas do sistema
    vector <VT> A(m, VT(n));
    VT b(m), c(n), res;
    A[0][0] = 1;
    A[0][1] = 1;
    b[0]= 4;
    A[1][0] = 2;
    A[1][1] = 1;
    b[1]= 5;
    c[0] = 3;
    c[1] = 4;

    res = simplex (A, b, c);

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";

    double maximum = 0;

    for (int i = 0; i < res.size(); ++i)
        maximum += res[i] * c[i];

    cout << endl << maximum << endl;

    return 0;
}*/

int main()
{

}
