#include <stdio.h>
#include <string.h>
#include <map>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

/*

    AHO CORASICK

    Aplicacoes:

        String matching de varios padroes simultaneamente

    Como chamar a funcao:

        1) Chamar a funcao initialize() para inicializar a
           estrutura.

        2) Adicionar os padroes (palavras do dicionario)
           por meio da funcao addPattern(s), onde s eh o
           padrao a ser adicionado.

        3) Chamar a funcao goFails() apos a insercao de todos
           os padroes para montar a arvore de padroes.

        4) Chamar a funcao query(s) para consultar se as
           palavras do dicionario encontram-se no texto s
           passado como parametro.

    Resultado da funcao:

        A resposta da query eh dada pelo vetor de listas
        "list<int> pos[MAX_PAD]".

        Para saber se um padrao foi encontrado no texto utilizar:

            list<int> ocorrencias = aut.pos[aut.pad[pattern]], onde
            pattern eh um dos padroes adicionados ao dicionario

        A lista contera os indices do texto onde o padrao "pattern"
        foi encontrado.

        Se a lista estiver vazia eh porque o padrao nao foi
        encontrado no texto!

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        UVA 10679

    Adicionado por:

        Jorge Gabriel Siqueira

*/

#define NULO -1
#define MAX_NO 100010
#define MAX_PAD 10010 //numero maximo de padroes

typedef map <char, int> mapach;
typedef map <string, int> mapastr;

struct automata
{
    mapach trans[MAX_NO];
    mapastr pad;
    list<int> pos[MAX_PAD]; //resposta para o problema!!!
    int falha[MAX_NO], final[MAX_NO], tam[MAX_PAD], numNos;
    automata (): numNos(0) {}

    void initialize ()
    {
        memset(falha, NULO, sizeof(falha));
        memset(final, NULO, sizeof(final));

        for (int i = 0; i < numNos; ++i) trans[i].clear();

        pad.clear();
        numNos = 1;
    }

    int addPattern (const char* s)
    {
        pair <mapach::iterator, bool> pch;
        int i, no = 0, numPad = pad.size();

        if (pad.count(s)) return pad[s];
        else pad.insert(make_pair(s, numPad));

        for (i = 0; s[i]; ++i)
        {
            if ((pch = trans[no].insert(make_pair(s[i], numNos))).second) ++numNos;
            no = pch.first -> second;
        }

        tam[numPad] = i ? i : 1;
        return final[no] = numPad;
    }

    void goFails ()
    {
        queue <int> fila;
        int filho;

        for (typeof(trans[0].begin()) it = trans[0].begin(); it != trans[0].end(); ++it)
        {
            falha[filho = it->second] = 0;
            fila.push(filho);
        }

        while (!fila.empty())
        {
            int atual = fila.front();
            fila.pop();
            for (typeof(trans[atual].begin()) it = trans[atual].begin(); it != trans[atual].end(); ++it)
            {
                char c = it->first;
                filho = it->second;
                int ret = falha[atual];

                while (ret != NULO && !trans[ret].count(c)) ret = falha[ret];

                if (ret != NULO)
                {
                    falha[filho] = trans[ret][c];
                    if (final[filho]==NULO && final[falha[filho]]!=NULO) final[filho] = final[falha[filho]];
                }
                else if (trans[0].count(c)) falha[filho] = trans[0][c];

                fila.push(filho);
            }
        }
    }

    void query (const char* s)
    {
        int ret, atual = 0, i = 0;
        int N = pad.size();

        for (int j = 0; j < N; j++) pos[j].clear();

        do
        {
            while(atual != NULO && !trans[atual].count(s[i])) atual = falha[atual];

            atual = (atual == NULO) ? 0 : trans[atual][s[i]];

            for (ret = atual; ret != NULO && final[ret] != NULO; ret = falha[ret])
            {
                pos[final[ret]].push_back(i - tam[final[ret]] + 1);
                while (falha[ret]!=NULO && final[falha[ret]]==final[ret]) ret = falha[ret];
            }
        }
        while (s[i++]);
    }
};

int main()
{
    return 0;
}
