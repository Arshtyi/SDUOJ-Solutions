#include <bits/stdc++.h>
/**
 * P = (2n-2)!!/(2n-1)!!
 * 显然是不能约分的
 */
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define notie cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl '\n'
#define pb push_back
#define mkp make_pair
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
const int N = 1e3 + 10;
double possibility[N];
void solve()
{
    possibility[1] = 1;
    FOR(i, 2, 1000)
    possibility[i] = possibility[i - 1] * (2 * i - 2) / (2 * i - 1);
}
signed main()
{
    notie;
    int T = 1;
    cin >> T;
    solve();
    while (T--)
    {
        int n;
        cin >> n;
        cout << fixed << setprecision(10) << possibility[n] << endl;
    }

    return 0;
}