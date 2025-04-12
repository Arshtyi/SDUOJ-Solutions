#include <bits/stdc++.h>
using namespace std;
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
#define notie ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

// 移除多余的零并格式化结果
string formatResult(string result)
{
    // 移除尾部的零
    while (!result.empty() && result.back() == '0')
    {
        result.pop_back();
    }

    // 移除尾部的小数点
    if (!result.empty() && result.back() == '.')
    {
        result.pop_back();
    }

    // 移除开头的零
    while (result.size() > 1 && result[0] == '0' && result[1] != '.')
    {
        result.erase(result.begin());
    }

    return result;
}

// 模拟从指定位置开始的四舍五入操作
string roundFromPosition(string num, int pos)
{
    // 截取需要保留的部分
    string result = num.substr(0, pos);

    // 如果当前位置大于等于5，需要进位
    if (pos < num.size() && num[pos] >= '5')
    {
        int i = result.size() - 1;
        bool carry = true;

        // 处理进位
        while (i >= 0 && carry)
        {
            if (result[i] == '.')
            {
                i--;
                continue;
            }

            if (result[i] == '9')
            {
                result[i] = '0';
                i--;
            }
            else
            {
                result[i]++;
                carry = false;
            }
        }

        // 如果第一位需要进位
        if (carry)
        {
            result = "1" + result;
        }
    }

    return formatResult(result);
}

string findMaxRounding(string num, int k)
{
    // 找到小数点位置
    int decimalPos = num.find('.');
    if (decimalPos == string::npos)
    {
        return num; // 无小数点，无法进行四舍五入
    }

    // 清理尾部多余的零
    while (num.back() == '0')
    {
        num.pop_back();
    }

    // 如果末尾是小数点，直接移除
    if (num.back() == '.')
    {
        num.pop_back();
        return num;
    }

    // 寻找题目描述的模式：位于小数点后且最靠近小数点、长度<=K的符合"444...444a"(a>=5)形式的串
    for (int i = decimalPos + 1; i < num.size(); i++)
    {
        if (num[i] >= '5')
        {
            // 向前查找连续的4
            int j = i - 1;
            int fourCount = 0;

            while (j > decimalPos && num[j] == '4' && fourCount < k - 1)
            {
                fourCount++;
                j--;
            }

            // 模式长度 = 4的个数 + 1(a>=5)
            int patternLength = fourCount + 1;

            // 如果模式长度<=k
            if (patternLength <= k)
            {
                // 模拟k次四舍五入
                string result = num;
                int operationsLeft = k;

                // 第一次四舍五入
                result = roundFromPosition(result, i);
                operationsLeft--;

                // 进行剩余的四舍五入操作
                while (operationsLeft > 0)
                {
                    // 寻找新的小数点位置
                    int newDecimalPos = result.find('.');
                    if (newDecimalPos == string::npos)
                    {
                        break; // 如果没有小数点了，无法继续四舍五入
                    }

                    // 寻找下一个>=5的位置
                    bool found = false;
                    for (int pos = newDecimalPos + 1; pos < result.size(); pos++)
                    {
                        if (result[pos] >= '5')
                        {
                            result = roundFromPosition(result, pos);
                            operationsLeft--;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        break; // 如果没有找到>=5的位置，无法继续四舍五入
                    }
                }

                return result;
            }
        }
    }

    // 如果没有找到符合条件的模式，但k>=1，尝试任何可能的四舍五入
    if (k >= 1)
    {
        for (int i = decimalPos + 1; i < num.size(); i++)
        {
            if (num[i] >= '5')
            {
                return roundFromPosition(num, i);
            }
        }
    }

    // 如果无法进行有效的四舍五入，返回原值
    return formatResult(num);
}

void solve()
{
    int k;
    cin >> k;
    string num;
    cin >> num;

    cout << findMaxRounding(num, k) << endl;
}

int main()
{
    // LOCAL;
    notie;

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}