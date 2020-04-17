#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

/*

    EULER TOTIENT - PHI

    Aplicacoes:

        Dado um numero n, contar o numero de inteiros
        positivos menores ou iguais a n que sao co-primos de n.

        Dois numeros a e b sao co-primos se gcd(a,b) = 1

    Como chamar a funcao:

        1) Chamar a funcao phi(n)

    Resultado da funcao:

        A funcao retorna o numero de inteiros positivos
        menores ou iguais a n que sao co-primos de n

    Complexidade do algoritmo:

        O (sqrt(n))

    Problemas resolvidos:

        UVA 12493

    Adicionado por:

        Jorge Gabriel Siqueira

*/

void factorize (int n, vector <int> &v)
{
    int sq = int (sqrt((double)n));
    for (int i = 2; i <= sq; ++i)
    {
        if (n % i)
            continue;
        v.push_back (i);
        n /= i--;
        sq = int (sqrt((double) n));
    }
    if (n > 1)
        v.push_back(n);
}

int phi (int n)
{
    vector <int> p;

    factorize (n, p);

    for (int i = 0; i < p.size(); ++i)
    {
        if (i && p[i] == p[i - 1])
            continue;
        n /= p[i];
        n *= p[i] - 1;
    }

    return n;
}

int main()
{
    return 0;
}
