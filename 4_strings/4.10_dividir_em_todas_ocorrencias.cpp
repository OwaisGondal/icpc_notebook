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

    DIVIDIR EM TODAS OCORRENCIAS

    Aplicacoes:

        Divide uma string em todas as ocorrencias
        de um padrao

    Como chamar a funcao:

        1) Chamar a funcao splitAll(s,t), onde:

            string s -> string original
            string t -> string a ser buscada em s

    Resultado da funcao:

        A funcao retorna um vector<string>
        contendo a string s quebrada em todas
        as ocorencias de t.

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

vector<string> splitAll(string s, string t)
{
    vector<string> v;

    for (int p = 0; (p = s.find(t)) != s.npos; )
    {
        v.push_back(s.substr(0, p));
        s = s.substr(p + t.size());
    }

    v.push_back(s);

    return v;
}

int main()
{
    return 0;
}
