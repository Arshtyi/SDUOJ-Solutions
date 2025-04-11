#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int inp;
        cin >> inp;
        cnt[inp]++;
    }
    int maxnum = -1, maxst;
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    {
        if (it->second > maxnum)
        {
            maxnum = it->second;
            maxst = it->first;
        }
    }
    cout << maxst << endl;

    return 0;
}