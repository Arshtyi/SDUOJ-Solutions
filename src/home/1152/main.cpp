#include <bits/stdc++.h>
using namespace std;
const int N = 9;
void solve()
{
    int grid[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            map<int, int> mp;
            for (int k = 0; k < 3; ++k)
            {
                for (int l = 0; l < 3; ++l)
                {
                    mp[grid[i * 3 + k][j * 3 + l]]++;
                }
            }
            if (mp.size() != 9)
            {
                cout << "Wrong Answer\n";
                return;
            }
        }
    }
    cout << "Accepted\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}