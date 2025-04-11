#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node
{
    int location;
    bool direction;
    Node(int location = 0, bool direction = 0) : location(location), direction(direction) {}
};
vector<Node> nodes(N);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            nodes[i].direction = (c == 'R' ? 1 : 0);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> nodes[i].location;
        }
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i)
        {
            if (nodes[i].direction == 1 && nodes[i + 1].direction == 0)
            {
                ans = min(ans, (nodes[i + 1].location - nodes[i].location) / 2);
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}