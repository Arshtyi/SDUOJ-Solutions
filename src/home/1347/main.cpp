#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000005
const ll N = 3;
const ll MOD = 998244353;
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
                c.x[i][j] = 0;
                for (ll k = 0; k < N; k++)
                {
                    c.x[i][j] += x[i][k] * b.x[k][j] % MOD;
                    c.x[i][j] %= MOD;
                }
            }
        return c;
    }
};

Matrix fastpow(Matrix a, ll n)
{
    Matrix res;
    for (ll i = 0; i < N; i++)
        res.x[i][i] = 1;
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
    ll t, n;
    cin >> t;
    Matrix a, b;
    a.x[0][0] = 1;
    a.x[0][2] = 1;
    a.x[1][1] = 1;
    a.x[1][2] = 1;
    a.x[2][0] = 2;
    a.x[2][1] = 2;
    a.x[2][2] = 1;
    for (ll i = 1; i <= t; ++i)
    {
        cin >> n;
        b = fastpow(a, n - 1);
        cout << (b.x[0][0] % MOD + ((b.x[0][2] % MOD) * 2) % MOD) % MOD << "\n";
    }

    return 0;
}