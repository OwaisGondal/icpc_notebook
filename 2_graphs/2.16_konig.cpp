#include <stdio.h>
#include <string.h>
#define MAXN 100
#define MAXM 100

using namespace std;

/*

    KONIG MAXIMUM BIPARTITE MATCHING

    Aplicacoes:

        Maximum bipartite matching.

    Como chamar a funcao:

        1) Zerar a matriz de adjacencias (graph[][])

        2) Armazenar em m o numero de vertices do lado
           esquerdo do grafo e em n o numero de vertices
           do lado direito do grafo.

        3) Adicionar as arestas que ligam o lado esquerdo
           ao lado direito chamando fazendo:

                graph[u][v] = true;

           onde u eh o vertice do lado esquerdo do grafo
           e v eh o vertice do lado direito do grafo.

        4) Chamar a funcao bpm()

    Resultado da funcao:

        A funcao bpm() retorna o numero maximo de
        casamentos possiveis.

        A funcao armazena em matchL[]: matchL[m] o
        indice do vertice do conjunto da direita ao
        qual o vertice m da esquerda se liga (-1 se nao existir)

        A funcao armazena em matchR[]: matchR[n] o
        indice do vertice do conjunto da esquerda ao
        qual o vertice n da direita se liga (-1 se nao existir)

    Complexidade do algoritmo:

        O(n^2 * m)

    Problemas resolvidos:

        ENGENHAR (SPOJ BR)
        URI 1208
        URI 1056

    Adicionado por:

        Jorge Gabriel Siqueira

*/

bool graph[MAXM][MAXN];
bool seen[MAXN];
int matchL[MAXM], matchR[MAXN];
int n, m;

bool dfs (int u)
{
    for (int v = 0; v < n; ++v)
        if (graph[u][v])
        {
            if (seen[v])
                continue;
            seen[v] = true;
            if (matchR[v] < 0 || dfs(matchR[v]))
            {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
    return false;
}

int bpm ()
{
    memset (matchL, -1, sizeof(matchL));
    memset (matchR, -1, sizeof(matchR));
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        memset (seen, 0, sizeof(seen));
        if (dfs (i))
            ++cnt;
    }
    return cnt;
}

int main()
{
    return 0;
}
