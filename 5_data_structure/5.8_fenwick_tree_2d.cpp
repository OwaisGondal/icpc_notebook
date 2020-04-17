#include <stdio.h>
#include <string.h>
#define MAXN 1000
#define MAXM 1000

/*

    FENWICK TREE 2D

    Aplicacoes:

        Determinar a soma dos elementos contidos em
        um sub-retangulo de uma matriz nxm.

    Como chamar a funcao:

        1) Armazenar as dimensoes da matriz em n(linhas)
           e m(colunas)

        2) Chamar a funcao create() para criar a arvore

        3) Para somar o valor inc a posicao (x,y) da
           matriz chamar:

                update(x,y,inc);

        4) Para saber a soma do sub-retangulo com
           canto superior esquerdo (x1,y1) e canto inferior
           direito (x2,y2) chamar:

                query(x1,y1,x2,y2);

    Resultado da funcao:

        A funcao query(x1,y1,x2,y2) retorna a soma do intervalo
        com canto superior esquerdo (x1,y1) e canto inferior
        direito (x2,y2).

    Complexidade do algoritmo:

        Queries em O(log(n)*log(m))

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int tree[MAXN][MAXM]; //arvore
int matrix[MAXN][MAXM]; //matriz original
int n, m; //dimensoes da matriz

void create ()
{
    for (int i = 0; i < n; ++i)
    {
        memset (tree[i], 0, sizeof(int)*m);
        memset (matrix[i], 0, sizeof(int)*m);
    }
}

int query2 (int x, int y)
{
    int sum;
    for (sum = 0; y >= 0; y = (y&(y+1))-1)
        sum += tree[x][y];
    return sum;
}

int query (int x1, int y1, int x2, int y2)
{
    int sum;
    if (x1 != 0)
        return query(0,y1,x2,y2) - query(0,y1,x1-1,y2);
    for (sum = 0; x2 >= 0; x2 = (x2&(x2+1))-1)
    {
        sum += query2 (x2,y2);
        if (y1)
            sum -= query2 (x2,y1-1);
    }
    return sum;
}

void update (int x, int y, int incremento)
{
    int y2;
    matrix[x][y] += incremento;
    for (; x < n; x |= x + 1)
        for (y2 = y; y2 < m; y2 |= y2 + 1)
            tree[x][y2] += incremento;
}

int main()
{
    return 0;
}
