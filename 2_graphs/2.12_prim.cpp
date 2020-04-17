#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MAXN 500

using namespace std;

/*

    PRIM'S MINIMUM SPANNING TREE ALGORITHM

    Aplicacoes:

        Arvore geradora minima em grafos densos
        nao-direcionados

    Como chamar a funcao:

        1) Preencher a matriz de adjacencias com INF

            memset(graph, INF, sizeof(graph));

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao prim()

    Resultado da funcao:

        A funcao retorna o custo da arvore geradora
        minima. A funcao armazena em pa[] o vetor de
        predecessores

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:

        RMAPA11 (SPOJ BR)
        REDOTICA (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/


int graph[MAXN][MAXN];
int tree[MAXN], dist[MAXN];
int pa[MAXN];
int n;

int prim ()
{
    int v0, cost = 0;
    for (int i = 1; i < n; ++i)
    {
        pa[i] = -1;
        tree[i] = 0;
        dist[i] = graph[0][i];
    }
    pa[0] = 0;
    while (1)
    {
        int mincost = INF;
        for (int i = 0; i < n; ++i)
            if (pa[i] == -1 && mincost > dist[i])
                mincost = dist[v0 = i];
        if (mincost == INF)
            break;
        pa[v0] = tree[v0];
        cost += mincost;
        for (int i = 0; i < n; ++i)
            if (pa[i] == -1 && dist[i] > graph[v0][i])
            {
                dist[i] = graph[v0][i];
                tree[i] = v0;
            }
    }
    return cost;
}

int main()
{
    return 0;
}
