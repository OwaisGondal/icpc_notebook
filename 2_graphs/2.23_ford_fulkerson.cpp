#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define MAX 1001

using namespace std;

/*

    FORD FULKERSON MAX FLOW ALGORITHM

    Aplicacoes:

        Fluxo maximo de um vertice s(origem) para um
        vertice d(destino)

    Como chamar a funcao:

        1) Zerar a matriz de adjacencias (grafo[][])

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao fordF(s,d), onde s eh o vertice
           de origem e d eh o vertice de destino do fluxo

    Resultado da funcao:

        A funcao retorna o fluxo maximo de s ate d.
        A funcao armazena em pred[]: pred[i] o predecessor
        do vertice i (-1 caso nao possua).

    Complexidade do algoritmo:

         O(m*f), onde m eh o numero de arestas e f eh o valor
                 do fluxo maximo.

    Problemas resolvidos:

        CAVALOS (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int grafo[MAX][MAX], pred[MAX], n;
bool visitado[MAX];

bool busca(int s, int d)
{
    register int i, x, pilha[MAX], topo;

    memset(visitado, 0, sizeof(visitado));
    memset(pred, -1, sizeof(pred));

    topo = -1;

    pilha[++topo] = s;
    pred[s] = s;

    while(topo >= 0)
    {
        x = pilha[topo];
        topo--;
        visitado[x] = 1;
        if(x == d) break;

        for(i=0; i<n; i++)
        {
            if(grafo[x][i] && !visitado[i])
            {
                pilha[++topo] = i;
                pred[i] = x;
            }
        }
    }

    if(pred[d] == -1) return false;
    else return true;
}

int calculaMinimo(int s, int d)
{
    int minimo = INF;
    while(d != s)
    {
        if(minimo > grafo[pred[d]][d]) minimo = grafo[pred[d]][d];
        d = pred[d];
    }
    return minimo;
}

int fordF(int s, int d)
{
    int minimo, total=0, x;
    while(busca(s,d))
    {
        minimo = calculaMinimo(s,d);
        total += minimo;

        x = d;

        while(x != s)
        {
            grafo[pred[x]][x] -= minimo;
            grafo[x][pred[x]] += minimo;
            x = pred[x];
        }
    }
    return total;
}

int main()
{
    return 0;
}
