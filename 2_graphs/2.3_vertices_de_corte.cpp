#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#define MAXN 400

using namespace std;

/*

    ARTICULATION POINTS DETECTION ALGORITHM

    Aplicacoes:

        Deteccao dos pontos de articulacao (vertices de corte)
        de um grafo. Um ponto de articulacao eh um vertice
        que quando removido do grafo o torna desconexo.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Armazenar o grafo em forma de lista de adjacencias
           no vector graph[]

        3) Verificar se o grafo eh, inicialmente, conexo.

        4) Chamar a funcao get_articulacoes()

    Resultado da funcao:

        A funcao armazena em set<int> articulacoes os
        vertices de corte do grafo.

    Complexidade do algoritmo:

        O(m+n), onde m eh a quantidade de arestas do grafo

    Problemas resolvidos:

        MANUT (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector <int> graph [MAXN];
set <int> articulacoes;
int time_s, visitado[MAXN];
int n;

int dfs (int u)
{
    int menor = visitado[u] = time_s++;
    int filhos = 0;
    int k = graph[u].size();
    for (int i = 0; i < k; ++i)
    {
        if (!visitado[graph[u][i]])
        {
            filhos++;
            int m = dfs(graph[u][i]);
            menor = min(menor, m);
            if (visitado[u] <= m && (u != 0 || filhos >= 2))
            {
                articulacoes.insert(u);
            }
        }
        else
        {
            menor = min(menor, visitado[graph[u][i]]);
        }
    }
    return menor;
}

void get_articulacoes()
{
    time_s = 1;
    articulacoes.clear();
    memset (visitado, 0, sizeof(int)*n);
    dfs (0);
}

int main()
{
    return 0;
}
