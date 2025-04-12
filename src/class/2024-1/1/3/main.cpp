#include <stdio.h>
#include <math.h>
const double PI=3.1415926;
int main(){
    double m,n;
    m = sqrt((1.0 - cos(PI / 3.0)) / 2);
    n = sin(PI / 4) * sin(PI / 4) + sin(PI / 4) * cos(PI / 4) - cos(PI / 4) * cos(PI / 4);
    printf("%f\n%f\n",m,n);
    return 0;
}