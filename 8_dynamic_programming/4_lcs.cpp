#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

/*
    LCS -> Maior Subsequencia Comum
    Tempo: m*n

    Parametros:
        x = string 1 a ser comparada
        y = string 2 a ser comparada

    Retorno:
        pair<int,string>:
            first -> tamanho da maior subsequencia
            second -> maior subsequencia comum;
*/

pair<int, string> LCS(string x, string y)
{
    int m,n,i,j;

    m = x.length();
    n = y.length();

    pair<int, string> PD[m+1][n+1];

    for(i=0; i<=m; i++) //Zera a coluna 0
    {
        PD[i][0].first = 0;
        PD[i][0].second = "";
    }

    for(i=0; i<=n; i++) //Zera a linha 0
    {
        PD[0][i].first = 0;
        PD[0][i].second = "";
    }


    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i-1] == y[j-1]) //Elemento igual, logo PD[i][j] = PD[i-1][j-1]+1
            {
                PD[i][j].first = PD[i-1][j-1].first + 1;
                PD[i][j].second = PD[i-1][j-1].second + x[i-1];
            }
            else //Elementos diferentes, PD[i][j] = MAX(PD[i-1][j], PD[i][j-1])
            {
                PD[i][j] = PD[i-1][j].first > PD[i][j-1].first ? PD[i-1][j] : PD[i][j-1];
            }
        }
    }

    return PD[m][n];
}

int main()
{
    string x, y;

    cin >> x >> y;

    pair<int,string> msc = LCS(x,y);

    cout << msc.first << " - " << msc.second << endl;

    return 0;
}
