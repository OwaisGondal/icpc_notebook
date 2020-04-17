#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <math.h>
#include <sstream>
#include <assert.h>
#include <numeric>
#include <fstream>
#include <limits>
#define INF 0x3f3f3f3f
#define MAX 105

using namespace std;

/*

    FLOYD WARSHALL WITH PATH RECONSTRUCTION

    Aplicacoes:

        Calcular o custo e imprimir o menor caminho entre quaisquer
        vertices de um grafo.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Inicializar grafo[][] da seguinte forma:
           - grafo[i][i] = 0, para todo i
           - grafo[i][j] = INF, se nao existir uma aresta entre i e j
           - grafo[i][j] = c, se existir uma aresta entre i e j de custo c

        3) Chamar a funcao FloydWarshallWithPathReconstruction() para
           calcular o menor caminho de todos os vertices para todos
           vertices.

        4) Chamar a funcao printPath(s,t) para imprimir o menor caminho
           partindo do vertice s ate o vertice t

    Resultado da funcao:

        A funcao FloydWarshallWithPathReconstruction()
        armazena em dist[][] : dist[s][t] a menor distancia
        entre partindo do vertice s ate o vertice t

    Complexidade do algoritmo:

        O(n^3)

    Problemas resolvidos:

        URI 1427

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int n;
int dist[MAX][MAX];
int next[MAX][MAX];
int grafo[MAX][MAX];

void FloydWarshallWithPathReconstruction()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dist[i][j] = grafo[i][j];
        }
    }

    memset(next, -1, n*sizeof(int));

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = k;
                }
            }
        }
    }
}

void Path(int i, int j)
{
    if(dist[i][j] == INF) cout << "no path!";

    int intermediate = next[i][j];

    if(intermediate == -1) cout << " ";
    else
    {
        Path(i, intermediate);
        cout << intermediate;
        Path(intermediate, j);
    }
}

void printfPath(int s, int t)
{
    cout << "Path:" << s;
    Path(s,t);
    cout << t << endl;
}

int main()
{
    return 0;
}

