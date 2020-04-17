#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 400

using namespace std;

/*

    ARTICULATION POINTS AND BRIDGES DETECTION ALGORITHM

    Aplicacoes:

        Deteccao de pontes e pontos de articulacao
        simultaneamente.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Armazenar o grafo em forma de lista de adjacencias
           no vector graph[]

        3) Chamar a funcao articulations_and_bridges()

    Resultado da funcao:

        A funcao armazena em vector<int> articulacoes os
        vertices de corte do grafo e em
        vector< pair<int,int> > pontes as arestas pontes
        do grafo.

    Complexidade do algoritmo:

        O(n+m) onde m eh o numero de arestas do grafo

    Problemas resolvidos:

        MANUT (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector <int> graph[MAXN];
vector <int> articulacoes;
vector <pair <int, int> > pontes;
bool visited[MAXN];
int timer, d[MAXN], lowpt[MAXN], pi[MAXN];
int n;

void dfs (int u)
{
    int sons = 0, v;
    bool art = false;
    visited[u] = true;
    lowpt[u] = d[u] = timer++;
    int k = graph[u].size();
    for (int i = 0; i < k; ++i)
    {
        v = graph[u][i];
        if (!visited[ graph[u][i]])
        {
            ++sons;
            pi[v] = u;
            dfs(v);
            lowpt[u] = min (lowpt[u], lowpt[v]);
            if ((pi[u] != -1) && (lowpt[v] >= d[u]))
                art = true;
            if (lowpt[v] > d[u])
                pontes.push_back(make_pair(u,v));
        }
        else if (v!= pi[u])
            lowpt[u] = min (lowpt[u], d[v]);
    }
    if (art)
        articulacoes.push_back(u);
    else if (pi[u] == -1 && sons > 1)
        articulacoes.push_back(u);
}

void articulations_and_bridges()
{
    memset (visited, 0, sizeof(visited));
    memset (pi, -1, sizeof(pi));
    articulacoes.clear();
    pontes.clear();
    timer = 0;
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i);
}

int main()
{
    return 0;
}
