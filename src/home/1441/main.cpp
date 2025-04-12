#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 100;
struct Node
{
    ll deadline, profit;
    Node(ll deadline = 0, ll profit = 0) : deadline(deadline), profit(profit) {}
    static bool cmp(const Node &a, const Node &b)
    {
        return a.deadline < b.deadline;
    }
};
vector<Node> s(N);
priority_queue<ll, vector<ll>, greater<ll>> q;
ll ans = 0, now = 0;
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ll d, p;
        cin >> d >> p;
        s[i] = Node(d, p);
    }
    sort(s.begin() + 1, s.begin() + n + 1, Node::cmp);
    for (int i = 1; i <= n; ++i)
    {
        if (now < s[i].deadline)
        {
            ans += s[i].profit;
            q.push(s[i].profit);
            ++now;
        }
        else if (s[i].profit > q.top())
        {
            ans += s[i].profit - q.top();
            q.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}