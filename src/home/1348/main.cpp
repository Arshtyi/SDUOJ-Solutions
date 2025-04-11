/**
 * https://xieincz.github.io/post/yi-ju/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 矩阵快速幂
const ll N = 101; // 方阵的大小
struct Matrix
{
    ll x[N][N];
    Matrix()
    {
        memset(x, 0, sizeof(x));
    }
    Matrix(const Matrix &b)
    {
        memcpy(x, b.x, sizeof(x));
    }
    Matrix operator*(const Matrix &b) const
    {
        Matrix c;
        for (ll i = 0; i < N; i++)
            for (ll j = 0; j < N; j++)
            {
                for (ll k = 0; k < N; k++)
                {
                    // 注意这里修改了矩阵乘法的定义，仅适用于衬衫题
                    c.x[i][j] = max(c.x[i][j], x[i][k] + b.x[k][j]);
                }
            }
        return c;
    }
};

Matrix fastpow(Matrix a, ll n)
{
    // 注意这里修改了矩阵快速幂的定义，仅适用于衬衫题
    Matrix res(a);
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    Matrix a;
    for (ll i = 0; i < m; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> a.x[i][j];
    a = fastpow(a, n - 2);
    for (ll i = 0; i < m; ++i)
        for (ll j = 0; j < m; ++j)
            ans = max(ans, a.x[i][j]);
    cout << ans;
    return 0;
}
