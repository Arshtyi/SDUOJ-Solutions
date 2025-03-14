#include <math.h>
#include <stdio.h>
const double eps = 1e-8;
int main(){
    int n;scanf("%d",&n);
    while (n--)
    {
        int x;scanf("%d",&x);
        if(x < -2000)printf("%d ",2 * x - 1);
        else if(x < 2000)printf("%d ",x * x);
        else if (sqrt(x) - (int)sqrt(x) < eps)printf("%d ",(int)sqrt(x));
            else printf("%.5f ",sqrt(x));
    }
    return 0;
}