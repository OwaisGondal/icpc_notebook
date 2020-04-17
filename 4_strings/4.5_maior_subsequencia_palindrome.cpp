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

    MAIOR SUBSEQUENCIA PALINDROME

    Aplicacoes:

        Determinar a maior subsequencia de uma string que
        e um palindromo.

    Como chamar a funcao:

        1) Armazenar a string a ser processada em text[]

        2) Chamar a funcao longestPalindromeSubsequence()

    Resultado da funcao:

        A funcao retorna o tamanho da maior subsequencia
        palindrome de text[]

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:

        UVA 11151

    Adicionado por:

        Jorge Gabriel Siqueira

*/

#include <stdio.h>
#include <string.h>

char text[1024];
int dp[1024][1024];

int z(int l, int r)
{
    if(l > r) return dp[l][r] = 0;
    if(l == r) return dp[l][r] = 1;
    if(dp[l][r] != -1) return dp[l][r];
    if(text[l] == text[r]) return dp[l][r] = z(l + 1, r - 1) + 2;
    return dp[l][r] = max(z(l + 1, r), z(l, r - 1));
}

int longestPalindromeSubsequence()
{
    int len = strlen(text);
    for(int i=0; i<len; i++) memset(dp[i],-1,len*sizeof(int));
    return z(0,strlen(text)-1);
}

int main()
{
    strcpy(text,"aaabcaa");
    cout << longestPalindromeSubsequence() << endl;
    return 0;
}
