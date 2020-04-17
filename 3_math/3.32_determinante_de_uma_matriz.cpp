#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

/*

    DETERMINANTE DE UMA MATRIZ

    Aplicacoes:

        Calcula o determinante de uma matriz quadrada

    Como chamar a funcao:

        1) Chamar a funcao mat_det(matrix, n) onde:

            matrix -> vector< vector<double> > representando
                      a matriz

            n -> Ordem da matriz

    Resultado da funcao:

        A funcao retorna o valor do determinante da matriz
        representada na variavel matrix.

    Complexidade do algoritmo:

        O(n^2)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/


inline bool eq(double a, double b)
{
    static const double eps = 1e-9;
    return (a - eps < b && b < a + eps);
}

double mat_det(vector< vector<double> > matrix, int n)
{
    int i, j, k;
    double ret = 1;
    for (i = 0 ; i < n ; i++)
    {
        if (eq(matrix[i][i], 0))
        {
            for (j = i + 1 ; j < n ; j++)
            {
                if (!eq(matrix[j][i], 0))
                {
                    for (k = 0 ; k < n ; k++)
                        matrix[i][k] += matrix[j][k];
                    break;
                }
            }
            if (j == n)
                return 0;
        }
        double tmp = matrix[i][i];
        for (k = 0 ; k < n ; k++)
            matrix[i][k] /= tmp;
        ret *= tmp;
        for (j = 0 ; j < n ; j++)
        {
            if (j == i) continue;
            tmp = matrix[j][i];
            for (k = 0 ; k < n ; k++)
                matrix[j][k] -= matrix[i][k] * tmp;
        }
    }
    return ret;
}

int main()
{

}
