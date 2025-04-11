#include <stdio.h>
int main(){
    int T;scanf("%d",&T);int s[T];
    for(int i = 0;i < T;i ++)scanf("%d",&s[i]);
    for(int i = 0;i < T - 1;i ++)for(int j = 0 ;j < T - i - 1;j ++)if(s[j] > s[j + 1]){int t = s[j];s[j] = s[j + 1];s[j + 1] = t;}
    for(int i = 0;i < T;i ++)printf("%d ",s[i]);return 0;
}