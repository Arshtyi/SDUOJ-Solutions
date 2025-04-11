#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int grid[N][N];
signed main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++)
        {
            for (int k = y1; k < y2; k++)
            {
                if (!grid[j][k])
                {
                    grid[j][k]++;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}