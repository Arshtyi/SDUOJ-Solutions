#define LOCAL
#include <bits/stdc++.h>
using namespace std;
// 优先选择结束早的，相同则选择开始晚的
struct Node
{
    int st, ed;
    Node(int st, int ed) : st(st), ed(ed) {}
};
vector<Node> v;

void processAndSort(vector<Node> &v)
{
    unordered_map<int, int> maxStartTimes;
    for (const auto &node : v)
    {
        if (maxStartTimes.find(node.ed) == maxStartTimes.end())
        {
            maxStartTimes[node.ed] = node.st;
        }
        else
        {
            maxStartTimes[node.ed] = max(maxStartTimes[node.ed], node.st);
        }
    }
    for (auto &node : v)
    {
        node.st = maxStartTimes[node.ed];
    }
    sort(v.begin(), v.end(), [](const Node &a, const Node &b)
         { return a.ed < b.ed; });
}
signed main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        v.push_back(Node(st, ed));
    }
    processAndSort(v);
    int cnt = 0, ced = 0;
    for (auto &node : v)
    {
        if (node.st >= ced)
        {
            cnt++;
            ced = node.ed;
        }
    }
    cout << cnt << endl;
    return 0;
}