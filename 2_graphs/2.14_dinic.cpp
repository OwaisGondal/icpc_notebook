#include <stdio.h>
#include <string.h>
#include <vector>
#define INF 0x3F3F3F3F
#define MAXN 200

using namespace std;

/*

    DINIC MAX FLOW ALGORITHM

    Aplicacoes:

        Fluxo maximo entre dois vertices de um grafo,
        valor do corte minimo entre dois vertices de
        um grafo (max flow = weight of min cut).

    Como chamar a funcao:

        1) Zerar a matriz de adjacencias (cap[][])

        2) Armazenar nas variaveis:

            n: Numero de vertices do grafo
            source: Origem do fluxo
            sink: Destino do fluxo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao maxflow()

    Resultado da funcao:

        A funcao maxflow() retorna um inteiro referente ao
        fluxo maximo do grafo.

    Complexidade do algoritmo:

        O(n^2 * m)

    Problemas resolvidos:

        CAVALOS (SPOJ BR)
        ENGENHAR (SPOJ BR)
        POTHOLE (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int cap[MAXN][MAXN]; //matriz de adjacencia (capacidades): vertices de 0 a n-1;
vector <int> adj[MAXN];
int q[MAXN], prev[MAXN];
int n, source, sink; //numero de vertices, origem e destino do fluxo

int dinic ()
{
    int flow = 0;
    while (1)
    {
        memset (prev, -1, sizeof(int)*n);
        int qf = 0, qb = 0;
        prev[q[qb++] = source] = -2;
        while (qb > qf && prev[sink] == -1)
        {
            for (int u = q[qf++], m = adj[u].size(), i = 0, v; i < m; ++i)
                if (prev[v = adj[u][i]] == -1 && cap[u][v])
                    prev[q[qb++] = v] = u;
        }
        if (prev[sink] == -1)
            break;
        for (int z = 0; z < n; ++z)
            if (cap[z][sink] && prev[z] != -1)
            {
                int bot = cap[z][sink];
                for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                    bot = min (bot, cap[u][v]);
                if (!bot)
                    continue;
                cap[z][sink] -= bot;
                cap[sink][z] += bot;
                for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                {
                    cap[u][v] -= bot;
                    cap[v][u] += bot;
                }
                flow += bot;
            }
    }
    return flow;
}

int maxflow ()
{
    for (int i = 0; i < n; ++i)
        adj[i].clear();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if(cap[i][j] || cap[j][i])
                adj[i].push_back (j);
    return dinic();
}

int main()
{
    return 0;
}

