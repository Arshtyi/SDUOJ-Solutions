#include <stdio.h>
#include <string.h>
#include <math.h>
const double EPS = 1e-8;
double toDecimal(const char* num, int base);
void fromDecimal(double decimal, int base, char* result);
int main() {
    char num[256]={0},result[256] = {0};
    int sourceBase,targetBase;
    scanf("%d %d %s",&sourceBase,&targetBase,num);
    double decimalValue = toDecimal(num, sourceBase);
    fromDecimal(decimalValue, targetBase, result);
    printf("%s\n", result);
    return 0;
}
double toDecimal(const char* num, int base) {
    double decimalValue = 0,basePower = 1;int len = strlen(num),isFraction = 0;
    for (int i = 0; i < len; ++i) {
        char c = num[i];
        if (c == '.') {isFraction = 1;continue;}
        int digit;
        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'a' && c <= 'z') digit = c - 'a' + 10;
        if (isFraction) {basePower /= base;decimalValue += digit * basePower;} 
        else decimalValue = decimalValue * base + digit;
    }
    return decimalValue;
}
void fromDecimal(double decimal, int base, char* result) {
    long long integerPart = (long long)decimal;double fractionalPart = decimal - integerPart;
    char temp[256];int index = 0;
    do {
        int remainder = integerPart % base;
        temp[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
        integerPart /= base;
    } while (integerPart > 0);
    int resultIndex = 0;
    for (int i = index - 1; i >= 0; --i) result[resultIndex++] = temp[i];
    if (fractionalPart > 0) {
        result[resultIndex++] = '.'; // 添加小数点
        for (int i = 0; i < 8; ++i) { // 最多保留 8 位小数
            fractionalPart *= base;
            int digit = (int)fractionalPart;
            result[resultIndex++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
            fractionalPart -= digit;
            if (fractionalPart < EPS) break; // 如果小数部分几乎为 0，停止计算
        }
    }
    result[resultIndex] = '\0'; // 添加字符串结束符
}


