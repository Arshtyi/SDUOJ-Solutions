#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int s[N], ns[N];
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            cout << (s[i] + s[i + 1]) / 2 << " ";
        else if (i == n)
            cout << (s[i] + s[i - 1]) / 2 << " ";
        else
            cout << (s[i - 1] + s[i] + s[i + 1]) / 3 << " ";
    }
    cout << endl;
    return 0;
}