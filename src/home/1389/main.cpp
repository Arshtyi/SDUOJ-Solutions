#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n, k;
    cin >> n >> k;
    n *= 3;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < n; i += 3)
    {
        cnt += (s[i + 2] - s[i] <= k) ? 0 : ((s[i + 2] - s[i + 1] <= k) ? (s[i + 2] - s[i] - k) : (2 * s[i + 2] - s[i + 1] - s[i] - 2 * k));
    }
    cout << cnt << endl;
    return 0;
}