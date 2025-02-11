#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;cin >> n;
    ll x,ans = 0,sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> x;sum += x;
        if(sum < 0){
            ans = max(ans,-sum);
        }
    }
    cout << ans << endl;
    return 0;
}