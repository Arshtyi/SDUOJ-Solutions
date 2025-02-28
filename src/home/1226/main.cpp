#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int s[N];
signed main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (s[i] - s[i - 1] == 1)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}