#include <stdio.h>
int main(){
    int in = 0;scanf("%X",&in);
    for(int i = 2;i < 16;i ++){
        char result[256]={0};
        int j,t = in;
        for(j = 255;t && j > -1;j --){
            if(t % i < 10)result[j] = t % i + '0';
            else if (t % i > 9)result[j] = t % i  - 10 + 'A'; 
            t /= i;
        }
        for(int k = j + 1;result[k] && k < 256;k ++)printf("%c",result[k]);
        printf("\n");
    }
    return 0;
}