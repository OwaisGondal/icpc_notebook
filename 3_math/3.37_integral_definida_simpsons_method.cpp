#include <stdio.h>

/*

    INTEGRAL DEFINIDA PELO METODO DE SIMPSON

    Aplicacoes:

        Encontrar a integral definida de uma funcao

    Como chamar a funcao:

        1) Definir a funcao a se obter o zero em
           f(double x).

        2) Chamar a funcao simpsons(a,b,n), onde:

            a -> Inicio do intervalo da funcao f()
            b -> Fim do intervalo da funcao f()
            n -> Numero de iteracoes

    Resultado da funcao:

        A funcao retorna o valor da integral definida
        de f() em [a,b]

    Complexidade do algoritmo:

        O(n)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

double f(double x)
{
    return(x*x) ;
}

double simpsons(double a, double b, int n)
{
    double delta = delta = (b-a)/n;
    double integral = 0.0;
    int i;


    for (i=0; i < n; i=i+1)
        integral = integral + (f(a+i*delta)+4*f(a+(i+0.5)*delta)+f(a+(i+1)*delta))/6*delta;

    return integral;
}

int main()
{
    printf("The integral of f from %f to %f is equal to %.18f\n",0.0,1.0,simpsons(0.0,1.0,100000));
}
