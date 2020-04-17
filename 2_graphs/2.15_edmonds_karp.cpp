#include <stdio.h>
#include <string.h>
#include <iostream>
#define INF 0x3F3F3F3F
#define NMAX 100

using namespace std;

/*

    EDMONDS KARP MIN CUT - MAX FLOW

    Aplicacoes:

        Fluxo maximo de custo minimo em grafos.

    Como chamar a funcao:

        1) Zerar a matriz de fluxo (cap[][])

        2) Preencher a matriz de custo cost[][] com INF

        3) Armazenar nas variaveis:

            n: Numero de vertices do grafo
            source: Origem do fluxo
            sink: Destino do fluxo

        4) Preencher a matriz de fluxo e de custo com as
           informacoes referentes ao grafo.

        5) Usar o dijkstra mais recomendado para o grafo
           em questao.

        6) Chamar a funcao mincost_maxflow()

    Resultado da funcao:

        A funcao mincost_maxflow() retorna um pair<long long, long long>:
            first: Custo minimo
            second: Fluxo maximo

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        FUTURE (SPOJ BR)
        UVA 10594

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int cap[NMAX][NMAX], cost[NMAX][NMAX]; //capacidades e custos: vertices de 0 a n-1
int adj[NMAX][NMAX], fnet[NMAX][NMAX], deg[NMAX], par[NMAX], d[NMAX], pi[NMAX];
int n, source, sink; //numero de vertices, origem e destino do fluxo

//Dijkstra para grafos densos
bool dijkstra (int s, int t)
{
    for (int i = 0; i < n; ++i)
        d[i] = INF, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;
    while (1)
    {
        int u = -1, bestD = INF;
        for (int i = 0; i < n; ++i)
            if(par[i] < 0 && d[i] < bestD)
                bestD = d[u = i];
        if (bestD == INF)
            break;
        par[u] = -par[u] - 1;
        for (int i = 0; i < deg[u]; ++i)
        {
            int v = adj[u][i];
            if (par[v] >= 0)
                continue;
            if (fnet[v][u] && d[v] > d[u] + pi[u] - pi[v] - cost[v][u])
            {
                d[v] = d[u] + pi[u] - pi[v] - cost[v][u];
                par[v] = -u - 1;
            }
            if (fnet[u][v] < cap[u][v] && d[v] > d[u] + pi[u] - pi[v] + cost[u][v])
            {
                d[v] = d[u] + pi[u] - pi[v] + cost[u][v];
                par[v] = -u - 1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (pi[i] < INF)
            pi[i] += d[i];
    return par[t] >= 0;
}



//Dijkstra para grafos esparsos
#define BUBL { \
t = q[i]; q[i] = q[j]; q[j] = t; \
t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }
int q[NMAX], inq[NMAX], qs;
bool dijkstra (int s, int t)
{
    memset (d, INF, sizeof(d));
    memset (par, -1, sizeof(par));
    memset (inq, -1, sizeof(inq));
    d[s] = qs = 0;
    inq[q[qs++] = s] = 0;
    par[s] = n;
    while (qs)
    {
        int u = q[0];
        inq[u] = -1;
        q[0] = q[--qs];
        if (qs) inq[q[0]] = 0;
        for (int i = 0, j = 2*i + 1, t; j < qs; i = j, j = 2*i + 1)
        {
            if (j + 1 < qs && d[q[j + 1]] < d[q[j]])
                ++j;
            if (d[q[j]] >= d[q[i]])
                break;
            BUBL;
        }
        for (int k = 0, v = adj[u][k]; k < deg[u]; v = adj[u][++k])
        {
            if (fnet[v][u] && d[v] > d[u] + pi[u] - pi[v] - cost[v][u])
                d[v] = d[u] + pi[u] - pi[v] - cost[v][par[v] = u];
            if (fnet[u][v] < cap[u][v] && d[v] > d[u] + pi[u] - pi[v] + cost[u][v])
                d[v] = d[u] + pi[u] - pi[v] + cost[par[v] = u][v];
            if (par[v] == u)
            {
                if(inq[v] < 0)
                {
                    inq[q[qs] = v] = qs;
                    qs++;
                }
                for (int i = inq[v], j = (i - 1)/2, t;
                        d[q[i]] < d[q[j]]; i = j, j = (i - 1)/2)
                    BUBL;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (pi[i] < INF)
            pi[i] += d[i];
    return par[t] >= 0;
}

pair <long long int, long long int> mincost_maxflow()
{
    memset (deg, 0, sizeof(deg));
    memset (fnet, 0, sizeof(fnet));
    memset (pi, 0, sizeof(pi));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (cap[i][j] || cap[j][i])
                adj[i][deg[i]++] = j;
    long long int flow = 0, fcost = 0;
    while (dijkstra (source, sink))
    {
        int bot = INF;
        for (int v = sink, u = par[v]; v != source; u = par[v = u])
            bot = min (bot, fnet[v][u] ? fnet[v][u] : (cap[u][v]-fnet[u][v]));
        for (int v = sink, u = par[v]; v != source; u = par[v = u])
            if(fnet[v][u])
            {
                fnet[v][u] -= bot;
                fcost -= (long long int) (bot * cost[v][u]);
            }
            else
            {
                fnet[u][v] += bot;
                fcost += (long long int) (bot * cost[u][v]);
            }
        flow += (long long int) bot;
    }
    return make_pair (fcost,flow);
}

int main()
{
    return 0;
}
