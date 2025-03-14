#include <stdio.h>
#include <string.h>
const long long MOD = 1e11 + 7;
long long solveFrogJump(int n);
void multiplyMatrix(long long A[3][3], long long B[3][3]);
void powerMatrix(long long M[3][3], int n);
int main() {
    int n;scanf("%d", &n);printf("%lld\n",solveFrogJump(n));
    return 0;
}
void multiplyMatrix(long long A[3][3], long long B[3][3]) {
    long long result[3][3] = {0};
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++)result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
    for (int i = 0; i < 3; ++i)for (int j = 0; j < 3; ++j)A[i][j] = result[i][j];
}
void powerMatrix(long long M[3][3], int n) {
    long long result[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    do{if (n & 1)multiplyMatrix(result, M);multiplyMatrix(M, M);}while (n >>= 1);
    for (int i = 0; i < 3; ++i)for (int j = 0; j < 3; ++j)M[i][j] = result[i][j];
}
long long solveFrogJump(int n) {
    if (n == 1) return 1;if (n == 2) return 2;if (n == 3) return 4;
    long long M[3][3] = {{1, 1, 1},{1, 0, 0},{0, 1, 0}};
    powerMatrix(M, n - 3);
    long long F[3] = {4, 2, 1},result = 0;
    for (int i = 0; i < 3; ++i) result = (result + M[0][i] * F[i]) % MOD;
    return result;
}