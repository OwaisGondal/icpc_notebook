#include <stdio.h>
#include <string.h>
#include <queue>
#define MAXN 1001
#define INF 0x3F3F3F3F

using namespace std;

/*

    BREADTH-FIRST SEARCH (BFS)

    Aplicacoes:

        Menor caminho em grafos sem peso
        Verificar se um grafo eh bipartido
        Verificar se um grafo eh bicoloravel
        Alcancabilidade
        Conectividade
        Etc.

    Como chamar a funcao:

        1) Zerar a matriz de adjacencias (graph[][])

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao bfs(s), onde s eh o vertice
           de origem da busca.

    Resultado da funcao:

        A funcao armazena no vetor dist[] a distancia
        do vertice s ate o vertice i, se dist[i] == INF
        o vertice s nao pode alcancar o vertice i

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:

        MESA (SPOJ BR)
        MOEDAS (SPOJ BR)
        DUENDE (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

bool graph[MAXN][MAXN];
int dist[MAXN];
int n;

void bfs (int s)
{
    memset (dist, INF, sizeof(int)*n);
    dist[s] = 0;
    queue <int> q;
    q.push (s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v)
        {
            if (dist[v] == INF && graph[u][v])
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    return 0;
}
