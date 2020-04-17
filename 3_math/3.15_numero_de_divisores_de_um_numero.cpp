#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

/*

    NUMERO DE DIVISORES DE UM NUMERO

    Aplicacoes:

        Contar o numero de divisores positivos de um dado
        numero n, incluindo 1 e ele mesmo.

    Como chamar a funcao:

        1) Chamar a funcao divisors(n)

    Resultado da funcao:

        A funcao retorna o numero de divisores de n,
        incluindo 1 e ele mesmo.

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

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

int divisors (int n)
{
    vector <int> f;
    factorize (n, f);

    int k = f.size();

    vector <int> table(k + 1, 0);
    table[k] = 1;

    for (int i = k - 1; i >= 0; --i)
    {
        table[i] = table[i + 1];

        for (int j = i + 1; ; ++j)
            if (j == k || f[j] != f[i])
            {
                table[i] += table[j];
                break;
            }
    }

    return table[0];
}

int main()
{
    return 0;
}
