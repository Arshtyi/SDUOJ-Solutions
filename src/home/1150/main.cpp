#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin >> n;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        if (num == 1) ++count;
    }
    cout << count << endl;
}
signed main(){
    int T;cin >> T;
    while(T--){
        solve();
    }

    return 0;
}