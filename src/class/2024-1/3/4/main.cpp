#include <stdio.h>
#include <math.h>
#include <limits.h>
int min = INT_MAX;
int check(int start,int end,int *s);
int sum(int *s1,int *s2);
int main(){
    int m;scanf("%d",&m);int T = pow(2,m);int s[T];int *si = s + T; 
    for(int i = 0;i < T;i ++)scanf("%d",&s[i]);
    int a = s[0],b;
    for(int i = 0;i < T;i ++)if(a != s[i]){b = s[i];break;}
    min = (a < b) ? a : b;    
    printf("%d",check(0,T - 1,s));
    return 0;
}
int check(int start,int end,int *s){
    int mid;
    while(start <= end){
        mid  = (start + end ) / 2;
        if(sum(s + start,s + mid) == sum(s + mid,s + end))return mid;
        else if (sum(s + start,s + mid ) < sum(s + mid ,s + end))return check(mid + 1,end,s);
        else return check(start,mid  - 1,s);
    }
    return -1;
}

int sum(int *s1,int *s2){
    int re = 0;
    for(int i = 0;s1 + i <= s2; i ++)if(*(s1 + i) == min)re ++;
    return re;
}