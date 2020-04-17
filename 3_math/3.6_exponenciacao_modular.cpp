#include <stdio.h>

/*

    EXPONENCIACAO MODULAR

    Aplicacoes:

        Determinar a^k (mod n) de forma eficiente.

    Como chamar a funcao:

        1) Chamar a funcao powMod(a,k,n)

    Resultado da funcao:

        A funcao powMod(a,k,n) retorna o valor de a^k (mod n)

    Complexidade do algoritmo:

        O(log(k))

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

//metodo nao recursivo
long long powMod (long long a, long long k, long long n)
{
    long long ret = 1;

    for (long long pow = a; k > 0; k >>= 1, pow = (pow * pow) % n)
        if (k & 1)
            ret = (ret * pow) % n;

    return ret;
}

//metodo recursivo
long long powMod (long long a, long long k, long long n)
{
    if (k == 0)
        return 1;
    if (k%2 == 0)
        return powMod(a * a % n , k/2, n);
    else
        return a * powMod(a, k - 1 ,n) % n;
}

int main()
{
    return 0;
}
