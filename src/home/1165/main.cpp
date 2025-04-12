#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define endl '\n'
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
#define notie ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void solve()
{
    int Kt;
    cin >> Kt;

    vector<ll> button_1_counts; // 存储每次按第二个按键前，按第一个按键的次数

    // 特殊处理K=1到K=2
    // 初始：A=2, K=1
    // 按两次按键1：A=4
    // 按一次按键2：A=2, K=2
    button_1_counts.push_back(2);

    ll A = 2, K = 2; // 按完按键2后的状态

    // 处理从K=2到K=Kt的升级过程
    while (K < Kt)
    {
        // 目标：构造A=(K(K+1))²
        ll factor = K * (K + 1); // 避免直接计算(K(K+1))²可能导致的溢出

        // 计算需要按多少次按键1
        // 公式：(target - A) / K = (K(K+1))² - A) / K
        ll press_count;
        if (factor <= 1e9)
        {
            // 如果K(K+1)不会溢出，直接计算
            ll target = factor * factor;
            press_count = (target - A) / K;
        }
        else
        {
            // 如果K(K+1)可能溢出，使用数学变形
            // (K(K+1))² = K²(K+1)²
            // ((K(K+1))² - A) / K = K(K+1)² - A/K
            press_count = K * (K + 1) * (K + 1) - A / K;
        }

        button_1_counts.push_back(press_count);

        // 更新状态（我们不需要实际计算A的值，只需要知道下一次循环开始时A=K(K+1)）
        A = K * (K + 1);
        K++;
    }

    // 输出结果
    for (ll count : button_1_counts)
    {
        cout << count << endl;
    }
}

signed main()
{
    LOCAL;
    notie;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}