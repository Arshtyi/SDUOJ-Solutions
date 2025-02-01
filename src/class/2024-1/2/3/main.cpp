#include <stdio.h>
#include <string.h>
#include <math.h>

char* convertToDecimal(const char* num, int base, char* result);
char* convertFromDecimal(const char* num, int base, char* result);

int main (){
    int src,dst;char *num,*result,*out;
    num = (char*)malloc(256 * sizeof(char));
    result = (char*)malloc(256 * sizeof(char));
    out = (char*)malloc(256 * sizeof(char));
    scanf("%d %d %s",&src,&dst,num);
    result = convertToDecimal(num,src,result);
    out = convertFromDecimal(result,dst,out);
    printf("%s",out);
    free(num);free(result);free(out);
    return 0;
}

char* convertToDecimal(const char* num, int base, char* result) {
    if (base == 10) {strcpy(result, num);return result;}
    long long decimalValue = 0;int power = 0,len = strlen(num);
    for (int i = len - 1; i >= 0; --i) {
        char c = num[i];int digit;
        if (c >= '0' && c <= '9')digit = c - '0';
        else digit = c - 'a' + 10;
        decimalValue += digit * pow(base, power);
        power++;
    }
    sprintf(result, "%lld", decimalValue);return result;
}
char* convertFromDecimal(const char* num, int base, char* result) {
    long long decimalValue = 0;int index = 0,isNegative = 0;
    if (num[0] == '-') {isNegative = 1;num++;}
    for (int i = 0; num[i] != '\0'; ++i)decimalValue = decimalValue * 10 + (num[i] - '0');
    if (isNegative) decimalValue = -decimalValue;
    do {int remainder = decimalValue % base;
        if (remainder < 0) {remainder += base;decimalValue = (decimalValue - remainder) / base;} 
        else decimalValue /= base;
        result[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
    } while (decimalValue != 0);
    if (isNegative)result[index++] = '-';
    result[index] = '\0';
    for (int i = 0, j = index - 1; i < j; ++i, --j) {char temp = result[i];result[i] = result[j];result[j] = temp;}
    return result;
}