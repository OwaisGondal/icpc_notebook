#include <stdio.h>
#define MAXN 1001

using namespace std;

/*

    DEPTH-FIRST SEARCH (DFS)

    Aplicacoes:

        Deteccao de ciclos
        Determinacao de pontes e articulacoes
        Caminho/ciclo Euleriano
        Decomposicao em componentes fortemente conexas
        Teste de conectividade
        Bipartite matching
        Etc.

    Como chamar a funcao:

        1) Zerar a matriz de adjacencias (graph[][]), color[]
           e a variavel num.

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao dfs(u,p), onde u eh o vertice
           de origem (source) para a busca e p eh o
           vertice de destino da busca. Se a intencao
           for realizar uma busca completa deve-se passar
           o valor -1 no parametro p.

    Resultado da funcao:

        A funcao armazena em dfsNum[] a ordem de visita
        dos vertices durante a busca. E o vetor color[]
        indica se a busca encontrou (2) ou nao (0) o
        vertice.

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:

        DEPENDEN (SPOJ BR)
        FORRO (SPOJ BR)
        IREVIR (SPOJ BR)
        NATUREZA (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

bool graph[MAXN][MAXN];
int color[MAXN];
int dfsNum[MAXN];
int num;
int n;

void dfs (int u, int p)
{
    color[u] = 1; //gray
    dfsNum[u] = ++num;
    for (int v = 0; v < n; ++v)
    {
        if (graph[u][v] && v != p)
        {
            if (color[v] == 0)   //forward edge
            {
                dfs (v, u);
            }
        }
        else if (color[v] == 1)   //back edge
        {
        }
        else   //cross edge, somente em grafos direcionados
        {
        }
    }
    color[u] = 2; //black
}

int main()
{
    return 0;
}
