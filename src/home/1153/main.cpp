#define LOCAL
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 100;
struct Node
{
    int length;
    bool exist;
    Node(int length = 0, bool exist = true) : length(length), exist(exist) {}
};
vector<Node> dp(N);
int pre[N];
void solve()
{
    int n;
    cin >> n;
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