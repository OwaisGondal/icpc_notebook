#include <stdio.h>

/*

    EXTENDED EUCLIDEAN ALGORITHM (BEZOUT THEOREM)

    Aplicacoes:

        Determinar a solucao da equacao
        a*x + b*y = gcd(a,b), onde a e b sao dois
        numeros inteiros nao negativos.

    Como chamar a funcao:

        1) Chamar a funcao egcd(a,b)

    Resultado da funcao:

        A funcao retorna a tripla(gcd(a,b), x, y)

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

struct Triple
{
    int d, x, y;
    Triple (int q, int w, int e) : d(q), x(w), y(e) {}
};

Triple egcd (int a, int b)
{
    if (!b)
        return Triple(a, 1, 0);

    Triple q = egcd(b, a % b);
    return Triple(q.d, q.y, q.x - a / b * q.y);
}

int main()
{
    return 0;
}
