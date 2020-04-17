#include <stdio.h>
#include <stdlib.h>

/*

    LCM - LEAST COMMON MULTIPLE

    Aplicacoes:

        Determinar o menor multiplo comum (MMC)
        entre dois numeros inteiros positivos a e b

    Como chamar a funcao:

        1) Chamar a funcao lcm(a,b)

    Resultado da funcao:

        A funcao retorna o menor multiplo comum entre a e b

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

inline int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : abs(a);
}

inline long long lcm(int a, int b)
{
    if (a && b)
        return abs(a) / gcd(a, b) * (long long) abs(b);
    else
        return (long long) abs(a | b);
}

int main()
{
    return 0;
}
