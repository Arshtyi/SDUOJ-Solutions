#define LOCAL
#include <bits/stdc++.h>
using namespace std;
pair<vector<int>, vector<int>> slidingWindowMaxMin(const vector<int>& nums, int K) {
    int n = nums.size();
    if (n == 0 || K == 0) {
        return {{}, {}}; 
    }
    
    deque<int> maxDeque, minDeque; // 双端队列用于维护最大值和最小值
    vector<int> maxResult, minResult; // 存储每次滑动窗口的最大值和最小值
    
    for (int i = 0; i < n; ++i) {
        // 移除不在当前窗口的元素
        if (!maxDeque.empty() && maxDeque.front() < i - K + 1) {
            maxDeque.pop_front();
        }
        if (!minDeque.empty() && minDeque.front() < i - K + 1) {
            minDeque.pop_front();
        }

        // 维护最大值队列，确保队列中的元素从大到小
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(i);

        // 维护最小值队列，确保队列中的元素从小到大
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[i]) {
            minDeque.pop_back();
        }
        minDeque.push_back(i);

        // 当窗口大小达到 K 时，记录当前窗口的最大值和最小值
        if (i >= K - 1) {
            maxResult.push_back(nums[maxDeque.front()]);
            minResult.push_back(nums[minDeque.front()]);
        }
    }
    
    return {maxResult, minResult};
}
signed main(){
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif
    int n,k;cin >> n >> k;
    vector<int> window(n);
    for(int i = 0;i < n;i ++){
        cin >> window[i];
    }
    auto [maxResult,minResult] = slidingWindowMaxMin(window,k);
    for(auto minVal : minResult){
        cout << minVal << " ";
    }cout << endl;
    for(auto maxVal : maxResult){
        cout << maxVal << " ";
    }cout << endl;
    return 0;
}