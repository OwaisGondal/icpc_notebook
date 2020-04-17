#include <stdio.h>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))
#define COMP(h, k) (h == m || (k+h<n && p[h]<t[k+h]))

using namespace std;

/*

    RANGE MINIMUM QUERY

    Aplicacoes:

        Queries de menor elemento em um sub-intervalo de
        um conjunto.

    Como chamar a funcao:

        1) Construir a RMQ chamando a funcao:

            int *rmq = buildRMQ(a,n), onde:

                a -> vetor contendo os elementos do conjunto
                n -> numero de elementos do conjunto

            A RQM fica armazenada na variavel int *rmq

        2) Para realizar as queries chamar:

            minimum(x, y, rmq, n); onde:

                x -> inicio do intervalo
                y - fim do intervalo
                rmq -> RMQ (variavel int *rmq do passo 1)
                n -> numero de elementos do conjunto

    Resultado da funcao:

        A funcao minimum(x,y,rmq,n) retorna o valor
        do menor elemento contido no subconjunto que
        inicia em x e termina em y.

    Complexidade do algoritmo:

        O(n) -> construcao
        O(1) -> queries

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int *buildRMQ(int *a, int n)
{
    int logn = 1;
    for (int k = 1; k < n; k *= 2) ++logn;
    int *r = new int[n * logn];
    int *b = r;
    copy(a, a+n, b);
    for (int k = 1; k < n; k *= 2)
    {
        copy(b, b+n, b+n);
        b += n;
        REP(i, n-k) b[i] = min(b[i], b[i+k]);
    }
    return r;
}

int minimum(int x, int y, int *rmq, int n)
{
    int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k
    s = ( (z & 0xffff0000) != 0 ) << 4;
    z >>= s;
    e <<= s;
    k |= s;
    s = ( (z & 0x0000ff00) != 0 ) << 3;
    z >>= s;
    e <<= s;
    k |= s;
    s = ( (z & 0x000000f0) != 0 ) << 2;
    z >>= s;
    e <<= s;
    k |= s;
    s = ( (z & 0x0000000c) != 0 ) << 1;
    z >>= s;
    e <<= s;
    k |= s;
    s = ( (z & 0x00000002) != 0 ) << 0;
    z >>= s;
    e <<= s;
    k |= s;
    return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}

int main()
{
    return 0;
}
