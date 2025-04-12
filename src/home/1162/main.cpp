#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define notie cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl '\n'
#define pb push_back
#define mkp make_pair
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
signed main()
{
    LOCAL;
    notie;
    int T = 1;
    cin >> T;
    while (T--)
    {
        int m, n;
        cin >> m >> n;
        cout << ((m * n) & 1 ? "Hui" : "Gua") << endl;
    }

    return 0;
}