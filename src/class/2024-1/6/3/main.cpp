#include <stdio.h>

#define N 1000
int matrix[N][N];

void rotate(int matrixSize, int matrixColSize);

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    rotate(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void rotate(int matrixSize, int matrixColSize)
{
    // TODO：在该函数内部完成对矩阵matrix的翻转
    int n = matrixSize;
    if(n > 1){
        for(int i = 0;i < n / 2;i ++){
            for(int j = i;j < n - 1 - i;j ++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
    }
}