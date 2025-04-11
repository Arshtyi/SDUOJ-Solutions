#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> mp;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        cout << mp[x] << " ";
    }
    return 0;
}