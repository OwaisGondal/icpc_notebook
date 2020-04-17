#include <stdio.h>
#include <string.h>
#define MAXSZ 100

/*

    FENWICK TREE

    Aplicacoes:

        Determinar a soma dos elementos contidos em
        um sub-intervalo de um conjunto.

    Como chamar a funcao:

        1) Armazenar em c o numero de elementos do
           conjunto

        2) Para soma o valor inc a posicao k do
           conjunto chamar:

                update(k, inc);

        3) Para saber a soma do intervalo que comeca
           em from e termina em to chamar:

                query(from, to);

    Resultado da funcao:

        A funcao query(from,to) retorna a soma do intervalo
        que comeca em from e termina em to

    Complexidade do algoritmo:

        O(log(n))

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int tree[MAXSZ], c;

void create()
{
    memset(tree,0,c*sizeof(int));
}

int query(int from, int to)
{
    int sum;

    if (from != 0) return query(0, to) - query(0, from-1);

    for (sum=0; to >= 0; to = (to & (to + 1)) - 1) sum += tree[to];

    return sum;
}

void update(int k, int inc)
{
    for ( ; k < c; k |= k + 1) tree[k] += inc;
}

int main()
{

}
