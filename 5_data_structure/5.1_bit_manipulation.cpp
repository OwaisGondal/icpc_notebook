#include <math.h>
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

/*

    BIT MANIPULATION

    Aplicacoes:

        Biblioteca de manipulacao binaria

    Funcoes suportadas:

        isOn()

            Parametros:

                S -> numero em representacao decimal
                j -> posicao do bit a ser analisada

            Retorna:

                Valor diferente de 0 -> o bit esta ativo
                0 -> o bit esta inativo

        setBit()

            Parametros:

                S -> numero em representacao decimal
                j -> posicao do bit a ser setado

            Funcao:

                Seta o j-esimo bit para 1

        clearBit()

            Parametros:

                S -> numero em representacao decimal
                j -> posicao do bit a ser setado

            Funcao:

                Seta o j-esimo bit para 0

        toggleBit()

            Parametros:

                S -> numero em representacao decimal
                j -> posicao do bit a ser setado

            Funcao:

                Seta o j-esimo bit para 0, caso ele seja 1
                Seta o j-esimo bit para 1, caso ele seja 0

        lowBit()

            Parametros:

                S -> numero em representacao decimal

            Retorna:

                2^n, onde n eh a posicao do bit menos
                significativo setado como 1

        setAll()

            Parametros:

                S -> numero em representacao decimal
                n -> numero de bits a serem setados

            Funcao:

                Seta os n primeiros bits de S para 1

        modulo()

            Parametros:

                x -> numero em representacao decimal
                N -> numero em representacao decimal

            Retorna:

                x % N, onde N eh uma potencia de 2

        isPowerOfTwo()

            Parametros:

                x -> numero em representacao decimal

            Retorna:

                true -> o numero eh uma potencia de 2
                false -> o numero nao eh uma potencia de 2

        nearestPowerOfTwo()

            Parametros:

                x -> numero em representacao decimal

            Retorna:

                A potencia de 2 mais proxima de x

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(x, N) ((x) & (N - 1))   //
#define isPowerOfTwo(x) ((x & (x - 1)) == 0)
#define nearestPowerOfTwo(x) ((int)pow(2.0, (int)((log((double)x) / log(2.0)) + 0.5)))

void printSet(int _S) //Imprime na representacao binaria
{
    printf("S = %2d = ", _S);
    stack<int> st;
    while (_S)
        st.push(_S % 2), _S /= 2;
    while (!st.empty())
        printf("%d", st.top()), st.pop();
    printf("\n");
}

int main()
{

}
