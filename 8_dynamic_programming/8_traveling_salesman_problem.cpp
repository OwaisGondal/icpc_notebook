#include <stdio.h>
#include <iostream>

using namespace std;

/*
    Aplicacoes:

        O problema do caixeiro viajante eh um problema
        que tenta determinar a menor rota para percorrer
        uma serie de cidades (visitando cada uma pelo
        menos uma vez), retornando a cidade de origem.
        Ele e um problema de otimizacao NP-Completo
        inspirado na necessidade dos vendedores em realizar
        entregas em diversos locais (as cidades) percorrendo
        o menor caminho possivel, reduzindo o tempo necessario
        para a viagem e os possiveis custos com transporte
        e combustivel.


*/

int n, grafo[11][11], memo[11][1 << 11];

int tsp(int pos, int bitmask)   // bitmask stores the visited coordinates
{
    if (bitmask == (1 << (n + 1)) - 1) return grafo[pos][0]; // return trip to close the loop

    if (memo[pos][bitmask] != -1) return memo[pos][bitmask];

    int ans = 2000000000;

    for (int nxt = 0; nxt <= n; nxt++) // O(n) here
        if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
            ans = min(ans, grafo[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));

    return memo[pos][bitmask] = ans;
}

int main()
{

}
