#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, L, v1, v2, K;
    cin >> n >> L >> v1 >> v2 >> K;
    int G = ceil((double)n / K);
    double c = (double)G / (v2 - v1) + (double)(G - 1) / (v1 + v2);
    cout << fixed << setprecision(10) << (double)L / (v1 + 1 / c) << endl;
}
signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}