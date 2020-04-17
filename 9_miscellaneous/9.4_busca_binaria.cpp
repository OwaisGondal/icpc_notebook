#include <stdio.h>
#include <iostream>

using namespace std;

int buscabinaria( pair<int,int> array[], int chave , int N)
{
     int inf = 0;
     int sup = N-1;
     int meio;
     while (inf <= sup)
     {
          meio = inf + (sup-inf)/2;
          if (chave == array[meio].first)
               return array[meio].second;
          else if (chave < array[meio].first)
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;
}

int main()
{

}
