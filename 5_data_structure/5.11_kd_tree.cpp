#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

/*

    KD-TREE

    Aplicacoes:

        Dado um conjunto S de pontos e um ponto P de
        coordenadas (x,y), determina de forma eficiente
        A distancia do ponto mais proximo de P do conjunto
        S (e que seja diferente de P)

    Como chamar a funcao:

        1) Armazenar em n o numero de pontos do conjunto

        2) Armazenar os pontos no vetor P[] a partir da
           posicao 0.

        3) Chamar a funcao initialize() para inicializar a
           arvore

           Obs.: A funcao destroi o vetor P[], se precisar manter
                 os dados salve em um vetor auxiliar.

        4) Chamar a funcao query(P) para consultar qual o
           ponto X do conjunto S esta mais proximo do
           ponto P. A funcao retorna um long long
           que eh a distancia entre P e X ao quadrado.

    Resultado da funcao:

        A funcao query(P) retorna retorna a distancia
        euclidiana minima de um ponto X do conjunto S
        ao ponto P.

        Para descobrir a distancia real, faca:

            double d = sqrt(query(P));

    Complexidade do algoritmo:

        O(log n) -> Query

    Problemas resolvidos:

        MLE (SPOJ)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

#define MAXN 101000

struct ponto
{
    long long axis [2];
};

ponto P[MAXN]; //conjunto de pontos
ponto PNode[MAXN];
long long minDist;
int esq[2*MAXN], dir[2*MAXN], at;
int root; //raiz da arvore
int n; //numero de pontos do conjunto

bool cmpX (ponto p1, ponto p2)
{
    if (p1.axis[0] != p2.axis[0])
        return p1.axis[0] < p2.axis[0];
    return p1.axis[1] < p2.axis[1];
}

bool cmpY (ponto p1, ponto p2)
{
    if (p1.axis[1] != p2.axis[1])
        return p1.axis[1] < p2.axis[1];
    return p1.axis[0] < p2.axis[0];
}

int make_tree (int ini , int fim , int axis)
{
    if (ini + 1 == fim)
    {
        int root = at++;
        PNode[root] = P[ini];
        esq[root] = dir[root] = -1;
        return root;
    }
    else if (ini + 1 > fim)
    {
        return -1;
    }
    int root = at++;
    int meio = (ini + fim)/2;
    if (!axis)
    {
        nth_element(P + ini, P + meio, P + fim, cmpX);
    }
    else
    {
        nth_element(P + ini, P + meio, P + fim, cmpY);
    }
    PNode[root] = P[meio];
    esq[root] = make_tree(ini, meio, 1 - axis);
    dir[root] = make_tree(meio + 1, fim, 1 - axis);
    return root;
}

void initialize ()
{
    at = 0;
    root = make_tree(0, n, 0);
}

long long dist (ponto p1, ponto p2, int axis = -1)
{
    if (axis == -1)
    {
        return (p1.axis[0] - p2.axis[0]) * (p1.axis[0] - p2.axis[0]) +
               (p1.axis[1] - p2.axis[1]) * (p1.axis[1] - p2.axis[1]);
    }
    else
    {
        return (p1.axis[axis] - p2.axis[axis])*(p1.axis[axis] - p2.axis[axis]);
    }
}

void query (ponto p, int root, int axis = 0)
{
    if (root == -1)
        return;
    long long d = dist (p, PNode[root]);
    if (d != 0LL)
    {
        minDist = (minDist != -1LL) ? min(minDist, d) : d;
    }
    if (p.axis[axis] < PNode[root].axis[axis])
    {
        query(p, esq[root], 1 - axis);
        if (dist(p, PNode[root], axis) <= minDist)
        {
            query(p, dir[root], 1-axis);
        }
    }
    else
    {
        query(p, dir[root], 1 - axis);
        if (dist(p, PNode[root], axis) <= minDist)
        {
            query(p, esq[root], 1-axis);
        }
    }
}

long long query (ponto p)
{
    minDist = -1LL;
    query (p, root, 0);
    return minDist;
}

int main()
{
    return 0;
}
