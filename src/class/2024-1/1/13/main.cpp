#include <stdio.h>
int main(){
    int a[3][3],b[3][3];
    for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)scanf("%d",&a[i][j]);
    for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)scanf("%d",&b[i][j]);      
    for(int i = 0;i < 3;i++ ){for(int j = 0;j < 3;j++)printf("%d\t",a[i][j] + b[i][j]);printf("\n");}
    printf("\n");
    for(int i = 0;i < 3;i++ ){for(int j = 0;j < 3;j++)printf("%d\t",a[i][j] - b[i][j]);printf("\n");}
    printf("\n");
    for(int i = 0;i < 3;i++){for(int j = 0;j < 3;j++){int sum = 0;for(int k = 0;k < 3;k++)sum += a[i][k] * b[k][j];printf("%d\t",sum);}printf("\n");}
    printf("\n");
    for(int i = 0;i < 3;i++ ){for(int j = 0;j < 3;j++)printf("%d\t",a[j][i]);printf("\n");}
    return 0;
}