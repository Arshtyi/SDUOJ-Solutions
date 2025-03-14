// 找不到正确题面，姑且晾着
#define LOCAL
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
struct Node
{
    int n, h;
    Node(int n = 0, int h = 0) : n(n), h(h) {}
};
vector<Node> a(N);
// 前三名是需要格外照顾的，他们所站的位置需要严格高于排名比其低的人。而其他人则没有那么多要求，他们只需要站的位置不低于排名比其低的人即可。

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].h;
        a[i].n = i;
    }
    if (n == 1)
    {
        cout << "Yes\n";
        return;
    }
    if (n == 2)
    {
        if (a[1].h == a[2].h)
            cout << "No\n";
        else
            cout << "Yes\n";
        return;
    }
    if (n == 3)
    {
        if ((a[2].h > a[1].h && a[1].h > a[3].h) || (a[2].h > a[3].h && a[3].h > a[1].h))
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }
    int mid = ceil(n / 2.0);
    // n>=4
    if (!(a[mid].h > a[mid + 1].h && a[mid + 1].h > a[mid - 1].h) && !(a[mid].h > a[mid - 1].h && a[mid - 1].h > a[mid + 1].h))
    {
        cout << "No\n";
        return;
    }
    bool flag = true;
    for (int i = mid - 1; i >= 1 || i <= n;)
    {
    }
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