#include <bits/stdc++.h>
using namespace std;
const int N = 505;
class BigInt
{
public:
    string value;

    BigInt(string val = "0") : value(val) {}

    BigInt operator*(const BigInt &other) const
    {
        string rev_value = value;
        string rev_other = other.value;
        int la = rev_value.size(), lb = rev_other.size(), l = la + lb;
        vector<int> res(l, 0);
        l--;
        reverse(rev_value.begin(), rev_value.end());
        reverse(rev_other.begin(), rev_other.end());
        for (int i = 0; i < la; ++i)
        {
            for (int j = 0; j < lb; ++j)
            {
                res[i + j] += (rev_value[i] - '0') * (rev_other[j] - '0');
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
        while (l > 0 && res[l] == 0)
            l--;
        string ans;
        for (int i = l; i >= 0; --i)
        {
            ans.push_back(res[i] + '0');
        }
        return BigInt(ans);
    }

    BigInt operator/(const int other) const
    {
        int l = value.size(), x = 0;
        vector<int> res(l, 0), IV(l, 0);
        for (int i = 0; i < l; i++)
            IV[i] = value[i] - '0';
        for (int i = 0; i < l; ++i)
        {
            res[i] = (x * 10 + IV[i]) / other;
            x = (x * 10 + IV[i]) % other;
        }
        int lc = 0;
        while (lc < l && res[lc] == 0)
            lc++;
        string ans;
        for (int i = lc; i < l; i++)
            ans.push_back(res[i] + '0');
        return BigInt(ans);
    }
};
vector<BigInt> Catalan(N);
signed main()
{
    int T;
    cin >> T;
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
        {
            Catalan[i] = BigInt("1");
        }
        else
        {
            BigInt temp = Catalan[i - 1] * BigInt(to_string(4 * i - 2));
            Catalan[i] = temp / (i + 1);
        }
    }
    while (T--)
    {
        int n;
        cin >> n;
        cout << Catalan[n].value << endl;
    }
    return 0;
}