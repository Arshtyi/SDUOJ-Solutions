/**
 * 如果你看到这个注释，说明此题作者并未AC
 * 一方面，题面描述非常不清楚，另一方面，已经无法找到原始正确的题面了
 * 如果你知道正确的题面orAC代码，请联系作者，这对作者很重要
 * 2025/4/5 14:42 于SDUQD
 */
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
#define notie ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
int n;
// 检查特定排名分配是否满足高度要求
bool checkArrangement(const vector<int> &heights, const vector<int> &ranks)
{
    int n = heights.size();
    // 验证高度要求
    FOR(pos, 0, n - 1)
    {
        int current_rank = ranks[pos];
        FOR(other_pos, 0, n - 1)
        {
            int other_rank = ranks[other_pos];
            // 前三名需要严格高于排名更低的所有人
            if (current_rank <= 3 && other_rank > 3)
                if (heights[pos] <= heights[other_pos])
                    return false;
            // 所有人需要不低于排名比自己低的人
            if (current_rank < other_rank)
                if (heights[pos] < heights[other_pos])
                    return false;
        }
    }
    return true;
}

bool solve()
{
    vector<int> heights(n);
    FOR(i, 0, n - 1)
    cin >> heights[i];

    // 可能的"中间"位置
    vector<int> mids;
    if (n % 2 == 1)
    {
        // 奇数情况，中间就是n/2
        mids.push_back(n / 2);
    }
    else
    {
        // 偶数情况，有两个可能的"中间"位置
        mids.push_back(n / 2 - 1); // 左中位置
        mids.push_back(n / 2);     // 右中位置
    }

    // 尝试每个可能的中间位置
    for (int mid : mids)
    {
        // 方案1：左边是2,4,6...，右边是3,5,7...
        vector<int> ranks1(n);
        ranks1[mid] = 1;
        int left = mid - 1;
        int right = mid + 1;
        int rank = 2;
        while (rank <= n)
        {
            if (left >= 0)
                ranks1[left--] = rank++;
            if (rank <= n && right < n)
                ranks1[right++] = rank++;
        }

        // 方案2：左边是3,5,7...，右边是2,4,6...
        vector<int> ranks2(n);
        ranks2[mid] = 1;
        left = mid - 1;
        right = mid + 1;
        rank = 2;
        while (rank <= n)
        {
            if (right < n)
                ranks2[right++] = rank++;
            if (rank <= n && left >= 0)
                ranks2[left--] = rank++;
        }

        if (checkArrangement(heights, ranks1) || checkArrangement(heights, ranks2))
        {
            return true;
        }
    }

    return false;
}

signed main()
{
    // LOCAL;
    notie;
    while (cin >> n && n)
    {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}