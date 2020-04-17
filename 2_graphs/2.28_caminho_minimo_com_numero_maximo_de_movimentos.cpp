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

#define INF 0x3f3f3f3f

#define MAXSZ 1000
#define MAX 300
#define MAXE 100000

using namespace std;

/*

    SHORTEST PATH LIMITED NUMBER OF MOVES

    Aplicacoes:

        Calcular o caminho minimo (se o grafo for aciclico
        pode-se calcular o caminho maximo multiplicando os
        custos por -1) com numero maximo de movimentos

    Como chamar a funcao:

        1) Armazenar em:

            n: O numero de vertices do grafo
            m: O numero de arestas do grafo
            t: O numero maximo de movimentos permitidos

        2) Chamar a funcao inicializaGrafo(n)

        3) Preencher os grafos com as arestas chamando:

            insereAresta(s,t,cst), onde:

                s: Vertice de origem
                t: Vertice de destino
                cst: Peso da aresta

        4) Chamar a funcao SPLNM(s), onde s eh o
           vertice de origem da busca

    Resultado da funcao:

        A funcao armazena em dist[]: dist[i] a distancia
        minima dovertice s ao vertice i

    Complexidade do algoritmo:

        O(n*m)

    Problemas resolvidos:

        INCIDENT (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int n, t, m;

typedef struct edge
{
    int s, t;
} edge;

int nEdges;
edge edges[MAXE];
int graph[MAX][MAX];
int dist[MAX];
int nVertices;
int nVezes[MAX];

void inicializaGrafo(int n_)
{
    memset(graph,INF,sizeof(graph));
    nEdges = 0;
    nVertices = n_;
}

void insereAresta(int s, int t, int cst)
{
    graph[s][t] = cst;

    edge temp;
    temp.s = s;
    temp.t = t;

    edges[nEdges] = temp;
    nEdges++;
}

void SPLNM(int s)
{
    int k, j;

    memset(dist, INF, sizeof(dist));
    memset(nVezes, 0, sizeof(nVezes));
    dist[s] = 0;

    for (k = 0; k < nVertices-1; ++k)
    {
        for (j = 0; j < nEdges; ++j)
        {
            int u = edges[j].s;
            int v = edges[j].t;

            if (dist[u] < INF && dist[v] > dist[u] + graph[u][v])
            {
                if(nVezes[u] + 1 <= t)
                {
                    dist[v] = dist[u] + graph[u][v];
                    nVezes[v] = nVezes[u] + 1;
                }
            }
        }
    }
}

int main()
{
    return 0;
}
