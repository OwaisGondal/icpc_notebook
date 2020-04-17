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

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))

using namespace std;

const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

/*

    4.15 String Matching com taxa de erro aceitavel

    Aplicacoes:

       Dado uma string pattern e um texto buscar todas as
       ocorencias de substrings de pattern com ate errors edicoes

    Retorna:

        vector<int> ret : posicoes de todos os matchings
                          encontradosno texto

*/

/*

    BIT PARALLEL ALGORITHM

    Aplicacoes:

        Dado uma string pattern e um texto buscar todas
        as ocorencias de substrings de pattern com ate
        n erros de edicao.

    Como chamar a funcao:

        1) Chamar a funcao BPR(pattern, text, errors)
           onde:

            pattern -> padrao a ser buscado
            text -> texto onde o padrao sera buscado
            errors -> quantidade de erros de edicao tolerados

    Resultado da funcao:

        A funcao retorna um vector<int> contendo a posicao
        onde ocorreram os matches

    Complexidade do algoritmo:

        O(n*m), onde n eh o numero de letras do texto e
        m eh o numero de erros permitidos

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector<int> BPR(string pattern, string text, int errors)
{
    int B[256];
    memset(B, 0, sizeof(B));
    vector<int> ret;

    // Initialize all characters positions
    for (int i = 0; i < pattern.size(); i++)
    {
        B[(int)pattern[i]] |= 1 << i;
    }
    // Initialize NFA states
    int states[errors+1];
    for(int i= 0; i <= errors; i++)
    {
        states[i] = (i == 0) ? 0 : (1 << (i - 1) | states[i-1]);
    }
    //
    int oldR, newR;
    int exitCriteria = 1 << pattern.size() -1;

    for (int i = 0; i < text.size(); i++)
    {
        oldR = states[0];
        newR = ((oldR << 1) | 1) & B[text[i]];
        states[0] = newR;

        for (int j = 1; j <= errors; j++)
        {
            newR = ((states[j] << 1) & B[text[i]]) | oldR | ((oldR | newR) << 1);

            oldR = states[j];
            states[j] = newR;
        }

        if ((newR & exitCriteria) != 0)
        {
            ret.push_back(i+1);
        }
    }
    return ret;
}

int main()
{
    string text = "pato==============pateta===============caneca";
    string pattern = "pat";

    vector<int> ret = BPR(pattern,text,0);
    for(int i=0; i<ret.size(); i++) cout << ret[i] << " ";
    return 0;
}
