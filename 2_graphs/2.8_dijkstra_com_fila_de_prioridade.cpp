#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

#define INF 0x3F3F3F3F
#define MAXN 1000

using namespace std;

/*

    DIJKSTRA'S ALGORITHM WITH PRIORITY QUEUE

    Aplicacoes:

        Menor caminho em grafos esparsos SEM ARESTAS
        NEGATIVAS!!!

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Armazenar o grafo em forma de lista de adjacencias
           no vector graph[]. Em cada pair<int,int>, representando
           uma aresta, armazenar da seguinte forma:

                graph[i][j].first -> distancia da aresta que liga
                o vertice i ao vertice graph[i][j].second.

        3) Chamar a funcao dijkstra (s,t) onde s eh o vertice
           o origem da busca e t eh o vertice destino da busca.
           Se a intencao for realizar uma busca completa
           deve-se passar o valor -1 no parametro t.

    Resultado da funcao:

        A funcao armazena em dist[]: dist[i] a distancia
        de s (source) ate i. A funcao retorna a distancia
        do vertice s ao vertice t.

    Complexidade do algoritmo:

        O((n+m)log(n))

    Problemas resolvidos:


    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector <pair <int, int> > graph[MAXN];
int dist[MAXN];
int n;

struct ltDist
{
    bool operator() (int u, int v) const
    {
        return make_pair(dist[u], u) < make_pair(dist[v], v);
    }
};

int dijkstra (int s, int t)
{
    memset (dist, INF, sizeof(int)*n);
    dist[s] = 0;
    set <int, ltDist> q;
    q.insert(s);
    while(!q.empty())
    {
        int u = *q.begin();
        q.erase(q.begin());
        for (int v = 0; v < graph[u].size(); ++v)
        {
            int newDist = dist[u] + graph[u][v].first;
            if (newDist < dist[graph[u][v].second])
            {
                if (q.count (graph[u][v].second))
                    q.erase (graph[u][v].second);
                dist[graph[u][v].second] = newDist;
                q.insert (graph[u][v].second);
            }
        }
    }
    return dist[t];
}

int main()
{
    return 0;
}
