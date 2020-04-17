#include <stdio.h>
#include <string.h>
#include <iostream>
#define INF 0x3F3F3F3F
#define MAXN 1000

using namespace std;

/*

    DIJKSTRA'S ALGORITHM (SINGLE-SOURCE SHORTEST PATH)

    Aplicacoes:

       Menor caminho em grafos densos (m > n2/log(n))
       SEM ARESTAS NEGATIVAS!

    Como chamar a funcao:

        1) Preencher a matriz de adjacencias (grafo[][])
           com INF.

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao dijkstra(p), onde p eh o
           vertice de origem (source) de busca

    Resultado da funcao:

        A funcao armazena em dist[]: dist[i] a distancia
        de p (source) ate i

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:

        PONTES09 (SPOJ BR)
        QUASEMEN (SPOJ BR)
        DESVIO (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int grafo[MAXN][MAXN];
int dist[MAXN];
int pred[MAXN];
bool visitado[MAXN];
int n;

void dijkstra(int p)
{
    register int i, v, c;

    memset(dist, INF, sizeof(dist));
    memset(visitado, 0, sizeof(visitado));
    memset(pred, -1, sizeof(pred));

    dist[p] = 0;
	v = p;

	while(!visitado[v])
	{
		visitado[v] = true;
		for(i=0; i<n; i++)
		{
			if(grafo[v][i] != INF)
			{
				c = grafo[v][i];

				if(dist[i] > dist[v]+c)
				{
					dist[i] = dist[v]+c;
					pred[i] = v;
				}
			}
		}

		v = 0;
		c = INF;

		for(i=1; i<n; i++)
		{
			if(visitado[i] == false && c > dist[i])
			{
				c = dist[i];
				v = i;
			}
		}
	}
}

int main()
{
    return 0;
}
