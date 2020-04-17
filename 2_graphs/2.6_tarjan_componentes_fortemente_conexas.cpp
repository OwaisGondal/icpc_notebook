#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 1000

using namespace std;

/*

    TARJAN'S STRONGLY CONNECTED COMPONENTS ALGORITHMS

    Aplicacoes:

        Decomposicao de um grafo direcionado desconexo
        em suas componentes fortemente conexas.
        2-SAT
        Etc.

    Como chamar a funcao:

        1) Armazenar o grafo em forma de lista de adjacencias
           no vector graph[]

        2) Chamar a funcao scc_decomposition(n), onde n eh o
           numero de vertices do grafo

        Observacao: Para o problema 2-SAT, criar um vertice
        para cada variavel e sua respectiva negacao. Para cada
        afirmacao da forma (a OU b), criar uma aresta (~b -> a)
        e outra (~a -> b). Todos os vertices de uma mesma
        componente fortemente conexa sao verdadeiros ou falsos.
        Portanto, se uma variavel e sua respectiva negacao
        pertencerem a uma mesma componente o problema nao possui
        solucao. Resultado da decomposicao em componentes
        fortemente conexas: um DAG (digrafo aciclico)

    Resultado da funcao:

        A funcao armazena em component[] : component[i] = o indice
        da componente ao qual o vertice i pertence
        A funcao tambem armazena em scc o numero de componentes
        fortemente conexas do grafo.

    Complexidade do algoritmo:

        O (n+m)

    Problemas resolvidos:

        DESVRUA (SPOJ BR)
        CARDAPIO (SPOJ BR)

    Adicionado por:

        Jorge Gabriel Siqueira

*/

vector <int> g[MAXN];
int component[MAXN];
int scc;

vector <int> S;
bool in_stack[MAXN];
int indices[MAXN], lowlinks[MAXN], indice;

void tarjan (int v)
{
    indices[v] = indice;
    lowlinks[v] = indice;
    ++indice;
    S.push_back(v);
    in_stack[v] = true;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int w = g[v][i];
        if (indices[w] == -1)
        {
            tarjan(w);
            lowlinks[v] = min (lowlinks[v], lowlinks[w]);
        }
        else if (in_stack[w])
            lowlinks[v]=min(lowlinks[v], indices[w]);
    }
    if (lowlinks[v] == indices[v])
    {
        int w = S[S.size() - 1];
        S.pop_back();
        while (w != v)
        {
            in_stack[w] = false;
            component[w] = scc;
            w = S[S.size() - 1];
            S.pop_back();
        }
        component[v] = scc++;
        in_stack[v] = false;
    }
}

void scc_decomposition (int n)
{
    for (int i = 0; i < n; ++i)
    {
        indices[i] = lowlinks[i] = component[i] = -1;
        in_stack[i] = 0;
    }
    S.clear();
    indice = scc = 0;
    for (int i = 0; i < n; ++i)
        if (component[i] == -1)
            tarjan(i);
}

int main()
{
    return 0;
}
