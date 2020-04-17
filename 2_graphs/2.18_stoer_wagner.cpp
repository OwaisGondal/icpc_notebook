#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

/*

    STOER WAGNER MINIMUM CUT

    Aplicacoes:

        Dado um grafo nao orientado e ponderado,
        retorna o peso do corte minimo no grafo.
        Um corte eh um conjunto de arestas que,
        quando removido, desconecta o grafo.
        Um corte minimo eh um corte de peso total minimo.

    Como chamar a funcao:

        1) Zerar a matriz de adjacencias (graph[][])

        2) Armazenar em n o numero de vertices do grafo

        3) Preencher a matriz de adjacencias com as
           informacoes referentes ao grafo.

        4) Chamar a funcao stoer_wagner()

    Resultado da funcao:

        A funcao stoer_wagner() retorna o
        valor do corte minimo no grafo

    Complexidade do algoritmo:

        O(n^3)

    Problemas resolvidos:

        UVA 10989

    Adicionado por:

        Jorge Gabriel Siqueira

*/

// Maximum number of vertices in the graph
#define NN 256

// Maximum edge weight (MAXW * NN * NN must fit into an int)
#define MAXW 1000000

// Adjacency matrix and some internal arrays
int g[NN][NN], v[NN], w[NN], na[NN];
bool a[NN];
int n;

int stoer_wagner()
{
    // init the remaining vertex set
    for( int i = 0; i < n; i++ ) v[i] = i;

    // run Stoer-Wagner
    int best = MAXW * n * n;
    while( n > 1 )
    {
        // initialize the set A and vertex weights
        a[v[0]] = true;
        for( int i = 1; i < n; i++ )
        {
            a[v[i]] = false;
            na[i - 1] = i;
            w[i] = g[v[0]][v[i]];
        }

        // add the other vertices
        int prev = v[0];
        for( int i = 1; i < n; i++ )
        {
            // find the most tightly connected non-A vertex
            int zj = -1;
            for( int j = 1; j < n; j++ )
                if( !a[v[j]] && ( zj < 0 || w[j] > w[zj] ) )
                    zj = j;

            // add it to A
            a[v[zj]] = true;

            // last vertex?
            if( i == n - 1 )
            {
                // remember the cut weight
                best = min(best,w[zj]);

                // merge prev and v[zj]
                for( int j = 0; j < n; j++ )
                    g[v[j]][prev] = g[prev][v[j]] += g[v[zj]][v[j]];
                v[zj] = v[--n];
                break;
            }
            prev = v[zj];

            // update the weights of its neighbours
            for( int j = 1; j < n; j++ ) if( !a[v[j]] )
                w[j] += g[v[zj]][v[j]];
        }
    }
    return best;
}


int main()
{
    return 0;
}
