#include <cstdio>
#define MAXN 1000

/*

    CHINESE REMAINDER THEOREM

    Aplicacoes:

        Determinar x tal que x = a[i] (mod p[i]).

        Exemplo: Para a[] = {1,2,3} e p[] = {5,6,7}
        determinar x tal que:

            x = 1 (mod 5)
            x = 2 (mod 6)
            x = 3 (mod 7)

        resposta: x = 206

    Como chamar a funcao:

        1) Chamar a funcao crt()

    Resultado da funcao:

        A funcao retorna o valor de x.

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        UVA 756

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int n;
int a[MAXN], p[MAXN];

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

int crt()
{
    int M = 1, x = 0;

    for (int i = 0; i < n; ++i)
        M *= p[i];

    for (int i = 0; i < n; ++i)
        x += a[i] * invMod(M/p[i],p[i]) * (M/p[i]);

    return (((x%M) + M)%M);
}

int main()
{
    return 0;
}
