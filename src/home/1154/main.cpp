#include <bits/stdc++.h>
using namespace std;
void solve(){
    int hp;string l,r;cin >> hp >> l >> r;
    int sub;
    if(l.length() != r.length()) sub = abs(int(l.length()) - int(r.length()));
    else if(l == r) sub = 0;
    else sub = 1;
    int damage=0;
    if(sub >= 1)damage = 1;
    else {
        if(l.length() <= 1) damage = atoi(l.c_str());
        else damage = 100;
    }
    if(hp > damage) cout << "GG" << endl;
    else cout << "haha" << endl;
}
signed main(){
    //显然,gcd(n,n+1)=1
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0; 
}