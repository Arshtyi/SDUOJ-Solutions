#include <stdio.h>
int n,s,a,b,m;
int X(int i);
int main (){
    scanf("%d %d %d %d %d",&n,&s,&a,&b,&m);
    for(int i = 1;i <= n;i++)printf("%d ",X(i));return 0;
}
int X(int i){
    return i == 0 ? s : (a * X(i-1) + b) % m;
}