#include <iostream>

using namespace std;

int sumDigits(int n)
{
    return n>=10 ? (n%10+n/10) : n;
}

bool creditCard(string number)
{
    int i, sum1=0, sum2=0;

    for(i=0; i<number.size(); i+=2)
    {
        sum1 += sumDigits((number[i]-'0')*2);
    }

    for(i=1; i<number.size(); i+=2)
    {
        sum2 += (number[i]-'0');
    }

    return ((sum1+sum2)%10 == 0) ? true : false;
}

int main()
{

}
