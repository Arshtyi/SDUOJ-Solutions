#define LOCAL
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll a[N], pre[N], l[N], r[N], indexs[N];
vector<int> v(N), res(N);
void solve()
{
    int n;
    cin >> n;
    l[n + 1] = n, r[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    };
    for (int i = 1; i <= n; ++i)
    {
        cin >> indexs[i];
    }
    res[1] = 0;
    for (int i = n; i >= 2; --i)
    {
        int index = indexs[i];
    }
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
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