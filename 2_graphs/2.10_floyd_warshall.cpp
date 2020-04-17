#include <stdio.h>
#include <string.h>
#include <iostream>

#define INF 0x3F3F3F3F
#define MAXN 150

using namespace std;

/*

    FLOYD-WARSHALL (ALL-PAIRS SHORTEST PATH)

    Aplicacoes:

        Menor caminho entre todos os pares de vertices do grafo
        Fecho transitivo
        Deteccao de ciclos negativos
        Conectividade
        Etc.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Inicializar graph[][] da seguinte forma:
           - graph[i][i] = 0, para todo i
           - graph[i][j] = INF, se nao existir uma aresta entre i e j
           - graph[i][j] = c, se existir uma aresta entre i e j de custo c

        4) Chamar a funcao floyd_warshall ()

    Resultado da funcao:

        ANTECAO: A funcao armazena o resultado na propria
        matriz de adjacencias. graph[i][j] represetara no
        final da execucao do algoritmo a distancia minima
        do vertice i ate o vertice j.

    Complexidade do algoritmo:

        O(n^3)

    Problemas resolvidos:

        DENGUE (SPOJ BR)
        IREVIR (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int graph[MAXN][MAXN];
int n;

/*

    Algoritmo Classico

*/
void floyd_warshall ()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = min (graph[i][j], graph[i][k] + graph[k][j]);
}

/*

    Deteccao de Ciclos Negativos

*/
bool floyd_warshall ()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                graph[i][j] = min (graph[i][j], graph[i][k] + graph[k][j]);
            }
            if (graph[i][i] < 0)
                return true;
        }
    }
    return false;
}

/*

    Fecho Transitivo

    Apos a execucao do algoritmo a matriz de adjacencia serq dada por:

         graph[i][j] = 1, se existir um caminho direto ou indireto entre i e j
         graph[i][j] = 0, se nao existir um caminho entre i e j no grafo

    obs: inicializar graph[i][j] com 1 se existir um
    caminho direto entre os vertices i e j

*/
void floyd_warshall ()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (graph[i][k])
            {
                for (int j = 0; j < n; ++j)
                {
                    graph[i][j] |= (graph[i][k] & graph[k][j]);
                }
            }
        }
    }
}

/*

    Mini-Max

    O problema consiste em determinar de
    todos os caminhos possiveis entre dois
    vertices o caminho que possui a menor
    maior aresta.

*/
void floyd_warshall ()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
}

/*

    Max-Mini

    O problema consiste em determinar de
    todos os caminhos possiveis entre dois
    vertices o caminho que possui a maior
    menor aresta.

*/
void floyd_warshall ()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
}

/*

    Safest Path

    inicializar graph[i][j] com a probabilidade de
    sobreviver movendo-se do vertice i ao vertice j.

    inicializar graph[i][i] com 0.

    Ao final do processo graph[i][j] contera a probabilidade
    de sobreviver movendo-se do vertice i ao vertice j
    utilizando-se do caminho mais seguro possivel

*/
void floyd_warshall ()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]));
}

int main()
{
    return 0;
}
