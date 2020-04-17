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

#define MAXSZ 100

using namespace std;

/*

    SUBSTITUIR NA PRIMEIRA OCORRENCIA

    Aplicacoes:

        Substitui a primeira ocorrencia de um padrao em
        uma string.

    Como chamar a funcao:

        1) Chamar a funcao replace(s,f,t), onde:

            string s -> string original
            string f -> string a ser buscada em s
            string t -> string que sera substituida
                        no lugar de f

    Resultado da funcao:

        A funcao retorna uma string com a primeira
        ocorrencias de f em s substituidas por t

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS)
{
    return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

string replace(string s, string f, string t)
{
    string r;
    int p = s.find(f);

    if (p != s.npos)
    {
        r += s.substr(0, p) + t;
        s = s.substr(p + f.size());
    }

    return r + s;
}

int main()
{
    return 0;
}
