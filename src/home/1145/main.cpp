#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n, t, s;
vector<string> names;
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin >> n >> t >> s;
    cin.ignore();
    while (n--)
    {
        string info;
        char ch;
        while (cin.get(ch) && ch != '\n')
        {
            info += ch;
        }
        // cout << info << endl;
        string name;
        size_t posName = info.find("use");
        name = info.substr(0, posName - 1);
        // cout << info << endl;
        size_t posUse = info.find("use") + 4;
        size_t firstComma = info.find(',');
        string Weapon = info.substr(posUse, firstComma - posUse - 1);
        transform(Weapon.begin(), Weapon.end(), Weapon.begin(), ::toupper);
        // cout << Weapon << endl;
        bool hited = Weapon.find("AK") != string::npos;
        size_t posHit = info.find("hit");
        if (!hited)
        {
            continue;
        }
        size_t pos = posHit;
        while (true)
        {
            size_t nextComma = info.find(',', pos + 1);
            if (nextComma == string::npos)
            {
                nextComma = info.find('.', pos + 1);
                if (nextComma == string::npos)
                {
                    break;
                }
            }
            string segment = info.substr(pos + 4, nextComma - pos - 4);
            if (segment == "ash")
            {
                t -= s;
                names.push_back(name);
                break;
            }
            pos = nextComma;
        }
    }
    if (t <= 0)
    {
        cout << "Heros never die." << endl;
    }
    else
    {
        cout << names.size() << endl;
        for (auto name : names)
        {
            cout << name << endl;
        }
    }
    return 0;
}