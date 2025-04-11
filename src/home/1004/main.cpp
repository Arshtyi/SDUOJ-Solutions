#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,x,s;
int main(){
    while (cin >> n && n)
    {
        s=0;
        while (n--)
        {
            cin >> x;s+=x;
        }
        cout << s << endl;
    }
    return 0;
}