#include <stdio.h>
#include <iostream>

using namespace std;

/*

    BRENT CYCLE DETECTION ALGORITHM

    Aplicacoes:

        Dada uma funcao y = f(x) e um valor inicial x0,
        determinar as caracteristicas do ciclo presente
        na sequencia (x0, f(x0), f(f(x0)), f(f(f(x0))),..)

    Como chamar a funcao:

        1) Definir a funcao em function()

        2) Chamar brent(x0)

    Resultado da funcao:

        A funcao brent() retorna um pair<int,int> :

            first -> O indice a partir do qual o ciclo
                     se inicia.

            second -> O tamanho do ciclo.

    Complexidade do algoritmo:

        O(mu + lambda), onde mu eh o indice a partir
        do qual o ciclo se inicia e lambda eh o
        tamanho do ciclo.

    Problemas resolvidos:

        UVA 350

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int z, j, m;

int function (int x)
{
    return (z*x + j)%m;
}

pair<int,int> brent(int x0)
{
    int p = 1, l = 1;
    int t = x0;
    int h = function(x0);
    //determina o tamanho do ciclo
    while (t != h)
    {
        if (p == l)
        {
            t = h;
            p *= 2;
            l = 0;
        }
        h = function(h);
        ++l;
    }
    //determina o indice de inicio do ciclo

    int u = 0;
    t = h = x0;

    for (int i = l; i != 0; --i)
        h = function(h);

    while (t != h)
    {
        t = function(t);
        h = function(h);
        ++u;
    }

    return make_pair(u, l);
}

int main()
{
    return 0;
}
