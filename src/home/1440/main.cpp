#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> s(N);
signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int target;
        cin >> target;
        auto it = lower_bound(s.begin() + 1, s.begin() + n + 1, target);
        cout << distance(s.begin(), it) << endl;
    }
    return 0;
}