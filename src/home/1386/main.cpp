// SUDOJ本题只有C语言模版
#define LOCAL
#include <bits/stdc++.h>
using namespace std;
signed main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int a, b;
    string c;
    cin >> a >> b >> c;

    // Convert c from base a to base 10
    bool is_float = false;
    long long int_part = 0;
    double frac_part = 0.0;
    size_t point_pos = c.find('.');
    if (point_pos != string::npos)
    {
        is_float = true;
        string int_str = c.substr(0, point_pos);
        string frac_str = c.substr(point_pos + 1);

        // Convert integer part
        for (char ch : int_str)
        {
            int_part = int_part * a + (isdigit(ch) ? ch - '0' : ch - 'A' + 10);
        }

        // Convert fractional part
        double base = 1.0 / a;
        for (char ch : frac_str)
        {
            frac_part += (isdigit(ch) ? ch - '0' : ch - 'A' + 10) * base;
            base /= a;
        }
    }
    else
    {
        // Convert integer part
        for (char ch : c)
        {
            int_part = int_part * a + (isdigit(ch) ? ch - '0' : ch - 'A' + 10);
        }
    }

    // Combine integer and fractional parts
    double base10_value = int_part + frac_part;

    // Convert base 10 value to base b
    string result;
    if (is_float)
    {
        // Convert fractional part
        double frac_part_b = base10_value - (long long)base10_value;
        long long int_part_b = (long long)base10_value;
        while (int_part_b > 0)
        {
            int digit = int_part_b % b;
            result += (digit < 10 ? '0' + digit : 'A' + digit - 10);
            int_part_b /= b;
        }
        reverse(result.begin(), result.end());
        if (frac_part_b > 0)
        {
            result += '.';
            int count = 0;
            while (frac_part_b > 0 && count < 12)
            { // Limit to 12 decimal places
                frac_part_b *= b;
                int digit = (int)frac_part_b;
                result += (digit < 10 ? '0' + digit : 'A' + digit - 10);
                frac_part_b -= digit;
                count++;
            }
        }
        // Limit to 8 decimal places
        result = result.substr(0, result.find('.') + 9);
    }
    else
    {
        // Convert integer part
        long long int_part_b = (long long)base10_value;
        while (int_part_b > 0)
        {
            int digit = int_part_b % b;
            result += (digit < 10 ? '0' + digit : 'A' + digit - 10);
            int_part_b /= b;
        }
        reverse(result.begin(), result.end());
    }

    cout << result << endl;
    return 0;
}