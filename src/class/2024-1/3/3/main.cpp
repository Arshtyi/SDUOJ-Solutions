#include <stdio.h>
#include <limits.h>
int MAX = INT_MIN;
int main (){
    int n;scanf("%d",&n);
    while (n--)
    {
        int s;scanf("%d",&s);
        MAX = MAX < s ? s : MAX;
    }
    printf("%d",MAX);
    return 0;
}