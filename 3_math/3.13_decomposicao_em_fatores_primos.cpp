#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

/*

    DECOMPOSICAO EM FATORES PRIMOS

    Aplicacoes:

        Determinar a fatoracao em numeros primos de
        um numero n.

        Exemplo:

            factorize(18) = {2, 3, 3}

    Como chamar a funcao:

        1) Chamar a funcao factorize(n)

    Resultado da funcao:

        A funcao factorize() retorna um vector <int> que
        contem os fatores primos resultantes da fatoracao
        do numero n.

    Complexidade do algoritmo:

        O(sqrt(n))

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

int main()
{
    return 0;
}
