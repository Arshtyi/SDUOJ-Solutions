#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long N;int seed;scanf("%d %lld",&seed,&N);
    float x,y,s;long long m=0,n=0;srand(seed);
    for (long long i=0;i<N;i++)
    {
         n++;x=1+(float)rand()/RAND_MAX;  
         y=(float)rand()/RAND_MAX;if(y<=(1/x))m++;
    }
    s=(float)m/n;printf("%f\n",s);return 0;
}