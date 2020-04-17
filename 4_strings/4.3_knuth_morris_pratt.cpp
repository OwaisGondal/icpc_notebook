#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

/*

    KNUTH MORRIS PRATT

    Aplicacoes:

        Busca de um padrao em um texto de forma eficiente.
        obs: a funcao strstr (char* text, char* pattern) da biblioteca
        <cstring> implementa KMP (C-ANSI). a funcao retorna a primeira
        ocorrencia do padrao no texto, KMP retorna todas!

    Como chamar a funcao:

        1) Chamar a funcao kmp(text, pattern)

    Resultado da funcao:

        A funcao armazena em:

            nres -> O numero de ocorrencias do padrao no texto
            res[] -> posicoes das nres ocorrencias do padrao no texto

    Complexidade do algoritmo:

        O(n)

    Problemas resolvidos:

        QUADRADO (SPOJ BR)
        PLAGIO (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

#define MAXN 100001 //tamanho maximo da string
int pi[MAXN], res[MAXN], nres;
void kmp (string text, string pattern)
{
    nres = 0;
    pi[0] = -1;
    for (int i = 1; i < pattern.size(); ++i)
    {
        pi[i] = pi[i-1];
        while (pi[i] >= 0 && pattern[pi[i] + 1] != pattern[i])
            pi[i] = pi[pi[i]];
        if (pattern[pi[i] + 1] == pattern[i])
            ++pi[i];
    }
    int k = -1;  //k + 1 eh o tamanho do match atual
    for (int i = 0; i < text.size(); ++i)
    {
        while (k >= 0 && pattern[k + 1] != text[i])
            k = pi[k];
        if (pattern[k + 1] == text[i])
            ++k;
        if (k + 1 == pattern.size())
        {
            res[nres++] = i - k;
            k = pi[k];
        }
    }
}

int main()
{
    return 0;
}
