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

    NUMERO DE SUBSEQUENCIAS PALINDROMES

    Aplicacoes:

        Determinar o numero de subsequencias de uma string
        que sao palindromos.

    Como chamar a funcao:

        1) Armazenar a string em string S

        2) Chamar a funcao ps()

    Resultado da funcao:

        A funcao ps() retorna o numero de subsequencias de
        S que sao palindromes

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        CB03 (CodeChef)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int n;
string S;
vector <vector<long long> > best;
long long solve (int b, int e)
{
    long long &res = best[b][e];
    if (res >= 0)
        return res;
    if (b == e)
        return res = 1;
    if (b + 1 == e)
        return res = 2;
    res = solve (b, e - 1) + solve (b + 1, e);
    if (S[b] != S[e - 1])
        res -= solve (b + 1, e - 1);
    return res;
}
long long ps ()
{
    best.clear();
    n = S.size();
    best.resize(n + 1, vector <long long> (n + 1, -1));
    return (solve (0, n) - 1);
}

int main()
{
    return 0;
}
