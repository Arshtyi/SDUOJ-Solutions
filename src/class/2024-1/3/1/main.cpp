#include <stdio.h>
#include <string.h>
void multiplyMatrix(long long A[2][2], long long B[2][2]);
void powerMatrix(long long M[2][2], int n);
long long fibonacci(int n);
int main() {
    int n;scanf("%d", &n);
    printf("%lld\n",fibonacci(n));return 0;
}
void multiplyMatrix(long long A[2][2], long long B[2][2]) {
    long long result[2][2] = {0};
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k)  result[i][j] += A[i][k] * B[k][j];
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) A[i][j] = result[i][j];
}
void powerMatrix(long long M[2][2], int n) {
    long long result[2][2] = { {1, 0}, {0, 1} }; 
    do {if (n &1) multiplyMatrix(result, M); multiplyMatrix(M, M);}while(n >>= 1);
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) M[i][j] = result[i][j];
}
long long fibonacci(int n) {
    if (n == 1) return 0;if(n == 2) return 1; 
    long long M[2][2] = {{1, 1},{1, 0}};
    powerMatrix(M, n - 2);return M[0][0] * 1 + M[0][1] * 0;
}

