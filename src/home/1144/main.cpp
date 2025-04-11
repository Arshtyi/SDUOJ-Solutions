#define LOCAL
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    // 计算3^k形式的极限
    int max_balanced = (pow(3, ceil(log(2 * n + 1) / log(3))) - 1) / 2;

    // 如果n恰好等于max_balanced，方案唯一
    // 否则存在多种方案
    if (n == max_balanced)
        cout << "NO\n";
    else
        cout << "YES\n";
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