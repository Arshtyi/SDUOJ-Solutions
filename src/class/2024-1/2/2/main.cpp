#include <stdio.h>
#include <string.h>
int main (){
    char s[256] = {0};scanf("%s",s);int t = strlen(s);
    if(s[t - 1] == 'y'){s[t - 1] = 'i';s[t] = 'e';s[t + 1] = 's';}
    else if (s[t - 1] == 's' || s[t - 1] == 'x' || (s[t - 2] == 'c' && s[t - 1] == 'h') || (s[t - 2] == 's' && s[t - 1] == 'h') || s[t - 1] == 'o'){s[t] = 'e';s[t + 1] = 's';}else s[t] = 's';
    printf("%s",s);return 0;
}