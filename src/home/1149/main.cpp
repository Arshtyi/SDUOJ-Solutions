#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll T;cin >> T;
    while (T--)
    {
        ll x, i = 0;cin >> x;
        for(i = 0;x != 1;i ++)if(!(x & 1)) x >>= 1;else x = 3 * x + 1;
        cout << i << endl;
    }
    return 0;
}