#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        // 记录结果
        vector<long long> ans(n + 1, 0);

        // 用于标记位置是否存在（初始都存在）
        vector<bool> exists(n + 1, true);

        // 用map维护每个连续区段 [left, right] -> sum
        map<pair<int, int>, long long> segments;

        // 用于根据位置找到其所在的区段
        map<int, pair<int, int>> pos_to_segment;

        // 用于维护所有区段和的多重集合，方便快速找最大值
        multiset<long long> segment_sums;

        // 初始化：全部是连续的一个区段
        segments[{1, n}] = 0;
        for (int i = 1; i <= n; i++)
        {
            segments[{1, n}] += a[i];
            pos_to_segment[i] = {1, n};
        }
        segment_sums.insert(segments[{1, n}]);

        // 按顺序移除元素
        for (int i = 1; i <= n; i++)
        {
            int pos = b[i];                               // 当前要移除的位置
            pair<int, int> segment = pos_to_segment[pos]; // 该位置所在的区段

            // 从multiset中移除当前区段的和
            segment_sums.erase(segment_sums.find(segments[segment]));

            // 从映射中移除当前区段
            segments.erase(segment);

            // 移除该位置
            exists[pos] = false;

            // 检查是否需要将当前区段分成两部分
            int left = segment.first;
            int right = segment.second;

            // 左侧区段 [left, pos-1]
            if (left <= pos - 1)
            {
                long long left_sum = 0;
                for (int j = left; j <= pos - 1; j++)
                {
                    left_sum += a[j];
                    pos_to_segment[j] = {left, pos - 1};
                }
                segments[{left, pos - 1}] = left_sum;
                segment_sums.insert(left_sum);
            }

            // 右侧区段 [pos+1, right]
            if (pos + 1 <= right)
            {
                long long right_sum = 0;
                for (int j = pos + 1; j <= right; j++)
                {
                    right_sum += a[j];
                    pos_to_segment[j] = {pos + 1, right};
                }
                segments[{pos + 1, right}] = right_sum;
                segment_sums.insert(right_sum);
            }

            // 记录当前最大区段和
            ans[i] = segment_sums.empty() ? 0 : *segment_sums.rbegin();
        }

        // 输出结果
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << endl;
        }
    }

    return 0;
}