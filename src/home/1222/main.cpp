#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int r, y, g, n, k, t, ti = 0;
    cin >> r >> y >> g >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k >> t;
        if (k == 0)
        {
            ti += t;
        }
        else if (k == 1)
        {
            ti += t;
        }
        else if (k == 2)
        {
            ti += t;
            ti += r;
        }
    }
    cout << ti << "\n";
    return 0;
}