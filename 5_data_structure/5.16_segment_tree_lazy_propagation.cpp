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
#include <assert.h>
#include <numeric>
#include <fstream>
#include <limits>
#include <time.h>
#include <bitset>
#define INF 0x3f3f3f3f
#define MAX 1000000
#define NOLAZY INF

using namespace std;

/*

    SEGMENT TREE WITH LAZY PROPAGATION

    Aplicacoes:

        Queries de minimo valor de elemento em sub-intervalo de um conjunto.

    Como chamar a funcao:

        1) Armazenar em n o numero de elementos do cnojunto

        2) Armazenar no vetor int array[] os elementos do conjunto

        3) Montar a Segment Tree:

            buildSegTree();

        4) Para updates unitarios:

            update(pos,val);

            para a posicao "pos" passar a ter o valor "val"

        5) Para updates de intervalos:

            update(ini,fim,val);

            para todos os elementos do intervalo [ini,fim] passarem
            a possuir o valor "val"

        5) Para queries:

            query(i,j);

    Resultado da funcao:

        query(i,j) -> retorna o valor do minimo elemento entre os
                      elementos de i a j do conjunto.

    Complexidade do algoritmo:

        update() , query() -> O( log(n) )
        queryInterval() -> Lazy propagation
        buildSegTree() -> O( n * log(n) )

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

typedef struct node
{
    node *pred;
    node *left, *right;
    int value;
    int lazy;
} node;

node *segTree;
node *cacheLeaf[MAX];
int array[MAX], n;

int buildSegTreeRec(node *segment, int l, int r)
{
    if(l == r)
    {
        cacheLeaf[l] = segment;
        segment -> lazy = NOLAZY;
        return segment -> value = array[l];
    }
    else
    {
        segment -> left = (node *)malloc(sizeof(node));
        segment -> right = (node *)malloc(sizeof(node));

        segment ->  left -> pred = segment;
        segment ->  right -> pred = segment;

        segment -> left -> lazy = NOLAZY;
        segment -> right -> lazy = NOLAZY;

        segment ->  left -> right = NULL;
        segment ->  left -> left = NULL;
        segment ->  right -> right = NULL;
        segment ->  right -> left = NULL;

        int left = buildSegTreeRec(segment ->  left, l, (l+r)/2);
        int right = buildSegTreeRec(segment ->  right, (l+r)/2+1, r);
        segment -> lazy = NOLAZY;

        return segment -> value = min(left, right);
    }
}

void buildSegTree()
{
    segTree = (node *)malloc(sizeof(node));
    segTree ->  pred = NULL;
    segTree ->  left = NULL;
    segTree ->  right = NULL;
    segTree -> lazy = NOLAZY;
    buildSegTreeRec(segTree, 0, n-1);
}

int queryRec(node *segment, int &l, int &r, int lazy, int i, int j)
{
    if(i >= l && i <= r && j >= l && j <= r) //[l,r] is totaly inside de interval [i,j]
    {
        return lazy != NOLAZY ? (segment -> lazy = segment -> value = lazy) : (segment -> value);
    }
    else if((i < l && j < l) || (i > r && j > r)) //[l,r] is totaly outside de interval [i,j]
    {
        int newLazy = segment -> pred -> lazy;
        if(newLazy != NOLAZY) segment -> lazy = segment -> value = newLazy;
        return INF;
    }
    else
    {
        int a = (i+j)/2;
        int b = a+1;
        int newLazy = (lazy != NOLAZY) ? lazy : segment -> lazy;
        segment -> lazy = newLazy;
        if(newLazy != NOLAZY) segment -> value = newLazy;
        int left = queryRec(segment -> left, l, r, newLazy, i, a);
        int right = queryRec(segment -> right, l, r, newLazy, b, j);
        segment -> lazy = NOLAZY;
        return min(left, right);
    }
}

inline int query(int l, int r)
{
    return queryRec(segTree, l, r, segTree -> lazy, 0, n-1);
}

void update(int p, int val)
{
    int left, right;
    node *segment = cacheLeaf[p];
    segment -> value = val;
    segment = segment -> pred;
    while(segment)
    {
        left = right = INF;
        if(segment -> left) left = segment -> left -> value;
        if(segment -> right) right = segment -> right -> value;
        segment -> value = min(left, right);
        segment = segment -> pred;
    }
    array[p] = val;
}

int updateIntervalRec(node *segment, int &l, int &r, int lazy, int i, int j)
{
    if(i >= l && i <= r && j >= l && j <= r) //[l,r] is totaly inside de interval [i,j]
    {
        return segment -> lazy = segment -> value = lazy;
    }
    else if((i < l && j < l) || (i > r && j > r)) //[l,r] is totaly outside de interval [i,j]
    {
        int newLazy = segment -> pred -> lazy;
        if(newLazy != NOLAZY) segment -> lazy = segment -> value = newLazy;
        return segment -> value;
    }
    else
    {
        int a = (i+j)/2;
        int b = a+1;

        if(!(i==0 && j==n-1))
        {
            int newLazy = segment -> pred -> lazy;
            if(newLazy != NOLAZY) segment -> lazy = newLazy;
        }

        int left = updateIntervalRec(segment -> left, l, r, lazy, i, a);
        int right = updateIntervalRec(segment -> right, l, r, lazy, b, j);

        segment -> lazy = NOLAZY;
        return segment -> value = min(left, right);
    }
}

inline void updateInterval(int l, int r, int val)
{
    updateIntervalRec(segTree, l, r, val, 0, n-1);
    for(int i=l; i<=r; i++) array[i] = val;
}

int main()
{
    return 0;
}
