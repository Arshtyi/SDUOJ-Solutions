#include <stdio.h>
int main(){
    int x,y,z;scanf("%d %d %d",&x,&y,&z);printf("%d\n",(x * 70 + y * 21 + z * 15) % 105);
    return 0;
}