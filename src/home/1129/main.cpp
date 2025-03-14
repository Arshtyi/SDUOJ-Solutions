#include <bits/stdc++.h>
using namespace std;
int l, r, cnt, letter[30];
char let[30];
void init(string s)
{
    for (int i = 0; i < 26; i++)
    {
        if (s[i] != '?')
            letter[s[i] - 'A']++;
        else
            letter[26]++;
    }
}
bool judge()
{
    cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (letter[i] > 1)
            return false;
        else if (!letter[i])
            cnt++;
    }
    if (cnt == letter[26])
        return true;
    return false;
}
int main()
{
    string s;
    cin >> s;
    if (s.size() < 26)
        cout << -1 << endl;
    init(s), l = 0, r = 25;
    while (r < s.size())
    {
        if (judge())
        {
            cnt = 0;
            for (int i = 0; i < 26; i++)
                if (!letter[i])
                {
                    let[cnt] = (char)(i + 'A');
                    cnt++;
                }
            cnt = 0;
            for (int i = l; i <= r; i++)
            {
                if (s[i] == '?')
                {
                    cout << let[cnt];
                    cnt++;
                }
                else
                    cout << s[i];
            }
            cout << endl;
            return 0;
        }
        else
        {
            if (s[l] == '?')
                letter[26]--;
            else
                letter[s[l] - 'A']--;
            l++, r++;
            if (r < s.size())
            {
                if (s[r] == '?')
                    letter[26]++;
                else
                    letter[s[r] - 'A']++;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}