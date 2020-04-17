#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int convertTime(char time[])
{
    int h,m,s,ms;

    char *t = strtok(time, ":");
    h = atoi(t);
    t = strtok(NULL, ":");
    m = atoi(t);
    t = strtok(NULL, ":");
    s = atoi(t);
    t = strtok(NULL, ":");
    ms = atoi(t);

    return ms + s*1000 + m*60000 + h*3600000;
}

int main()
{

}
