#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXN 10000000
#define gP(n)(prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n)(prime[n>>6]&=~(1<<((n>>1)&31)))

unsigned int prime[MAXN / 64];

/*

    CRIVO DE ERASTOTENES

    Aplicacoes:

        Determinar os numeros primos no intervalo [3,MAXN]
        de forma eficiente, necessitando apenas de MAXN / 16
        bytes de memoria.

        Observacao: O algoritmo funciona apenas para numeros
        impares. Tratar numeros pares separadamente!

    Como chamar a funcao:

        1) Chamar a funcao sieve() para preencher a tabela.

        3) Para descobrir se um numero n eh primo chame
           a funcao gP(n).

    Resultado da funcao:

        A funcao retorna:

            0 se o numero nao eh primo
            Algo diferente de 0 caso contrario

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        DINOSTRA (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

void sieve()
{
    memset(prime, -1, sizeof(prime));
    unsigned int i;
    unsigned int sqrtN = (unsigned int) sqrt((double) MAXN) + 1;

    for (i = 3; i < sqrtN; i += 2)
        if (gP( i ))
        {
            unsigned int i2 = i + i;
            for (unsigned int j = i * i; j < MAXN; j += i2)
                rP(j);
        }
}

int main()
{
    return 0;
}
