#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        vector<string> v;
        int m = s.size();
        for (int i = 0; i < m; i += 2)
        {
            v.push_back(s.substr(i, 2));
        }
        bool flag = true;
        m /= 2;
        for (int i = 0; i < m; ++i)
        {
            if (v[i] != v[m - i - 1])
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}