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

    MANACHER MAIOR SUBSTRING PALINDROME

    Aplicacoes:

        Determinar a maior substring palindromo de uma
        string.

        Exemplo:

            banana -> anana

    Como chamar a funcao:

        1) Chamar a funcao longestPalindromeSubstring(s), onde s
        eh a string onde sera feito a busca.

    Resultado da funcao:

        A funcao retorna a string que representa a maior
        subsequencia palindrome de s.

    Complexidade do algoritmo:

         O(n)

    Problemas resolvidos:

        EPALIN (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s)
{
    int n = s.length();
    if (n == 0) return "^$";
    string ret = "^";
    for (int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);

    ret += "#$";
    return ret;
}

string longestPalindromeSubstring(string s)
{
    string T = preProcess(s);
    int n = T.length();
    int *P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++)
    {
        int i_mirror = 2*C-i; // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    delete[] P;

    return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

int main()
{
    return 0;
}
