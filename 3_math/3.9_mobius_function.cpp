#include <cstdio>
#define MAXN 2000000 //valor maximo de n

/*

    MOBIUS FUNCTION

    Aplicacoes:

        Determinar o valor de mu(n), onde mu eh a
        funcao de Mobius:

            mu(n) = 0, se n nao eh uma raiz livre;

            mu(n) = 1, se n e uma raiz livre com um
                       numero par de fatores primos

            mu(n) = -1, se n eh uma raiz livre com um
                        numero impar de fatores primos

        Obs: uma raiz livre eh aquela que nao eh divisivel
             por um quadrado perfeito.

        Exemplo: 10 (2*5) eh uma raiz livre, mas 18 (2*3*3) nao!

    Como chamar a funcao:

        1) Chamar a funcao mu(n)

    Resultado da funcao:

        A funcao retorna o resultado da funcao Mobius

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int mu(int n)
{
    static int lookup = 0, p[MAXN], f[MAXN];

    if (!lookup)
    {
        for (int i = 0; i < MAXN; ++i)
            p[i] = 1, f[i] = 1;

        for (int i = 2; i < MAXN; ++i)
        {
            if (p[i])
            {
                f[i] = -1;

                for (int j = i + i; j < MAXN; j += i)
                {
                    p[j] = 0;
                    f[j] *= (j % (i * i) == 0) ? 0 : -1;
                }
            }
        }

        lookup = 1;
    }

    return f[n];
}

int main()
{
    return 0;
}
