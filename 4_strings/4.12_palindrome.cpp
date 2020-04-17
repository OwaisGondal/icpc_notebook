#include <cstdio>
#include <iostream>

#define ALL(c) (c).begin(), (c).end()

using namespace std;

/*

    PALINDROME

    Aplicacoes:

        Determinar se uma string s eh palindrome

    Como chamar a funcao:

        1) Chamar a funcao is_palindrome(s), onde;

            s -> string a ser analisada

    Resultado da funcao:

        A funcao retorna:

            true se s eh palindrome
            false se s nao eh palindrome

    Complexidade do algoritmo:

        O(n)

    Problemas resolvidos:

        UVA 11309
        UVA 353
        UVA 401
        UVA 10018
        UVA 10945
        UVA 112211

    Adicionado por:

        Jorge Gabriel Siqueira

*/

bool is_palindrome(string const &s)
{
    return equal(ALL(s),s.rbegin());
}

int main()
{
    return 0;
}
