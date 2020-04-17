#include <stdio.h>
#include <iostream>
#define MAX 100

using namespace std;

/*
    Aplicações:

        Dados números naturais  (p1, p2, … , pn), (v1, v2, … , vn)
        e  c,  encontrar um subconjunto X de {1,2,…,n} que
        maximize v(X)   sob a restrição  p(X) ≤ c. Em outras palavras
        Determinar o subconjunto de elementos que maximize a soma
        dos valores e que possua a soma dos pesos menores ou iguais a c

*/

int p[MAX]; //Peso dos elementos
int v[MAX]; //Valor dos elementos
int n; //Numero de elementos do conjunto
int c; //Peso maximo suportado

int knapsack_0_1()
{
	register int mat[n+1][c+1], i, j;

	for(i=0; i<n; i++) mat[i][0] = 0;

	mat[i][0] = 0;

	for(i=0; i<=c; i++) mat[0][i] = 0;

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=c; j++)
		{
			if(p[i-1] > j) mat[i][j] = mat[i-1][j];
			else mat[i][j] = max(mat[i-1][j], mat[i-1][j-p[i-1]]+v[i-1]);
		}
	}

	/*for(i=0; i<=n; i++)
	{
		for(j=0; j<=c; j++) printf("%d ",mat[i][j]);
		printf("\n");
	}*/

	return mat[n][c];
}

int main()
{
    return 0;
}
