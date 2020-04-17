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

#define MAXSZ 100

using namespace std;

/*

    PROXIMO NUMERO PALINDROME

    Aplicacoes:

       Dado um numero K encontra o proximo numero maior
       de que K que seja palindrome.

    Como chamar a funcao:

        1) Armazenar o numero na variavel K[]

        2) Chamar a funcao find_palin()

    Resultado da funcao:

        A funcao reescreve K com o proximo numero
        palindrome.

    Complexidade do algoritmo:

        O(n)

    Problemas resolvidos:

        SPOJ PALIN

    Adicionado por:

        Jorge Gabriel Siqueira

*/

const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS)
{
    return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

char K[1000002];
int flag;

void find_palin()
{
    int len,i,tmp,t,tmp1;
    len = strlen(K);
    flag = 1;

    for(i=0; i<len; i++)
    {
        if(K[i] != '9')
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        K[0] = '1';
        for(i=1; i<len; i++)
        K[i] = '0';
        K[len] = '1';
        K[len+1] = '\0';
        return ;
    }

    flag = 0;

    for(i=0; i<len/2; i++)
    {
        if(K[i] < K[len-i-1])
        flag = -1;
        else if(K[i] > K[len-i-1])
        flag = 1;
        K[len-i-1] = K[i];
    }

    if(flag == -1 || flag==0)
    {
        t = 0;

        if(len%2 == 0) tmp1 = len/2-1;
        else tmp1 = len/2;

        while(K[tmp1-t] == '9')
        {
            K[tmp1-t] = '0';
            K[len-1-tmp1+t] = '0';
            t ++;
        }

        K[tmp1-t] ++;
        K[len-1-tmp1+t] = K[tmp1-t];
    }
}

int main()
{
    return 0;
}
