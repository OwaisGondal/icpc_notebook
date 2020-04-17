#include <stdio.h>
#define MAXN 80

/*

    BINOMIAL

    Aplicacoes:

        Calculo do triangulo de pascal ate ordem maxima MAXN.
        C[n][k] = valor da combinacao C(n,k), onde k <= n.

    Como chamar a funcao:

        1) Chamar a funcao pascalTriangle()

    Resultado da funcao:

        A funcao pascalTriangle() armazena em C[][]:
        C[i][j] a combinacao C[i][j], note que a combinacao
        tambem representa o triangulo de pascal.

        0  : 1 |_____
        1  : 1 | 1  |_____
        2  : 1 | 2  | 1  |_____
        3  : 1 | 3  | 3  | 1   |_____
        4  : 1 | 4  | 6  | 4   | 1   |_____
        5  : 1 | 5  | 10 | 10  | 5   | 1   |_____
        6  : 1 | 6  | 15 | 20  | 15  | 6   | 1   |_____
        7  : 1 | 7  | 21 | 35  | 35  | 21  | 7   | 1   |_____
        8  : 1 | 8  | 28 | 56  | 70  | 56  | 28  | 8   | 1   |_____
        9  : 1 | 9  | 36 | 84  | 126 | 126 | 84  | 36  | 9   | 1  |
        10 : 1 | 10 | 45 | 120 | 210 | 252 | 210 | 120 | 45  | 10 | 1 |

        C(33, 16) = 1.166.803.110 [limite do int]
        C(34, 17) = 2.333.606.220 [limite do unsigned int]
        C(66, 33) = 7.219.428.434.016.265.740 [limite do int64_t]
        C(67, 33) = 14.226.520.737.620.288.370 [limite do uint64_t]

    Complexidade do algoritmo:

        O(MAXN^2)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

unsigned long long C[MAXN+1][MAXN+1];

void pascalTriangle()
{
    unsigned long long n, k;

    for (n = 0; n <= MAXN; ++n)
    {
        C[n][0] = C[n][n] = 1;

        for (k = 1; k < n; ++k)
            C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
}

int main()
{
    return 0;
}
