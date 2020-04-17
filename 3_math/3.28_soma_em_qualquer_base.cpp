#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

/*
    Aplicacoes:

        Dados dois numeros em uma certa base, retorna a soma
        destes numeros.

    Parametros

            a -> numero a ser somado armazenado em forma de string
            b -> numero a ser somado armazenado em forma de string
            base -> a base que os numeros a e b estao representados

    Obs. Para bases acima de 10, onde existem letras no numero,
    armazenar as letras na forma maiuscula.

    O range R de bases suportado e: 2 <= R <= 36

*/

int getVal(char n)
{
    if(n >= '0' && n <= '9') return n-'0';
    else return n-'A'+10;
}

char getSimbol(int n)
{
    if(n >= 0 && n <= 9) return n+'0';
    else return (n-10)+'A';
}

string soma(string a, string b, int base)
{
    int posA = a.size()-1;
    int posB = b.size()-1;
    int localSum;
    int vaiUm = 0;
    string resposta = "";

    while(posA >= 0 || posB >= 0)
    {
        localSum = vaiUm;
        vaiUm = 0;

        if(posA >= 0) localSum += getVal(a[posA--]);
        if(posB >= 0) localSum += getVal(b[posB--]);

        if(localSum >= base)
        {
            vaiUm = 1;
            localSum -= base;
        }
        resposta.push_back(getSimbol(localSum));
    }

    if(vaiUm == 1) resposta.push_back('1');

    reverse(resposta.begin(), resposta.end());
    return resposta;
}

int main()
{
    return 0;
}
