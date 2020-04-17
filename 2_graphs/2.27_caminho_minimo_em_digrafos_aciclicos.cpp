#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#define FOI -1
#define INF 0x3f3f3f3f
#define MAX 200

using namespace std;

/*

    SHORTEST PATH ACICLIC DIGRAPHS

    Aplicacoes:

        Calcula o caminho minimo em um grafo
        orientado sem ciclos

    Como chamar a funcao:

        1) Zerar as variaveis grafo[][] e grauEntrada[]

        2) Armazenar em n o numero de vertices do grafo

        3) Armazenar o grafo em forna de matriz de adjacencias,
           mantendo o grau de entrada de cada vertice.

            Para armazenar uma aresta que liga o vertice
            x a y com custo c:

                grafo[x][y] = c;
                grauEntrada[y]++;

        4) Chamar a funcao shortest_path(p), onde p eh o
           vertice de origem da busca

    Resultado da funcao:

        A funcao armazena em dist[]: dist[i] a distancia
        minima dovertice p ao vertice i

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:



    Adicionado por:

        Jorge Gabriel Siqueira

*/


int grafo[MAX][MAX], n;
int grauEntrada[MAX];
int dist[MAX];
int top[MAX];

void topSort()
{
    queue<int> Q;

    for(int i=0; i<n; i++)
    {
        if(grauEntrada[i] == 0) Q.push(i);
    }

    int posic=0;

    while( !Q.empty())
    {
        int N = Q.front();
        Q.pop();
        top[posic++] = N;
        for(int M=0; M<n; M++)
        {
            if(grafo[N][M] != 0)
            {
                grauEntrada[M]--;
                if(grauEntrada[M] == 0)
                {
                    Q.push(M);
                }
            }
        }
    }
}

void shortest_path(int p)
{
    int i,j;
    memset(dist, INF, sizeof(dist));
    topSort();
    dist[p] = 0;

    for(i = 0; top[i] != p; i++);

    for(; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(grafo[top[i]][top[j]]) dist[top[j]] = min(dist[top[j]], dist[top[i]] + grafo[top[i]][top[j]]);
		}
	}
}



int main()
{
    return 0;
}
