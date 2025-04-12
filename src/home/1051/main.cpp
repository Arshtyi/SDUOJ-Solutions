#define LOCAL
#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    cin>>n>>s;
    while (n--)
    {
        int op;cin >> op;
        if(op == 1){
            string t;cin >> t;s += t;cout << s << endl;
        }
        if(op == 2){
            int a, b;cin >> a >> b;s=s.substr(a, b);cout << s << endl;
        }
        if(op == 3){
            int a;string t;cin >> a >> t;
            s.insert(a, t);cout << s << endl;
        }
        if(op == 4){
            string t;cin >> t;size_t pos = s.find(t);
            if(pos != string::npos)cout << pos << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}