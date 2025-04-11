#include <stdio.h>
#include <math.h>
int x;
int check(int start,int end,int *s);
int main(){
    int T;scanf("%d",&T);int s[T];
    for(int i = 0;i < T;i ++)scanf("%d",&s[i]);scanf("%d",&x);
    printf("%d\n",check(0,T - 1,s));return 0;
}
int check(int start,int end,int *s){
    int mid ;
    while(start <= end){
        mid  = (start + end ) / 2;
        if(x == *(s + mid))return mid;
        else if(x > *(s + mid))return check(mid + 1,end,s);    
        else return check(start,mid - 1,s);
    }
    return -1;
}