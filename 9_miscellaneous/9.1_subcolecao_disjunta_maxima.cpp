#include <stdio.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*

    Aplicacoes:

        Dados um conjunto de tarefas determinandas
        por seus momentos de inicio e fim, determinar a
        subcolecao maxima destas tarefas de modo a
        maximizar o numero de tarefas realizadas

        Obs. Armazenar o conjunto de tarefas na variavel
        tarefas de forma inversa, ou seja, o momento de
        fim da i-esima tarefa deve ser armazendo em
        tarefas[i].first e o momento de inicio da i-esima
        tarefa deve ser armazenado em tarefas[i].second

*/
vector< pair<int,int> > tarefas; //Armazenar em first o termino e em second o inicio

int sdm()
{
    if(tarefas.empty()) return 0;

    sort(tarefas.begin(), tarefas.end());

    int cont=1;
    int i = 0;

    for(int k=1; k<tarefas.size(); k++)
    {
        if(tarefas[k].second > tarefas[i].first)
        {
            cont++;
            i = k;
        }
    }

    return cont;
}

int main()
{

}

