#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int s[N];
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int st, ed;
        cin >> st >> ed;

        for (int j = st; j < ed; j++)
        {
            s[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        for (int j = st; j < ed; j++)
        {
            s[j]++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        if (s[i] == 2)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}