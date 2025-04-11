#include <bits/stdc++.h>
using namespace std;
const int N = 59;
const vector<int> weight = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
void solve()
{
    int n;
    cin >> n;
    vector<int> curweight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> curweight[i];
    }
    if (n == 1 && (curweight[0] != 1 && curweight[0] != 30))
    {
        cout << "No Response\n";
        return;
    }
    int i, j;
    for (i = 0; i < N; ++i)
    {
        if (curweight[0] == weight[i])
        {
            for (j = 1; j < n; ++j)
            {
                if (curweight[j] != weight[(i + j) % (N - 1)])
                {
                    break;
                }
            }
            if (j == n)
            {
                cout << (weight[(i + j) % (N - 1)] > curweight[n - 1] ? "Heavy" : "Light") << endl;
                return;
            }
        }
    }
    cout << "No Response\n";
    return;
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