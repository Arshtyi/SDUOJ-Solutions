#include <stdio.h>
int main ()
{
    double x = 5;
    for(int i=1;i<4;i++)x=1.0+1.0/x;
    printf("%f",x);
    return 0;
}