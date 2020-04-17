#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <math.h>
#include <sstream>
#include <assert.h>
#define INF 0x3f3f3f3f

using namespace std;

/*

    ABB - Arvore Binaria de Busca

    Aplicacoes:

        Busca em O(log(n)) em um conjunto de numeros
        Percurso In,Pre e Pos ordem
        Contar os nos de uma arvore
        Contar as folhas de uma arvore
        Calcular a altura de uma arvore

    Como chamar a funcao:

        1) Criar a arvore:

            No *arvore;
            criarArvore(&arvore);

        2) Inserir um elemento:

            int numero;
            scanf("%d",&numero);
            inserir(&arvore,numero);

        3) Remover um elemento:

            int numero;
            scanf("%d",&numero);
            remover(&arvore,numero);

        4) Exibir os percursos:

            exibirPreOrdem(arvore);
            exibirEmOrdem(arvore);
            exibirPosOrdem(arvore);

        5) Contar nos, folhas, verificar a altura:

            contarNos(arvore);
            contarFolhas(arvore);
            altura(arvore);

    Resultado da funcao:

        1,2) void

        3) void, caso nao exista o elemento a ser removido eh
           possivel tratar esta situacao (primeira linha da funcao)

        4) Imprime o percurso escolhido

        5) Retorna um inteiro representando o valor da
           funcao selecionada

    Complexidade do algoritmo:

        1) O(1)

        2,3) O(log(n))

        4,5) O(n)

    Problemas resolvidos:

        URI 1200
        URI 1201

    Adicionado por:

        Jorge Gabriel Siqueira

*/

typedef struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
} No;

void criarArvore(No **pRaiz)
{
    *pRaiz = NULL;
}

void inserir(No **pRaiz, int numero)
{
    if(*pRaiz == NULL)
    {
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }
    else
    {
        if(numero < (*pRaiz)->numero)
            inserir(&(*pRaiz)->esquerda, numero);
        if(numero > (*pRaiz)->numero)
            inserir(&(*pRaiz)->direita, numero);
    }
}

No *MaiorDireita(No **no)
{
    if((*no)->direita != NULL)
        return MaiorDireita(&(*no)->direita);
    else
    {
        No *aux = *no;
        if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse no vai perder todos os seus filhos da esquerda!
            *no = (*no)->esquerda;
        else
            *no = NULL;
        return aux;
    }
}

No *MenorEsquerda(No **no)
{
    if((*no)->esquerda != NULL)
        return MenorEsquerda(&(*no)->esquerda);
    else
    {
        No *aux = *no;
        if((*no)->direita != NULL) // se nao houver essa verificacao, esse no vai perder todos os seus filhos da direita!
            *no = (*no)->direita;
        else
            *no = NULL;
        return aux;
    }
}

void remover(No **pRaiz, int numero)
{
    if(*pRaiz == NULL)    // esta verificacao serve para caso o numero nao exista na arvore.
    {
        printf("Numero nao existe na arvore!\n");
        return;
    }
    if(numero < (*pRaiz)->numero)
        remover(&(*pRaiz)->esquerda, numero);
    else if(numero > (*pRaiz)->numero)
        remover(&(*pRaiz)->direita, numero);
    else     // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
    {
        No *pAux = *pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
        if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL))          // se nao houver filhos...
        {
            free(pAux);
            (*pRaiz) = NULL;
        }
        else      // so tem o filho da direita
        {
            if ((*pRaiz)->esquerda == NULL)
            {
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux);
                pAux = NULL;
            }
            else             //so tem filho da esquerda
            {
                if ((*pRaiz)->direita == NULL)
                {
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else        //Escolhi fazer o maior filho direito da subarvore esquerda.
                {
                    pAux = MaiorDireita(&(*pRaiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                    pAux->esquerda = (*pRaiz)->esquerda;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                    pAux->direita = (*pRaiz)->direita;
                    (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                    free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}

void exibirEmOrdem(No *pRaiz)
{
    if(pRaiz != NULL)
    {
        exibirEmOrdem(pRaiz->esquerda);
        printf("\n%i", pRaiz->numero);
        exibirEmOrdem(pRaiz->direita);
    }
}

void exibirPreOrdem(No *pRaiz)
{
    if(pRaiz != NULL)
    {
        printf("\n%i", pRaiz->numero);
        exibirPreOrdem(pRaiz->esquerda);
        exibirPreOrdem(pRaiz->direita);
    }
}

void exibirPosOrdem(No *pRaiz)
{
    if(pRaiz != NULL)
    {
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("\n%i", pRaiz->numero);
    }
}

int contarNos(No *pRaiz)
{
    if(pRaiz == NULL)
        return 0;
    else
        return 1 + contarNos(pRaiz->esquerda) + contarNos(pRaiz->direita);
}

int contarFolhas(No *pRaiz)
{
    if(pRaiz == NULL)
        return 0;
    if(pRaiz->esquerda == NULL && pRaiz->direita == NULL)
        return 1;
    return contarFolhas(pRaiz->esquerda) + contarFolhas(pRaiz->direita);
}

int maior(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int altura(No *pRaiz)
{
    if((pRaiz == NULL) || (pRaiz->esquerda == NULL && pRaiz->direita == NULL))
        return 0;
    else
        return 1 + maior(altura(pRaiz->esquerda), altura(pRaiz->direita));
}

int busca (No *inicio, int valor)
{
    while (inicio != NULL)
    {
        if (valor == inicio->numero)
            return inicio->numero;
        else if (valor < inicio->numero)
            inicio = inicio->esquerda;
        else
            inicio = inicio->direita;
    }
    return 0;
}

int main()
{

    return 0;
}

