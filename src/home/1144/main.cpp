#define LOCAL
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    n *= 2;
    int ans = ceil(log(n + 1) / log(3) - 1);
    if (ans == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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