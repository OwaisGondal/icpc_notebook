#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

/*

    LSP - LONGEST SUBSET PALINDROME

    Aplicacoes:

        Encontrar a maior subsequencia palindrome de um texto

    Como chamar a funcao:

        1) Deve-se inicialmente colocar o texto original na string "s"
           se houver restricoes (como desconsiderar maiusculas e
           minusculas ou ignorar simbols de pontuacao) deve-se tratar
           estes casos e armazenar esta string em ss, caso nao existam
           restricoes simplesmente copie a string "s" para a string "ss"

        2) Chame a funcao lsp()

        Observacao: Cuidado com a complexidade, algoritmo indicado para
        textos longos com matches de palindromes pequenos

    Resultado da funcao:

        A funcao armazena em:

            string output -> armazena a maior subsequencia palindrome
            int maxl -> armazena o tamanho de output

    Complexidade do algoritmo:

        O(n*m), onde m eh o tamanho da maior substring palindrome e
        n eh o tamanho do texto (armazenado em ss)

    Problemas resolvidos:

        USACO 1.3.3

    Adicionado por:

        Jorge Gabriel Siqueira

*/

string s, ss;
int maxp, maxq, maxl = 0;
string output;

void findpal (int p, int q)
{
    int i=-1, j=-1;
    while (p >= 0 && q < ss.size() && ss[p] == ss[q])
    {
        i = p;
        j = q;
        p--;
        q++;
    }

    if (i != -1 && j != -1 && j - i + 1 > maxl)
    {
        maxp = i;
        maxq = j;
        maxl = j - i + 1;
    }
}

void lsp()
{
    maxl = 0;
    for (int i = 1; i < ss.size(); i++)
    {
        //odd palindrome
        findpal (i - 1, i + 1);
        //even palindrome
        findpal (i - 1, i);
    }

    output = "";
    int alpha = -1;

    for (int i = 0; i < s.size() && maxq >= alpha + 1; i++)
    {
        if (isalpha (s[i]))
            alpha++;
        if (maxp <= alpha && maxq >= alpha)
            output += s[i];
    }
}

int main()
{
    s = ss = "aaabcaa";
    lsp();
    assert(output == "aaa" && maxl == 3);

    s = ss = "sdabccbagfa";
    lsp();
    assert(output == "abccba" && maxl == 6);

    s = ss = "gaaasmcfjafsdmadamimadamasdagsaksdj";
    lsp();
    assert(output == "madamimadam" && maxl == 11);

    s = "Confucius say: Madam, I'm Adam.";
    ss = "confuciussaymadamimadam";
    lsp();
    assert(output == "Madam, I'm Adam" && maxl == 11);

    return 0;
}
