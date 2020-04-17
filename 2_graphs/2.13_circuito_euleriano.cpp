#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#define INF 0x3F3F3F3F
#define MAXN 1000

using namespace std;

/*

    EULERIAN CIRCUIT

    Aplicacoes:

        Determinar um caminho euleriano em um grafo nao-direcionado.

    Como chamar a funcao:

        1) Preencher a matriz de adjacencias com INF

            memset(graph, INF, sizeof(graph));

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao print_eulerian_circuit()

        Obs.:

        Um caminho euleriano eh um caminho que visita cada aresta do
        grafo uma unica vez.

        Um grafo possui um caminho euleriano se e somente ele eh conexo
        e possui 2 vertices de grau impar. Se o grafo for conexo e nao
        possuir nenhum vertice de grau impar, entao tem-se um circuito
        euleriano (um caminho que inicia e termina no mesmo vertice).

    Resultado da funcao:

        A funcao imprime o circuito euleriano do grafo

        Obs.: Verifique antes se o grafo satisfaz as restricoes
        propostas em 4

    Complexidade do algoritmo:

        O(n)

    Problemas resolvidos:

        OBIDOMIN (SPOJ BR)
        UVA 10054

    Adicionado por:

        Jorge Gabriel Siqueira

*/


int graph[MAXN][MAXN];
int g[MAXN][MAXN];
int n;

void dfs (int v, vector<int>& path)
{
    for (int i = 0; i < n; ++i)
        if(g[v][i] != INF)
        {
            g[v][i] = INF;
            //g[i][v] = INF -> caso o grafo seja nao-direcionado!
            dfs(i, path);
        }
    path.push_back(v);
}

void print_eulerian_circuit ()
{
    memcpy (g, graph, sizeof(graph));
    vector <int> path;
    dfs(0, path);
    for (int i = 0; i < path.size() - 1; ++i)
        cout << path[i] << ' ' << path[i + 1] << endl;
}

int main()
{
    return 0;
}
