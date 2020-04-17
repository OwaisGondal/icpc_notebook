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
#include <bitset>
#define INF 0x3f3f3f3f
#define MAX 1000000

using namespace std;

/*

    CLASSIC SEGMENT TREE

    Aplicacoes:

        Queries de minimo valor de elemento em sub-intervalo de um conjunto.

    Como chamar a funcao:

        1) Armazenar em n o numero de elementos do conjunto

        2) Armazenar no vetor int array[] os elementos do conjunto

        3) Montar a Segment Tree:

            buildSegTree();

        4) Para updates:

            update(pos,val);

            para a posicao "pos" passar a ter o valor "val"

        5) Para queries:

            query(i,j);

    Resultado da funcao:

        query(i,j) -> retorna o valor do minimo elemento entre os
                      elementos de i a j do conjunto.

    Complexidade do algoritmo:

        update() , query() -> O( log(n) )
        buildSegTree() -> O( n * log(n) )

    Problemas resolvidos:

        URI 1301

    Adicionado por:

        Jorge Gabriel Siqueira

*/

typedef struct node
{
    node *pred;
    node *left, *right;
    int value;
} node;

node *segTree;
node *cacheLeaf[MAX];
int array[MAX], n;

int buildSegTreeRec(node *segment, int l, int r)
{
    if(l == r)
    {
        cacheLeaf[l] = segment;
        return segment -> value = array[l];
    }
    else
    {
        segment -> left = (node *)malloc(sizeof(node));
        segment -> right = (node *)malloc(sizeof(node));

        segment ->  left -> pred = segment;
        segment ->  right -> pred = segment;

        segment ->  left -> right = NULL;
        segment ->  left -> left = NULL;
        segment ->  right -> right = NULL;
        segment ->  right -> left = NULL;

        int left = buildSegTreeRec(segment ->  left, l, (l+r)/2);
        int right = buildSegTreeRec(segment ->  right, (l+r)/2+1, r);

        return segment -> value = min(left, right);
    }
}

void buildSegTree()
{
    segTree = (node *)malloc(sizeof(node));
    segTree ->  pred = NULL;
    segTree ->  left = NULL;
    segTree ->  right = NULL;
    buildSegTreeRec(segTree, 0, n-1);
}

int queryRec(node *segment, int &l, int &r, int i, int j)
{
    if((i >= l && i <= r && j >= l && j <= r))
    {
        return segment -> value;
    }
    else
    {
        int a = (i+j)/2;
        int b = a+1;
        int p1, p2;
        p1 = p2 = INF;

        if(i >= l && i <= r || a >= l && a <= r || (i < l && a > r)) p1 = queryRec(segment -> left, l, r, i, a);
        if(b >= l && b <= r || j >= l && j <= r || (b < l && j > r)) p2 = queryRec(segment -> right, l, r, b, j);

        return min(p1,p2);
    }
}

inline int query(int l, int r)
{
    return queryRec(segTree, l, r, 0, n-1);
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

int main()
{
    return 0;
}

