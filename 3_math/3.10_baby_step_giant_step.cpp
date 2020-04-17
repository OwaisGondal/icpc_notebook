#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

/*

    BABY STEP - GIANT STEP

    Aplicacoes:

        Determinar o menor valor de e na
        expressao b^e = n (mod p)

    Como chamar a funcao:

        1) Chamar a funcao bsgs(b,n,p)

    Resultado da funcao:

        A funcao bsgs(b,n,p) retorna o menor
        valor de e ou -1, se a equacao nao
        possuir solucao.

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        UVA 10225

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

long long bsgs (long long b, long long n, long long p)
{
    if (n == 1)
        return 0;

    map <long long, int> table;

    long long m = sqrt(p) + 1, pot = 1, pot2 = 1;

    for (int j = 0; j < m; ++j)
    {
        if (pot == n)
            return j;

        table[(n * invMod(pot, p)) % p] = j;
        pot = (pot * b) % p;
    }

    for (int i = 0; i < m; ++i)
    {
        if (table.find(pot2) != table.end())
            return i * m + table[pot2];
        pot2 = (pot * pot2) % p;
    }

    return -1;
}

int main()
{
    return 0;
}
