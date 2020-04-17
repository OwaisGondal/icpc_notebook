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
#include <numeric>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    float r=7.125;
    printf(" %9.3f\n",-r);//  -> "    -7.125"
    printf(" %9.3f\n",r);//   -> "     7.125"
    printf(" %-9.3f\n",r);//  -> " 7.125    "
    printf(" %09.3f\n",-r);// -> " -0007.125"
    printf(" %09.3f\n",r);//  -> " 00007.125"
    printf(" %-09.3f\n",r);// -> " 7.125    "
    return 0;
}
