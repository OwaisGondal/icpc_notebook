#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

/*

    MINIMUM STEINER TREE

    Aplicacoes:

        Determinar uma arvore de custo total minimo que
        interonecte um conjunto de vertices de um grafo.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Chamar a funcao initialize()

        3) Armazenar em T os vertices que a arvore deve possuir

        4) Preencher a matriz de adjacencias (g[][]) com as
           informacoes referentes ao grafo.

        6) Chamar a funcao minimum_steiner_tree();

    Resultado da funcao:

        A funcao retorna o custo da arvore minima que interconecta
        os vertices em T

    Complexidade do algoritmo:

        O(n*log(n))

    Problemas resolvidos:

        AIZU ONLINE JUDGE 1040

    Adicionado por:

        Jorge Gabriel Siqueira

*/

typedef vector< vector<int> > matrix;

int n;
matrix g;
vector<int> T;

void initialize()
{
    g = matrix(n, vector<int>(n,INF));
    T.clear();
}

int minimum_steiner_tree()
{
    const int numT = T.size();

    if (numT <= 1) return 0;

    matrix d(g); // all-pair shortest

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

    int OPT[(1 << numT)][n];

    for (int S = 0; S < (1 << numT); ++S)
        for (int x = 0; x < n; ++x)
            OPT[S][x] = INF;

    for (int p = 0; p < numT; ++p) // trivial case
        for (int q = 0; q < n; ++q)
            OPT[1 << p][q] = d[T[p]][q];

    for (int S = 1; S < (1 << numT); ++S)   // DP step
    {
        if (!(S & (S-1))) continue;
        for (int p = 0; p < n; ++p)
            for (int E = 0; E < S; ++E)
                if ((E | S) == S)
                    OPT[S][p] = min( OPT[S][p], OPT[E][p] + OPT[S-E][p] );

        for (int p = 0; p < n; ++p)
            for (int q = 0; q < n; ++q)
                OPT[S][p] = min( OPT[S][p], OPT[S][q] + d[p][q] );
    }

    int ans = INF;

    for (int S = 0; S < (1 << numT); ++S)
        for (int q = 0; q < n; ++q)
            ans = min(ans, OPT[S][q] + OPT[((1 << numT)-1)-S][q]);

    return ans;
}

int main()
{
    return 0;
}
