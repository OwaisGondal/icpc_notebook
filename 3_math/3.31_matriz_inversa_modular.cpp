#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

/*

    MATRIZ INVERSA MODULAR

    Aplicacoes:

        Calcula a inversa de uma matriz modulo m.

        Dizemos que uma matriz tera uma matriz inversa
        modular se for quadrada e se o produto das duas
        matrizes modulo m for igual a uma matriz
        identidade quadrada de mesma ordem das outras.

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

        4) Chamar a funcao mat_inverse(mod), onde mod eh
           o valor do modulo

    Resultado da funcao:

        A funcao mat_inverse() retorna um vector<vector<double> >
        representando a matriz inversa

    Complexidade do algoritmo:

        O(n^3)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector<vector<long long> > matrix;
int n;

pair<long long, long long> extended_gcd(long long a, long long b)
{
    if (b == 0) return make_pair(1, 0);
    pair<long long, long long> t = extended_gcd(b, a % b);
    return make_pair(t.second, t.first - t.second * (a / b));
}

long long modinverse(long long a, long long m)
{
    return (extended_gcd(a, m).first % m + m) % m;
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
vector<vector<long long> > mat_inverse(long long mod)
{
    int i, j, k;
    vector<vector<long long> > ret;
    ret.resize(n);
    for (i = 0 ; i < n ; i++)
    {
        ret[i].resize(n);
        for (j = 0 ; j < n ; j++)
            ret[i][j] = 0;
        ret[i][i] = 1 % mod;
    }
    for (i = 0 ; i < n ; i++)
    {
        if (matrix[i][i] == 0)
        {
            for (j = i + 1 ; j < n ; j++)
            {
                if (matrix[j][i] != 0)
                {
                    for (k = 0 ; k < n ; k++)
                    {
                        matrix[i][k] = (matrix[i][k] + matrix[j][k]) % mod;
                        ret[i][k] = (ret[i][k] + ret[j][k]) % mod;
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
        long long tmp = modinverse(matrix[i][i], mod);
        for (k = 0 ; k < n ; k++)
        {
            matrix[i][k] = (matrix[i][k] * tmp) % mod;
            ret[i][k] = (ret[i][k] * tmp) % mod;
        }
        for (j = 0 ; j < n ; j++)
        {
            if (j == i) continue;
            tmp = matrix[j][i];
            for (k = 0 ; k < n ; k++)
            {
                matrix[j][k] -= matrix[i][k] * tmp;
                matrix[j][k] = (matrix[j][k] % mod + mod) % mod;
                ret[j][k] -= ret[i][k] * tmp;
                ret[j][k] = (ret[j][k] % mod + mod) % mod;
            }
        }
    }
    return ret;
}

int main()
{

}
