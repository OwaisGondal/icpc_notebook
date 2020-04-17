#include <stdio.h>
#include <vector>

using namespace std;

/*

    PRIMOS EM UM INTERVALO

    Aplicacoes:

        Determinar os numero primos contidos em um
        intervalo [n,m]

    Como chamar a funcao:

        1) Chamar a funcao primesBetween(n,m)

    Resultado da funcao:

        A funcao primesBetween(n,m) armazena em vector<int> ret
        os primos contidos no intervalo [n,m]

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        PRIME1 (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector<int> ret;

void primesBetween (int n, int m)
{
    ret.clear();
    int* primes = new int[m - n + 1];

    for (int i = 0; i < m - n + 1; ++i)
        primes[i] = 0;

    for (int p = 2; p*p <= m; ++p)
    {
        int less = n / p;
        less *= p;

        for (int j = less; j <= m; j += p)
            if (j != p && j >= n)
                primes[j - n] = 1;
    }

    for (int i = 0; i < m - n + 1; ++i)
    {
        if (primes[i] == 0 && n+i != 1)
            ret.push_back(n+i);
    }

    delete primes;
}

int main()
{
    return 0;
}
