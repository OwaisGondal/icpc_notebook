#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

/*

    BHASKARA QUADRATIC POLYNOMIALS ROOTS

    Aplicacoes:

        Encontrar as raizes de uma equacao de segundo grau

    Como chamar a funcao:

        1) Chamar a funcao baskara(a,b,c), onde:

            a -> multiplicado de x^2
            b -> multiplicado de x^1
            c -> multiplicado de x^0

    Resultado da funcao:

        A funcao retorna um pair<int,int> contendo
        em first e second as duas raizes da equacao

        Caso a equacao nao possua raizes a funcao retorna
        pair<int,int>(INF,INF);

    Complexidade do algoritmo:

        O(1)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

pair<double,double> bhaskara(double a, double b, double c)
{
    double delta = b*b - 4*a*c;
    if(delta < 0) return pair<int,int>(INF,INF);
    double x1 = (-b + sqrt(delta))/(2.0*a);
    double x2 = (-b - sqrt(delta))/(2.0*a);
    return pair<double,double>(x1,x2);
}

int main()
{
    //8000 -720 12
    pair<double,double> root = bhaskara(12,-720,8000);
    cout << root.first << endl << root.second << endl;
}
