#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/*

    UNION FIND

    Aplicacoes:

        Estrutura de dados que trata da manipulacao
        de conjuntos, abrangindo basicamente 2 operacoes:

            Union -> Juntar dois subconjuntos em um so

            Find -> Determinar o subconjunto de um determinado
                    elemento

    Como chamar a funcao:

        1) Criar a estrutura:

            UnionFind unionFind = UnionFind(n); onde:

                n -> numero de elementos do conjunto

        2) Para unir o conjunto x com o conjunto y chamar:

            unionFind.unionSet(x,y);

        3) Para saber o conjunto do elemento x chamar:

            unionFind.root(x);

    Resultado da funcao:

        A funcao unionFind.root(x) retorna o indice do
        conjunto onde x esta contido.

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

struct UnionFind
{
    vector<int> data;

    /*

    Construtor

    Parametros:
        int size -> tamanho do conjunto

    */

    UnionFind(int size) : data(size, -1) { }

    /*

    unionSet - Une o conjunto do elemento x ao conjunto do elemento y

    Parametros:
        int x -> elemento de um conjunto A
        int y -> elemento de um conjunto B a ser unido em A

    Retorna:
        true se conseguiu unir, ou seja, x != y
        false se x pertence ao mesmo conjunto de y

    */

    bool unionSet(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x != y)
        {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    /*

    findSet - Verifica se x e y pertencem ao mesmo conjunto

    Parametros:
        int x -> elemento de um conjunto
        int y -> elemento de um conjunto

    Retorna:
        true se x pertence ao mesmo conjunto de y
        false se x nao pertence ao mesmo conjunto de y

    */

    bool findSet(int x, int y)
    {
        return root(x) == root(y);
    }

    /*

    root - retorna o conjunto de um elemento x
    Parametros:
        int x -> elemento a ser verificado

    Retorna:
        indice do conjunto que contem x

    */

    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    /*

    size - retorna o tamanho do conjunto onde x esta contido
    Parametros:
        int x -> elemento a ser verificado

    Retorna:
        retorna o tamanho do conjunto onde x esta contido

    */

    int size(int x)
    {
        return -data[root(x)];
    }
};

int main()
{
    UnionFind unionFind = UnionFind(10);

    unionFind.unionSet(1,2);
    unionFind.unionSet(3,4);
    unionFind.unionSet(2,3);

    cout << unionFind.root(4);
}
