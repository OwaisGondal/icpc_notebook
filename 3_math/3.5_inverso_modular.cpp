#include <stdio.h>

/*

    INVERSO MODULAR

    Aplicacoes:

        Determinar a solucao da equacao a*x = 1 (mod n).
        se n eh primo, entao x = (a^n-2) % n.

    Como chamar a funcao:

        1) Chamar a funcao invMod(a,n)

    Resultado da funcao:

        A funcao invMod(a,n) retorna o valor de x,
        ou 0 caso nao possua solucao

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

int invMod (int a, int n)
{
    Triple t = egcd (a, n);

    if (t.d > 1)
        return 0;

    int r = t.x % n;

    return (r < 0 ? r + n : r );
}

int main()
{
    return 0;
}
