#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*

    GCD - GREATEST COMMON DIVISOR

    Aplicacoes:

        Determinar o maior divisor comum (MDC)
        entre dois numeros inteiros positivos a e b.

    Como chamar a funcao:

        1) Chamar a funcao gcd(a,b)

    Resultado da funcao:

        A funcao retorna o maior divisor comum entre a e b

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        URI 1028

    Adicionado por:

        Jorge Gabriel Siqueira

*/

inline int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : abs(a);
}

int main()
{
    return 0;
}
