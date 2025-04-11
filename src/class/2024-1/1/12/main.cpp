#include <stdio.h>
#include <math.h>
int main(){
    double s = 1,pi = 0,i = 1,n = 1;int N;
    scanf("%d",&N);double y = pow(0.1,N);
    while(fabs(i) - y > 1e-12 ){pi+=4.0*i;n=n+2;s=-s;i=s/n;}
    printf("%f\n",pi);return 0;
}