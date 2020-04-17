#include <stdio.h>

/*

    MILLER RABIN

    Aplicacoes:

        Determinar se um numero n eh provavelmente primo.
        Ideal para testes de primalidade de numeros
        extremamente grandes.

    Como chamar a funcao:

        1) Chamar isProbablePrime(n)

    Resultado da funcao:

        A funcao isProbablePrime() retorna:

            true: Se n eh provavelmente primo
            false: Caso contrario

    Complexidade do algoritmo:

        O (?)

    Problemas resolvidos:

        PRIMO (SPOJ BR)
        URI 1221

    Adicionado por:

        Jorge Gabriel Siqueira

*/

long long powMod (long long a, long long k, long long n)
{
    long long ret = 1;

    for (long long pow = a; k > 0; k >>= 1, pow = (pow * pow) % n)
        if (k & 1)
            ret = (ret * pow) % n;

    return ret;
}

bool miller_rabin (long long n, long long base)
{
    if (n <= 1)
        return false;

    if (n%2 == 0)
        return n == 2;

    long long s = 0, d = n - 1;

    while (d%2 == 0)
        d /= 2, ++s;

    long long base_d = powMod(base, d, n);

    if (base_d == 1)
        return true;

    long long base_2r = base_d;

    for (long long i = 0; i < s; ++i)
    {
        if (base_2r == 1)
            return false;

        if (base_2r == n - 1)
            return true;

        base_2r = (long long) base_2r * base_2r % n;
    }

    return false;
}
bool isProbablePrime (long long n)
{
    if (n == 2 || n == 7 || n == 61)
        return true;

    return miller_rabin(n, 2) && miller_rabin(n, 7) && miller_rabin(n, 61);
}

int main()
{
    return 0;
}
