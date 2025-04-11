#define LOCAL
// n较小考虑快速幂，较大考虑拉格朗日插值
// https://www.cnblogs.com/luckyblock/p/13429496.html
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 10;
int pl[N], pr[N], fac[N]; // 前缀积，后缀积，阶乘
int qpow(int a, int b)
{
    int res = 1;
    do
    {
        if (b & 1)
            res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
    } while (b >>= 1);
    return res;
}
void solve()
{
    int n, k;
    int s = 0, ans = 0;
    cin >> n >> k;
    pl[0] = pr[k + 3] = fac[0] = 1;
    for (int i = 1; i <= k + 2; ++i)
        pl[i] = 1ll * pl[i - 1] * (n - i) % MOD;
    for (int i = k + 2; i >= 1; --i)
        pr[i] = 1ll * pr[i + 1] * (n - i) % MOD;
    for (int i = 1; i <= k + 2; ++i)
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    for (int i = 1; i <= k + 2; ++i)
    {
        s = (s + qpow(i, k)) % MOD;
        int x = 1ll * pl[i - 1] * pr[i + 1] % MOD;
        int y = ((k - i) & 1 ? -1ll : 1ll) * fac[i - 1] * fac[k + 2 - i] % MOD;
        ans = (ans + 1ll * s * x % MOD * qpow(y, MOD - 2) % MOD) % MOD;
    }
    cout << (ans + MOD) % MOD << endl;
}
signed main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}