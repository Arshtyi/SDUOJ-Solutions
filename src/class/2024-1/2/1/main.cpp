#include <stdio.h>
#include <string.h>
int main(){
    char s[256] = {0};int n;scanf("%d", &n);getchar();
    while (n--){memset(s, 0, sizeof(s));scanf("%[^\n]", s);getchar();printf("%s\n", s);}
    return 0;
}