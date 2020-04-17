#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

/*

    MATRIZ INVERSA

    Aplicacoes:

        Calcula a inversa de uma matriz.

        Dizemos que uma matriz tera uma matriz inversa
        se for quadrada e se o produto das duas matrizes
        for igual a uma matriz identidade quadrada de
        mesma ordem das outras.

        Matriz identidade eh uma matriz da forma:

        1   0   ...   0
        0   1   ...   0
        .   .  .      .
        .   .    .    .
        .   .      .  .
        0   0   ...   1

    Como chamar a funcao:

        1) Armazenar em n a ordem da matriz

        2) Chamar a funcao init pra alocar a matriz
           da forma correta

        3) Popular a matriz matrix[][] com os devidos valores

        4) Chamar a funcao mat_inverse()

    Resultado da funcao:

        A funcao mat_inverse() retorna um vector<vector<double> >
        representando a matriz inversa

    Complexidade do algoritmo:

        O(n^3)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int n;
vector<vector<double> > matrix;

inline bool eq(double a, double b)
{
    static const double eps = 1e-9;
    return fabs(a - b) < eps;
}

void init()
{
    matrix.clear();
    matrix.resize(n);
    for(int i=0; i<n; i++)
    {
        matrix[i].resize(n);
    }
}

// returns empty vector if fails
vector<vector<double> > mat_inverse()
{
    int i, j, k;
    vector<vector<double> > ret;
    ret.resize(n);
    for (i = 0 ; i < n ; i++)
    {
        ret[i].resize(n);
        for (j = 0 ; j < n ; j++)
            ret[i][j] = 0;
        ret[i][i] = 1;
    }
    for (i = 0 ; i < n ; i++)
    {
        if (eq(matrix[i][i],0))
        {
            for (j = i + 1 ; j < n ; j++)
            {
                if (!eq(matrix[j][i], 0))
                {
                    for (k = 0 ; k < n ; k++)
                    {
                        matrix[i][k] += matrix[j][k];
                        ret[i][k] += ret[j][k];
                    }
                    break;
                }
            }
            if (j == n)
            {
                ret.clear();
                return ret;
            }
        }
        double tmp = matrix[i][i];
        for (k = 0 ; k < n ; k++)
        {
            matrix[i][k] /= tmp;
            ret[i][k] /= tmp;
        }
        for (j = 0 ; j < n ; j++)
        {
            if (j == i) continue;
            tmp = matrix[j][i];
            for (k = 0 ; k < n ; k++)
            {
                matrix[j][k] -= matrix[i][k] * tmp;
                ret[j][k] -= ret[i][k] * tmp;
            }
        }
    }
    return ret;
}

int main()
{

}
