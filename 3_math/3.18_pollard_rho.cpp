#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <iostream>

using namespace std;

/*

    POLLARD RHO

    Aplicacoes:

        Fatorar numeros grandes de forma eficiente.

        Obs: O metodo so funciona para numeros compostos
        (testar a primalidade antes!)

        Usar em conjunto com MILLER RABIN

        Para fatorar um numero, deve-se chamar a funcao
        pollard() sucessivamente ate que o seu resultado
        seja um numero primo.

    Como chamar a funcao:

        1) Chamar pollard(n)

    Resultado da funcao:

        A funcao pollard() retorna um fator nao-trivial
        do numero que esta sendo fatorado

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

long long pollard_r, pollard_n;

inline long long f (long long val)
{
    return (val*val + pollard_r) % pollard_n;
}

inline long long myabs (long long a)
{
    return a >= 0 ? a : -a;
}

long long pollard (long long n)
{
    srand(unsigned(time(0)));
    pollard_n = n;
    long long d = 1;

    do
    {
        d = 1;
        pollard_r = rand() % n;
        long long x = 2, y = 2;
        while (d == 1)
            x = f(x), y = f(f(y)), d = __gcd(myabs(x-y), n);
    }

    while (d == n);

    return d;
}

int main()
{
    return 0;
}
