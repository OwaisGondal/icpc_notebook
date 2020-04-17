#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1000
#define MAXM 2000000

using namespace std;

/*

    KRUSKAL MINIMUM SPANNING FOREST

    Aplicacoes:

        Floresta geradora minima em grafos esparsos
        nao direcionados.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Armazenar em m o numero de arestas do grafo

        3) Armazenar em edges[] as arestas do grafo

            edge.s -> vertice de origem da aresta
            edge.t -> vertice de destino da aresta
            edge.w -> peso da aresta

        4) Chamar a funcao kruskal()

    Resultado da funcao:

        A funcao armazena em result o custo da floresta
        geradora minima e armazena em pa[] o vetor de
        predecessores dos vertices.

    Complexidade do algoritmo:

        O(m(log(m)))

    Problemas resolvidos:

        CIPO (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/


struct edge
{
    int s, t, w;
    bool operator < (const edge& e) const
    {
        return w < e.w;
    }
};

edge edges[MAXM]; //lista de arestas do grafo
int pa[MAXN], comp_sz[MAXN];
int n, m; //numero de vertices e arestas do grafo

long long int kruskal()
{
    int u, v;
    long long int result = 0;
    edge e;
    for (int i = 0; i < n; ++i)
    {
        comp_sz[i] = 1;
        pa[i] = i;
    }
    sort (edges, edges+m); //ordenar em tempo linear, se possivel!!!
    for (int i = 0, k = 0; i < m && k < n - 1; ++i)
    {
        e = edges[i];
        //union-find
        for (u = e.s; u != pa[u]; u = pa[u]);
        for (v = e.t; v != pa[v]; v = pa[v]);
        if (u == v) //se a aresta gera um ciclo
            continue;
        if (comp_sz[u] < comp_sz[v])
        {
            pa[u] = v;
            comp_sz[v] += comp_sz[u];
        }
        else
        {
            pa[v] = u;
            comp_sz[u] += comp_sz[v];
        }
        result += e.w;
        ++k;
    }
    return result;
}

int main()
{
    return 0;
}
