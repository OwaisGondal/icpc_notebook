#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 100001
#define LOGNMAX 17 //log2(MAXN)

using namespace std;

/*

    LCA - LOWEST COMMON ANCESTOR

    Aplicacoes:

        -> Menor ancestral comum entre 2 vertices de uma arvore

        -> Distancia entre 2 vertices de uma arvore (otimo quando
           se tem que realizar sucessivas consultas seguidas!)

    Como chamar a funcao:

        1) Armazenar em n o numero de nos da arvore

        2) Para armazenar um  aresta que liga o no x ao no y
           com custo c, faca:

                graph[x].push_back(no(y,c));
                graph[y].push_back(no(x,c));
                (Dupla direcao!!!)

        3) Monte a arvore chamando a funcao pre_process()

        4) Para saber o menor ancestral comum entre o vertice
           a e b chame a funcao LCA(a,b)

    Resultado da funcao:

        A funcao LCA(a,b) retona um  pair <int, long long> onde:

            first -> Menor Ancestral Comum de a e b
            second -> Distancia de a ate b

    Complexidade do algoritmo:

        O(?) -> construcao

    Problemas resolvidos:

        ANTS10 (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

struct X
{
    long long int v, c; //aresta[i][j] = 20 ---> v = j, c = 20
};

X no (long long int v, long long int c)
{
    X novo;
    novo.v = v;
    novo.c = c;
    return novo;
}

vector <X> graph[MAXN];
long long int pai[MAXN][LOGNMAX], distancia[MAXN][LOGNMAX], prof[MAXN];
int n;

void monta (long long int v, long long int p, long long int pro, long long int d)
{
    prof[v] = pro;
    pai[v][0] = p;
    distancia[v][0] = d;
    for (int i = 1; i < LOGNMAX; i++)
    {
        pai[v][i] = pai[pai[v][i-1]] [i-1];
        distancia[v][i] = distancia[v][i-1] + distancia[pai[v][i-1]][i-1];
    }
    for (int i = 0; i < graph[v].size(); ++i)
    {
        if (graph[v][i].v == p)
            continue;
        monta (graph[v][i].v, v, pro + 1, graph[v][i].c);
    }
}

void pre_process()
{
    prof[0] = 0;
    for (int i = 0; i < LOGNMAX; ++i)
    {
        pai[0][i] = 0;
        distancia[0][i] = 0;
    }
    for (int i = 0; i < graph[0].size(); ++i)
        monta(graph[0][i].v, 0, 1, graph[0][i].c);
}

pair <int, long long int> LCA (int a, int b)
{
    long long int d = 0;
    int pa = a, pb = b;
    if (prof[pb] > prof[pa])
        swap(pa, pb);
    while (prof[pa] > prof[pb])
    {
        int j = 0;
        for (int i = 0; i < LOGNMAX; ++i)
        {
            if (prof[pai[pa][i]] < prof[pb])
                break;
            j = i;
        }
        d += distancia[pa][j];
        pa = pai[pa][j];
    }
    while (pa != pb)
    {
        int j = 0;
        for (int i = 0; i < LOGNMAX; ++i)
        {
            if (pai[pa][i] == pai[pb][i])
                break;
            j=i;
        }
        d += distancia[pa][j];
        d += distancia[pb][j];
        pa = pai[pa][j];
        pb = pai[pb][j];
    }
    return make_pair(pa, d);
}

int main()
{
    return 0;
}
