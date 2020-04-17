#include <stdio.h>
#include <string.h>
#define MAXM 600
#define MAXW 600

using namespace std;

/*

    STABLE MARRIAGE ALGORITHM

    Aplicacoes:

        Seja um conjunto de m homens e n mulheres, onde
        cada pessoa possui uma preferencia (numero inteiro)
        por pessoas do sexo oposto. o algoritmo produz um
        casamento de cada homem com uma mulher de forma que
        todos os casamentos sejam estaveis, isto eh:

            - Cada homem se casara com uma mulher diferente (n >= m)
            - Dois casais H1M1 e H2M2 nao serao instaveis.

        Dois casais H1M1 e H2M2 sao instaveis se:

            - H1 prefere M2 ao inves de M1, e
            - M1 prefere H2 ao inves de H1.

    Como chamar a funcao:

        1) Armazenar em:

                m: O numero de homens
                n: O numero de mulheres

        2) Preencher R com as preferencias das
           mulheres da seguinte forma:

            R[x][y] = i : i eh a ordem de preferencia
                          do homem y pela mulher x

            Obs.: Quanto maior o valor de i menor eh a
                  preferencia do homem y pela mulher x

        3) Preencher L com as preferencias dos
           homens da seguinte forma:

            L[x][i] = y : A mulher y eh a i-esima
                          preferencia do homem x

            Obs.: 0 <= i <= n-1, quanto menor o valor de i
                  maior eh a preferencia do homem x pela mulher y

    Resultado da funcao:

       A funcao stableMarriage() armazena em:

            L2R[i]: a mulher do homem i (sempre entre 0 e n-1)
            R2L[j]: o homem da mulher j (-1 se a mulher for solteira)

    Complexidade do algoritmo:

        O(m^2)

    Problemas resolvidos:

        STABLEMP (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int L[MAXM][MAXW];
int R[MAXW][MAXM];
int L2R[MAXM], R2L[MAXW];
int m, n;
int p[MAXM];

void stableMarriage ()
{
    static int p[MAXM];
    memset(R2L, -1, sizeof(R2L));
    memset(p, 0, sizeof(p));
    for (int i = 0; i < m; ++i)
    {
        int man = i;
        while (man >= 0)
        {
            int wom;
            while (1)
            {
                wom = L[man][p[man]++];
                if (R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]])
                    break;
            }
            int hubby = R2L[wom];
            R2L[L2R[man] = wom] = man;
            man = hubby;
        }
    }
}

int main()
{
    return 0;
}
