#include <stdio.h>
#include <math.h>
const double PI = 3.1415926;
int main(){
    double x,y,z;
    x = 2 * sqrt(5) * (sqrt(6) + sqrt(3)) / 9.0;
    y = (log(5 * log(3)) - log(2)) / (sin(PI / 3));
    z = exp(3) + log10(105);
    printf("%f\n%f\n%f\n",x,y,z);
    return 0;
}