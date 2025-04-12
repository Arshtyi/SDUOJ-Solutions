#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define notie cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl '\n'
#define pb push_back
#define mkp make_pair
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
signed main()
{
    int n;
    cin >> n;
    int s[n][n];
    FOR(i, 0, n - 1)
    FOR(j, 0, n - 1)
    cin >> s[i][j];
    int x = 0, y = 0;
    FOR(i, 0, n - 1)
    {
        if (i & 1)
        {
            FOR(j, 0, i - 1)
            cout << s[x++][y--] << " ";
            cout << s[x++][y] << " ";
        }
        else
        {
            FOR(j, 0, i - 1)
            cout << s[x--][y++] << " ";
            cout << s[x][y++] << " ";
        }
    }

    if (n & 1)
        y--, x++;
    else
        y++, x--;
    ROF(i, n - 2, 1)
    {
        if (i & 1)
        {
            FOR(j, 0, i - 1)
            cout << s[x++][y--] << " ";
            cout << s[x][y++] << " ";
        }
        else
        {
            FOR(j, 0, i - 1)
            cout << s[x--][y++] << " ";
            cout << s[x++][y] << " ";
        }
    }
    if (n != 1)
        cout << s[n - 1][n - 1] << " ";
    return 0;
}