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
#include <math.h>
#include <sstream>
#define INF 0x3f3f3f3f

using namespace std;

/*

    Josephus Problem Solver

    Aplicacoes:

        n pessoas dispostas em um circulo, as pessoas sao numeradas de [0 .. n-1]
        e a cada intervalo k de pessoas eh morta a pessoa correspondente ao final do intervalo,
        no final sobra apenas um sobrevivete(Josephus).

    Como chamar a funcao:

        1) Chamar a funcao int Josephus(int n, int k)

            int n -> quantidade de pessoas
            int k -> intervalo no qual cada pessoa morre

    Resultado da funcao:

        Funcao Josephus retorna a pessoa sobrevivente

    Complexidade do algoritmo:

       O(n) se K>2 e O(1) se K<=2

    Problemas resolvidos:

    Adicionado por:
        Fulvio Abrahao
*/

int Josephus(int n, int k){
        if(k == 1)return n-1;
        if(k == 2){
            int j = floor(log10(n)/log10(2.0));
            n &= ~(1<<j);
            n = n<<1;
            n|=1;
            return n-1;
        }

        if(n==1)return 0;
        return (Josephus(n-1,k)+k)%n;
}

int main()
{

    return 0;
}
