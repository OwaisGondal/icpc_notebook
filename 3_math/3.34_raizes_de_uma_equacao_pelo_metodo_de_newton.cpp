#include <stdio.h>
#include <math.h>

#define epsilon 0.0000001

/*

    RAIZ DE UMA EQUACAO PELO METODO DE NEWTON

    Aplicacoes:

        Determinar a raiz de uma equacao

    Como chamar a funcao:

        1) Definir a funcao a se obter o zero em
           f(double x).

        2) Definir a devirava da funcao a se obter
        o zero em df(double x).

        3) Chamar a funcao newtonMethod(x), onde x
           eh uma estimativa para o zero da equacao

    Resultado da funcao:

        A funcao newtonMethod() retorna um zero para a
        equacao

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

/* function */
double f(double x)
{
    return(x*x - 3);
}

/* derivative of f */

double df(double x)
{
    return(2*x);
}

double newtonMethod(double initialX)
{
    double oldx, x;
    x = initialX;
    do
    {
        oldx = x;
        x = x - f(x)/df(x);
        printf("%f\n",x);
    }
    while (fabs(x-oldx) > epsilon);

    return x;
}

int main()
{

    double x;

    printf("Give an initial estimate of zero > ");
    scanf("%lf",&x);



    printf("A zero is equal to: %lf", newtonMethod(x));
}
