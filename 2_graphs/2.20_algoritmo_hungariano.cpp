#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#define INF 0x3f3f3f3f
#define MAXN 150

using namespace std;

/*

    HUNGARIAN ALGORITHM

    Aplicacoes:

        Maximum bipartite matching de peso maximo/minimo.

        o algoritmo resolve o problema do maximum
        bipartite matching de peso maximo. Para
        matching de peso minimo, inicializar a matriz
        de custos com custos negativos.

    Como chamar a funcao:

             1) Armazenar em n o numero de vertices em cada lado.
                Caso o numero de vertices seja diferente entre os
                dois lados, inicializar n com o meior valor entre
                eles.

             2) Inicializar cost[][] com valores que nao interfiram
                no algoritmo (geralmente 0 para maximo, INF para
                minimo)

             3) Preencher cost[][] com os valores referentes ao grafo:
                Para representar uma aresta que liga o vertice
                x ao vertice y com custo c faca:

                    cost[x][y] = c;

            4) Chame a funcao hungarian()

    Resultado da funcao:

        A funcao hungarian() retorna o valor do peso
        do maximum bipartite matching do grafo.

        A funcao deixa armazenado em xy[]: xy[x] o
        vertice casado com x, e em yx[]: yx[y] o vertice
        casado com y.

        O tamanho do maximum bipartite matching fica
        armazenado em max_match.

    Complexidade do algoritmo:

        O(n^3)

    Problemas resolvidos:

        SCITIES (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/


int cost[MAXN][MAXN];
int xy[MAXN];
int yx[MAXN];
bool S[MAXN], T[MAXN];
int lx[MAXN], ly[MAXN], slack[MAXN], slackx[MAXN], prev[MAXN];
int max_match;
int n;

void init_labels ()
{
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
            lx[x] = max(lx[x], cost[x][y]);
}

void add (int x, int prevx)
{
    S[x] = true;
    prev[x] = prevx;
    for (int y = 0; y < n; ++y)
        if (lx[x] + ly[y] - cost[x][y] < slack[y])
        {
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackx[y] = x;
        }
}

void update_labels ()
{
    int x, y, delta = INF;
    for (y = 0; y < n; ++y)
        if (!T[y])
            delta = min(delta, slack[y]);
    for (x = 0; x < n; ++x)
        if (S[x])
            lx[x] -= delta;
    for (y = 0; y < n; ++y)
        if (T[y])
            ly[y] += delta;
    for (y = 0; y < n; ++y)
        if (!T[y])
            slack[y] -= delta;
}

void augment ()
{
    if (max_match == n)
        return;
    int x, y, root;
    int q[MAXN], wr = 0, rd = 0;
    memset(S, false, sizeof(S));
    memset(T, false, sizeof(T));
    memset(prev, -1, sizeof(prev));
    for (x = 0; x < n; ++x)
        if (xy[x] == -1)
        {
            q[wr++] = root = x;
            prev[x] = -2;
            S[x] = true;
            break;
        }
    for (y = 0; y < n; ++y)
    {
        slack[y] = lx[root] + ly[y] - cost[root][y];
        slackx[y] = root;
    }
    while (true)
    {
        while (rd < wr)
        {
            x = q[rd++];
            for (y = 0; y < n; ++y)
                if (cost[x][y] == lx[x] + ly[y] && !T[y])
                {
                    if (yx[y] == -1)
                        break;
                    T[y] = true;
                    q[wr++] = yx[y];
                    add(yx[y], x);
                }
            if (y < n)
                break;
        }
        if (y < n)
            break;
        update_labels();
        wr = rd = 0;
        for (y = 0; y < n; ++y)
            if (!T[y] && slack[y] == 0)
            {
                if (yx[y] == -1)
                {
                    x = slackx[y];
                    break;
                }
                else
                {
                    T[y] = true;
                    if (!S[yx[y]])
                    {
                        q[wr++] = yx[y];
                        add(yx[y], slackx[y]);
                    }
                }
            }
        if (y < n)
            break;
    }
    if (y < n)
    {
        ++max_match;
        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty)
        {
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        augment();
    }
}

int hungarian ()
{
    int ret = 0;
    max_match = 0;
    memset(xy, -1, sizeof(xy));
    memset(yx, -1, sizeof(yx));
    init_labels();
    augment();
    for (int x = 0; x < n; ++x)
        ret += cost[x][xy[x]];
    return ret;
}

int main()
{
    return 0;
}
