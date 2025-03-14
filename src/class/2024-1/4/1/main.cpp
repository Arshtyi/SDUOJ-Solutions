#include <stdio.h>
int main(){
    int N;scanf("%d",&N);
    int M = N / 2;int Z = N % 2;int X = M ,Y = M;
    do{while (X >= 2){X -= 1;M ++;Y ++;}while (Y >= 4){Y -= 3;M ++;X ++;}}while(X >= 2 || Y >= 4);
    printf("%d %d %d %d",M,X,Y,Z);return 0;
}