#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#define MAX 10006

using namespace std;

/*

    TREE ISOMORPHISM

    Aplicacoes:

        Isomorfismo em arvores. Determinar se duas
        arvores com indices de nos distintos tem a
        mesma forma.

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo

        2) Limpar as listas de adjacencias A e B da
           posicao 0 ate a posicao n.

           for(int i=0; i<=n; i++)
           {
                A[i].clear();
                B[i].clear();
           }


        3) Armazenar a arvore 1 em A e a arvore 2 em B
           como lista de adjacencias.

           Importante: o range de vertices eh de 1 a n (inclusive)

        4) Chamar a funcao treeIsomorphism()

    Resultado da funcao:

        A funcao treeIsomorphism() retorna:

            true: Caso a arvore a seja isomorfica com b
            false: caso contrario

    Complexidade do algoritmo:

        O(n*log(n))

    Problemas resolvidos:

        UVA 12489
        URI 1229

    Adicionado por:

        Jorge Gabriel Siqueira

*/


vector<int> A[MAX], B[MAX];
vector<int> NA[MAX], NB[MAX];
int n;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for(int i=0; i<a.size(); i++)
    {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

bool eq(const vector<int>& a, const vector<int>& b)
{
    if (a.size() != b.size()) return false;
    for(int i=0; i<a.size(); i++)
    {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool treeIsomorphism()
{
    memset(NA, 0, sizeof(NA));
    memset(NB, 0, sizeof(NB));

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<A[i].size(); j++)
            NA[i].push_back(A[A[i][j]].size());
        sort(NA[i].begin(), NA[i].end());

        for(int j=0; j<B[i].size(); j++)
            NB[i].push_back(B[B[i][j]].size());
        sort(NB[i].begin(), NB[i].end());
    }

    sort(NA+1, NA+n+1, comp);
    sort(NB+1, NB+n+1, comp);

    bool equals = true;
    for(int i=1; i<=n; i++) equals &= eq(NA[i], NB[i]);
    return equals;
}

int main()
{
    return 0;
}
