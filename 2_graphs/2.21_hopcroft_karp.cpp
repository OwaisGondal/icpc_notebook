#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#define MAXN1 50000
#define MAXN2 50000
#define MAXM 150000

using namespace std;

/*

    HOPCROFT KARP MAXIMUM BIPARTITE MATCHING

    Aplicacoes:

        Maximum bipartite matching de forma eficiente.

    Como chamar a funcao:

        1) Chamar a funcao init(_n1,_n2), onde _n1 eh o numero
           de vertices do lado esquerdo do grafo e _n2 eh o numero
           de vertices do lado direito do grafo.

        2) Adicionar as arestas que ligam o lado esquerdo ao lado
           direito chamando a funcao void addEdge(u,v), onde u
           eh o vertice do lado esquerdo do grafo e v eh o vertice
           do lado direito do grafo.

        3) Chamar a funcao maxMatching()

    Resultado da funcao:

        A funcao maxMatching() retorna o matching maximo no grafo.

        matching[]: matching[i] -> armazena o par da esquerda do
        vertice i (da direita, obviamente)

    Complexidade do algoritmo:

        O(sqrt(n) * m)

    Problemas resolvidos:

        ENGENHAR (SPOJ BR)
        URI 1208
        URI 1056
        URI 1330
        Live Archive 6525

    Adicionado por:

        Jorge Gabriel SIqueira

*/

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2)
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v)
{
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}

void bfs()
{
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u)
    {
        if (!used[u])
        {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++)
    {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prev[e])
        {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0)
            {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1)
{
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prev[e])
    {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))
        {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching()
{
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;)
    {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

int main()
{
    return 0;
}
