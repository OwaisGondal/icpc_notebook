#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 10000

using namespace std;

/*

    BRIDGE DETECTION ALGORITHM

    Aplicacoes:

        Deteccao das pontes de um grafo.
        Uma ponte eh uma aresta que quando removida
        do grafo o torna desconexo, ou seja, o numero
        de componentes conexas do grafo aumenta com
        a remocao da aresta.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Armazenar o grafo em forma de lista de adjacencias
           no vector graph[]

        3) Chamar a funcao get_pontes()

        Observacao: Uma aresta eh uma ponte se, e somente se,
        a mesma nao estiver contida em um ciclo. Um grafo
        com n vertices pode ter no maximo n-1 pontes, ja
        que a adicao de uma aresta adicional criaria um ciclo.
        Se nao houver nenhum ciclo entre os vertices u e v,
        entao existe apenas um caminho entre estes dois vertices.

    Resultado da funcao:

        a funcao armazena em vector< pair<int,int> > pontes
        as arestas pontes do grafo

    Complexidade do algoritmo:

        O (n+m)

    Problemas resolvidos:

        HEDGE11 (SPOJ BR)
        TUBOS (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector <int> graph[MAXN];
vector <pair <int, int> > pontes;
int time_s, visitado[MAXN];
int n;

int dfs(int u, int pai)
{
    int menor = visitado[u] = time_s++;
    int filhos = 0;
    int k = graph[u].size();
    for (int i = 0; i < k; ++i)
    {
        if (!visitado[graph[u][i]])
        {
            ++filhos;
            int m = dfs (graph[u][i], u);
            menor = min (menor,m);
            if (visitado[u] < m)
                pontes.push_back (make_pair(u, graph[u][i]));
        }
        else if (graph[u][i] != pai)
        {
            menor = min(menor, visitado[graph[u][i]]);
        }
    }
    return menor;
}

void get_pontes()
{
    pontes.clear();
    time_s = 1;
    memset (visitado, 0, sizeof(int)*n);
    dfs (0,-1);
}

int main()
{
    return 0;
}
