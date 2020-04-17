#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;

/*

    DISTANCIA MINIMA DE ROTACAO

    Aplicacoes:

        Determinar o numero minimo de vezes que
        deve-se rotacionar uma string S (ao rotacionar,
        S torna-se T = S[2..n] + S[1]) de forma a se
        obter a menor construcao lexografica possivel.

        Exemplo: Dada a string "bbaaccaadd", a menor
        string resultante da rotacao desta eh "aaccaaddbb".

    Como chamar a funcao:

        1) Chamar a funcao minimumExpression(s), onde s
           eh um char[] contendo a string a ser analisada

    Resultado da funcao:

        A funcao retorna o numero minimo de rotacoes para
        tornar s a menor construcao lexografica possivel

    Complexidade do algoritmo:

        O(n)

    Problemas resolvidos:

        MINMOVE (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int minimumExpression(char s[])
{
    int i, j, k, n, len, p, q;
    len = n = strlen(s), n <<= 1, i = 0, j = 1, k = 0;
    while (i + k < n && j + k < n)
    {
        p = i + k >= len ? s[i + k - len] : s[i + k];
        q = j + k >= len ? s[j + k - len] : s[j + k];
        if (p == q)
            ++k;
        else if (p > q)
        {
            i = i + k + 1;
            if (i <= j)
                i = j + 1;
            k = 0;
        }
        else if (p < q)
        {
            j = j + k + 1;
            if (j <= i)
                j = i + 1;
            k = 0;
        }
    }
    return i < j ? i : j;
}

int main()
{
    return 0;
}
