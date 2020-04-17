#include <stdio.h>
#include <string.h>
#include <queue>
#define MAXN 1000
#define MAXM 100000

using namespace std;

/*

    GOMORY-HU TREE

    Aplicacoes:

        Max-Flow/Min-Cut entre todos os vertices do grafo.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Chamar a funcao d_init()

        3) Adicionar as arestas no grafo chamando:

            d_edge(s, t, capacity), onde:

                s: Vertice de origem
                t: Vertice de destino
                capacity: Capacidade da aresta

        4) Chamar a funcao gomory_hu()

    Resultado da funcao:

        A funcao gomory_hu() armazena em ans[][] a matriz
        de adjacencias que contem o max-flow/min-cut entre
        todos os vertices do grafo.

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        UVA 11549
        UVA 11603

    Adicionado por:

        Jorge Gabriel Siqueira

*/


int last_edge[MAXN], cur_edge[MAXN], dist[MAXN];
int prev_edge[MAXM], cap[MAXM], flow[MAXM], adj[MAXM];
int up[MAXN], val[MAXN];
bool cut[MAXN];
int nedges;
int ans[MAXN][MAXN];
int n;

void d_init ()
{
    nedges = 0;
    memset(last_edge, -1, sizeof last_edge);
}

void d_edge (int v, int w, int capacity, bool r = false)
{
    prev_edge[nedges] = last_edge[v];
    cap[nedges] = capacity;
    adj[nedges] = w;
    flow[nedges] = 0;
    last_edge[v] = nedges++;
    if (!r)
        d_edge(w, v, 0, true);
}

bool d_auxflow (int source, int sink)
{
    queue<int> q;
    q.push(source);
    memcpy(cur_edge, last_edge, sizeof last_edge);
    memset(dist, -1, sizeof dist);
    dist[source] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = last_edge[v]; i != -1; i = prev_edge[i])
        {
            if (cap[i] - flow[i] == 0)
                continue;
            if (dist[adj[i]] == -1)
            {
                dist[adj[i]] = dist[v] + 1;
                q.push(adj[i]);
                if (adj[i] == sink)
                    return true;
            }
        }
    }
    return false;
}

int d_augmenting (int v, int sink, int c)
{
    if (v == sink)
        return c;
    for (int& i = cur_edge[v]; i != -1; i = prev_edge[i])
    {
        if (cap[i] - flow[i] == 0 || dist[adj[i]] != dist[v] + 1)
            continue;
        int val;
        if (val = d_augmenting(adj[i], sink, min(c, cap[i] - flow[i])))
        {
            flow[i] += val;
            flow[i^1] -= val;
            return val;
        }
    }
    return 0;
}

int dinic (int source, int sink)
{
    int ret = 0;
    while (d_auxflow(source, sink))
    {
        int flow;
        while (flow = d_augmenting(source, sink, 0x3f3f3f3f))
            ret += flow;
    }
    return ret;
}

int mincut (int s, int t)
{
    memset(flow, 0, sizeof flow);
    memset(cut, 0, sizeof cut);
    int ret = dinic(s, t);
    queue <int> q;
    q.push(s);
    cut[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = last_edge[v]; i != -1; i = prev_edge[i])
        {
            int w = adj[i];
            if (cap[i] - flow[i] && !cut[w])
                cut[w] = true, q.push(w);
        }
    }
    return ret;
}

void gomory_hu ()
{
    memset(up, 0, sizeof up);
    memset(ans, 0x3f3f3f3f, sizeof ans);
    for (int i = 1; i < n; ++i)
    {
        val[i] = mincut(i, up[i]);
        for (int j = i+1; j < n; ++j)
            if (cut[j] && up[j] == up[i])
                up[j] = i;
        ans[i][up[i]] = ans[up[i]][i]=val[i];
        for (int j = 0; j < i; ++j)
            ans[i][j] = ans[j][i] = min(val[i], ans[up[i]][j]);
    }
}

int main()
{
    return 0;
}
