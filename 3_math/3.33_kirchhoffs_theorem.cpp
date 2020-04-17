#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

/*

    KIRCHHOFFS THEOREM

    Aplicacoes:

        Contar o numero de spannings trees de um grafo

    Como chamar a funcao:

        [Definicao de como deve-se chamar a funcao  ]
        [e de todas as observacoes necessarias, se  ]
        [possivel enumerar o passo-a-passo ate      ]
        [a chamada da funcao                        ]

    Resultado da funcao:

        [Definir o que a funcao retorna ou onde ela ]
        [salva os resultados                        ]

    Complexidade do algoritmo:

        [Complexidade do algoritmo: ex: O(n^2)      ]

    Problemas resolvidos:

        [Listar os problemas que ja foram           ]
        [resolvidos usando este algoritmo           ]

    Adicionado por:

        Jorge Gabriel Siqueira

*/

inline bool eq(double a, double b)
{
    return a == b;
}

double mat_det(vector<vector<double> > matrix, int n)
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

long long count_spantree(vector<int> graph[], int size)
{
    int i, j;
    vector<vector<double> > matrix(size);
    for (i = 0 ; i < size; i++)
    {
        matrix[i].resize(size - 1);
        for (j = 0 ; j < size - 1 ; j++)
            matrix[i][j] = 0;
        for (j = 0 ; j < graph[i].size() ; j++)
        {
            if (graph[i][j] < size - 1)
            {
                matrix[i][graph[i][j]]--;
                matrix[i][i]++;
            }
        }
    }
    return (long long)(mat_det(matrix, size - 1) + 0.5);
}

int main()
{
    vector<int> graph[3];

    graph[0].push_back(1);
    graph[0].push_back(1);

    graph[1].push_back(0);
    graph[1].push_back(1);

    graph[2].push_back(0);
    graph[2].push_back(1);

    cout << count_spantree(graph, 2) << endl;

    return 0;
}
