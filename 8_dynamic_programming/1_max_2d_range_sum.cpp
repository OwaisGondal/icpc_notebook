#include <stdio.h>
#include <vector>
#include <string.h>
#include <limits.h>

using namespace std;

/*
    Aplicacoes:

        Determina a sub-matriz de soma maxima em uma matriz

    Retorna:

        int finalTop ->
        int finalLeft ->
        int finalBottom ->
        int finalRight ->
        int maxSum ->
*/

#define ROW 100
#define COL 100

int M[ROW][COL];
int finalTop;
int finalLeft;
int finalBottom;
int finalRight;
int maxSum;

int kadane(int* arr, int* start, int* finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;

    // needed if sum NEVER becomes less than 0
    *start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            *start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *finish = i;
        }
    }
    return maxSum;
}

void findMaxSum()
{
    // Variables to store the final output
    maxSum = 0;

    int left, right, i;
    int temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < COL; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < COL; ++right)
        {
            // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            // Find the maximum sum subarray in temp[]. The kadane() function
            // also sets values of start and finish.  So 'sum' is sum of
            // rectangle between (start, left) and (finish, right) which is the
            //  maximum sum with boundary columns strictly as left and right.
            sum = kadane(temp, &start, &finish, ROW);

            // Compare sum with maximum sum so far. If sum is more, then update
            // maxSum and other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
}

int main()
{

}
