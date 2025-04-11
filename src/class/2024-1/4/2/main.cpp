#include <math.h>
#include <stdio.h>
int main(){
    int n;scanf("%d",&n);
    while (n--){int x;scanf("%d",&x);printf("%.5f ",(3 * x * x + 4 * sqrt(x) + 5) /(7 * x + 13));}
    return 0;
}