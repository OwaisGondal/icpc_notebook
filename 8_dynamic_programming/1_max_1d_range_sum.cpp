#include <stdio.h>
#include <vector>

using namespace std;

/*
    Aplicacoes:

        Determinar a subarray de maior soma de um
        conjunto de numeros

    Complexidade:

        O(n)

*/

int max_so_far; //Max 1D range Sum
int begin; //Inicio da subsequencia
int end; //Fim da subsequencia

//Max 1D range Sum
void kadane(std::vector<int>& numbers)
{
    // Initialize variables here
    int max_ending_here = numbers[0];
    int begin_temp = 0;

    max_so_far  = numbers[0];
    begin = 0;
    end = 0;

    for(int i = 1; i < numbers.size(); i++)
    {
        // calculate max_ending_here
        if(max_ending_here < 0)
        {
            max_ending_here = numbers[i];
            begin_temp = i;
        }
        else
        {
            max_ending_here += numbers[i];
        }

        // calculate max_so_far
        if(max_ending_here > max_so_far )
        {
            max_so_far  = max_ending_here;
            begin = begin_temp;
            end = i;
        }
    }
}

int main()
{
    return 0;
}
