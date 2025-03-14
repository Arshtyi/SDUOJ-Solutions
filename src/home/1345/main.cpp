#define LOCAL
#include <bits/stdc++.h>
using namespace std;
long long MOD, n;
int fib()
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    vector<vector<long long>> F = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    n -= 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = {{(result[0][0] * F[0][0] + result[0][1] * F[1][0]) % MOD, (result[0][0] * F[0][1] + result[0][1] * F[1][1]) % MOD},
                      {(result[1][0] * F[0][0] + result[1][1] * F[1][0]) % MOD, (result[1][0] * F[0][1] + result[1][1] * F[1][1]) % MOD}};
        }
        F = {{(F[0][0] * F[0][0] + F[0][1] * F[1][0]) % MOD, (F[0][0] * F[0][1] + F[0][1] * F[1][1]) % MOD},
             {(F[1][0] * F[0][0] + F[1][1] * F[1][0]) % MOD, (F[1][0] * F[0][1] + F[1][1] * F[1][1]) % MOD}};
        n /= 2;
    }
    return result[0][0];
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
        cin >> n >> MOD;
        cout << fib() << endl;
    }

    return 0;
}