#include <stdio.h>
#include <math.h>

/*

    SOMA DOS DIVISORES DE UM NUMERO

    Aplicacoes:

        Determinar a soma de todos os divisores de um numero

        Exemplo:

            somaDiv(36) -> 1 + 2 + 3 + 4 + 6 + 9 + 12 + 18 = 55

    Como chamar a funcao:

        1) Chame a funcao somaDiv(n)

    Resultado da funcao:

        A funcao somaDiv(n) retorna a soma dos divisores de n

    Complexidade do algoritmo:

        O(sqrt(n))

    Problemas resolvidos:

        URI 1164

    Adicionado por:

        Jorge Gabriel Siqueira

*/

int somaDiv(int n)
{
    int i;
    int sum = 1;

    double limite = sqrt(n);

    if(n==1) return 0;

    for(i=2;i<limite;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            sum+=n/i;
        }
    }

    if(i*i==n) sum += i;

    return sum;
}

int main()
{

}
