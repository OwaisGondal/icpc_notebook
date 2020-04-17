#include <stdio.h>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))
#define COMP(h, k) (h == m || (k+h<n && p[h]<t[k+h]))

using namespace std;

/*

    RANGE MAXIMUM QUERY

    Aplicacoes:

        Queries de maior elemento em um sub-intervalo de
        um conjunto.

    Como chamar a funcao:

        1) Armazenar o numero de elementos do conjunto em n

        2) Armazenar o conjunto no vetor r[].

        3) Chamar a funcao construct() para construir o RMQ

        4) Chamar a funcao getmax(a, b) para realizar uma query
           no intervalo (a,b)

    Resultado da funcao:

        A funcao getmax(a, b) retorna o valor
        do maior elemento contido no subconjunto que
        inicia em a e termina em b.

    Complexidade do algoritmo:

        O(n) -> construcao
        O(1) -> queries

    Problemas resolvidos:

        UVA 11235

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int r[50010], n;
int mm[50010][18]; // Ou N x log(N) + 1

void construct()
{
    int i,j,b;

    for(i=0; i<n; i++) mm[i][0]=r[i];

    for(i=1; i<18; i++)
    {
        for(j=0; (j+(1<<i)-1)<n; j+=(1<<i)) mm[j][i] = max(mm[j][i-1], mm[j+(1<<(i-1))][i-1]);
    }
}

int getmax(int a, int b)
{
    if(a>b) return -1;

    for(int i=17; i>=0; i--)
    {
        if((a % (1 << i)) == 0 && (a + (1 << i) - 1) <= b)
            return max(mm[a][i], getmax(a + (1 << i), b));
    }
}

int main()
{
    return 0;
}
