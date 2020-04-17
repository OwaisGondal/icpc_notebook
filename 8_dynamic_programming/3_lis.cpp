#include <stdio.h>
#include <iostream>
#define MAX 500

/*
    LIS -> Maior Subsequencia Crescente
    Tempo: ( n^2 + n ) / 2

    dist[i] -> vetor auxiliar que computa a LIS do i-esimo vertice
    seq[] -> vetor que guarda a sequencia inteira
    pred[] -> vetor de predecessores para se recuperar a LIS

    Parametros;
        n = tamanho da sequencia seq[]

    Retorno:
        pair<int,int>:
            first -> Tamanho da LIS
            second -> vertice final da LIS
*/

using namespace std;

int dist[MAX], seq[MAX], pred[MAX];

pair<int,int> LIS(int n)
{
    int i, j;
    pair<int,int> lis;

    lis.first = 0;

    for(i=0; i<n; i++)
    {
        dist[i] = 1;
        pred[i] = i;

        for(j=0; j<i; j++)
        {
            if(seq[j] < seq[i] && dist[j]+1 > dist[i]) //mudar para menor ou igual para ter elementos repetidos
            {
                dist[i] = dist[j]+1;
                pred[i] = j;

                if(lis.first < dist[i])
                {
                    lis.first = dist[i];
                    lis.second = i;
                }
            }
        }
    }

    return lis;
}

int main()
{
    int n, i, j,vet[MAX];
    pair<int,int> lis;

    scanf("%d",&n);

    for(i=0; i<n; i++) scanf("%d",&seq[i]);

    lis = LIS(n);

    i = lis.second;
    j=0;

    while(1)
    {
        vet[j++] = i;
        if(i == pred[i]) break;
        else i = pred[i];
    }

    for(i=j-1; i>=0; i--) printf("%d ",seq[vet[i]]);

    return 0;
}
