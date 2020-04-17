#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define FOI -1
#define MAX 200

using namespace std;

/*

    TOPOLOGICAL SORT

    Aplicacoes:

        Calcula a ordenacao topologica de um grafo

        Obs. Nao existe ordenacao topologica em grafos
             ciclicos

    Como chamar a funcao:

        1) Zerar o vetor de tamanho da lista de
           adjacencias pos[] e o vetor grauEntrada[]:

                memset(pos, 0, sizeof(pos));
                memset(grauEntrada, 0, sizeof(grauEntrada));

        2) Armazenar em n o numero de vertices do grafo

        3) Armazenar o grafo em forna de lista de adjacencias,
           mantendo o grau de entrada de cada vertice.

            Para armazenar uma aresta que liga o vertice x a y:

                grafo[x][pos[x]++] = y;
                grauEntrada[y]++;

        4) Chamar a funcao topSort()

    Resultado da funcao:

        A funcao armazena em top[]: top[i] o i-esimo
        elemento da ordenacao topologica.

    Complexidade do algoritmo:

        O(n+m), onde m eh  numero de arestas do grafo

    Problemas resolvidos:



    Adicionado por:

        Jorge Gabriel Siqueira

*/

int grafo[MAX][MAX], pos[MAX], grauEntrada[MAX], top[MAX], n;

void topSort()
{
    queue<int> Q;

    for(int i=0; i<n; i++)
    {
        if(!grauEntrada[i]) Q.push(i);
    }

    int posic = 0;

    while(!Q.empty())
    {
        int N = Q.front();
        Q.pop();
        top[posic++] = N;
        for(int M=0; M<pos[N]; M++)
        {
            int v = grafo[N][M];
            grauEntrada[v]--;
            if(!grauEntrada[v])
            {
                Q.push(v);
            }
        }
    }
}

int main()
{
    return 0;
}
