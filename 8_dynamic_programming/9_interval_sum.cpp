#include <stdio.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
    Aplicacoes:

        Dado um conjunto de elementos, determinar
        todas as subsequencias deste conjunto que possuam
        soma v

    Parametros:

        int vet[] -> conjunto de elementos
        int n -> numero de elementos do conjunto
        int t -> valor de soma a ser buscado

    Retorna:

        intervals -> intervalos (inicio, fim) de vet que possuem soma v
*/

vector< pair<int,int> > interval_sum(int vet[], int n, int v)
{
    vector< pair<int,int> > intervals;
    int sum=vet[0];
    int ini=0;
    int fim=0;

    while(ini < n)
    {
        if(sum == v)
        {
            intervals.push_back(pair<int,int>(ini,fim));
            sum -= vet[ini];
            ini++;
        }
        else if(sum < v)
        {
            if(fim+1 < n)
            {
                fim++;
                sum += vet[fim];
            }
            else break;
        }
        else
        {
            sum -= vet[ini];
            ini++;
        }
    }

    return intervals;
}

int main()
{
    for(int i=0; i<5000; i++)
    for(int j=0; j<5000; j++);
}
