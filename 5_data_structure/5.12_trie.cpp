#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

/*

    TRIE

    Aplicacoes:

        A arvore trie pode substituir uma tabela hash.
        Eh comumente usada para localizar uma palavra em
        um dicionario.

    Como chamar a funcao:

        1) Criar uma Trie:

            Trie t;

        2) Inserir palavras no dicionario da Trie:

            insert("word", &t);

        3) Para verificar se uma palavra encontra-se
           no dicionario chamar:

                find("word",&t);

    Resultado da funcao:

        A funcao find() retorna:

            true -> caso a palavra esteja no dicionario
            false -> caso contrario

    Complexidade do algoritmo:

        O(m) no pior caso, onde m eh o tamanho da maior
        palavra do dicionario.

    Problemas resolvidos:

        URI 1284

    Adicionado por:

        Jorge Gabriel Siqueira

*/

struct Trie
{
    bool end;

    Trie *next[0x100];

    Trie()
    {
        end = false;
        fill(next, next+0x100, (Trie*)0);
    }
};

void insert(char *t, Trie *r)
{
    for (int i = 0; t[i]; ++i)
    {
        char c = t[i];

        if (!r->next[c])
        {
            r -> next[c] = new Trie;
        }

        r = r->next[c];
    }

    r -> end = true;
}

bool find(char *t, Trie *r)
{
    for (int i = 0; t[i]; ++i)
    {
        char c = t[i];

        if (!r->next[c]) return false;

        r = r->next[c];
    }

    return r -> end;
}

int main()
{
    Trie t;
    insert("jorge1",&t);
    cout << find("jorge",&t);
    return 0;
}
