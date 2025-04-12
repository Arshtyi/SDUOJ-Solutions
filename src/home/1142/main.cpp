#define LOCAL
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int cnt[N], pre[N];
void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s = "#" + s;
    int n = s.size();
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + cnt[i];
        if ((s[i] == '0' && pre[i] & 1) || (s[i] == '1' && !(pre[i] & 1)))
        {
            ++cnt[i + 1];
            ++ans;
        }
    }
    if (ans & 1)
        cout << "gou\n";
    else
        cout << "zhu\n";
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