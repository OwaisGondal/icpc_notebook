#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3F3F3F3F
#define MAXN 150

using namespace std;

/*

    BELLMAN-FORD (SINGLE-SOURCE SHORTEST PATH)

    Aplicacoes:

        Menor caminho em grafos com arestas negativas,
        maior caminho em digrafo aciclico (adicionar os
        custos das arestas com sinal invertido)

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Zerar a matriz de adjacencias (graph) e
           limpar o vetor de arestas (edges.clean())

        3) Armazenar o grafo na matriz de adjacencias e
           nao se esquecer de tambem adicionar as arestas
           no vetor edges. Cada pair<int,int> em edges deve
           representar uma aresta que liga first em second

        4) Chamar a funcao bellman_ford(s) onde s eh o
           vertice de origem (source) da busca.

    Resultado da funcao:

        A funcao armazena em dist[]: dist[i] a distancia
        de s (source) ate i. A funcao retorna false se o
        grafo possui ciclos negativos ou true caso contrario.

    Complexidade do algoritmo:

        O(n*m), onde m eh o numero de arestas do grafo

    Problemas resolvidos:

        INCIDENT (SPOJ BR)
        PASSEIO (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector <pair<int, int> > edges; //lista de arestas do grafo (vertices de 0 a n-1)
int graph[MAXN][MAXN]; //matriz de adjacencia (custos): vertices de 0 a n-1
int dist[MAXN]; //distancia de s (source) ate os demais vertices alcancaveis
int n; //numero de vertices do grafo

bool bellman_ford (int s)
{
    int m = edges.size();
    memset (dist, INF, sizeof(int)*n);
    dist[s] = 0;
    for (int k = 0; k < n-1; ++k)
    {
        for (int j = 0; j < m; ++j)
        {
            int u = edges[j].first;
            int v = edges[j].second;
            if (dist[u] < INF && dist[v] > dist[u] + graph[u][v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    //detecta ciclos negativos
    for (int j = 0; j < m; ++j)
    {
        int u = edges[j].first, v = edges[j].second;
        if (dist[u] < INF && dist[v] > dist[u] + graph[u][v])
            return false;
    }
    return true;
}

int main()
{
    return 0;
}
