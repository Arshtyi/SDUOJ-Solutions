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
    cin>>n;cin.ignore();
    getline(cin,s);
    while (n--)
    {
        string op;getline(cin,op);
        if(op[0] == '1'){
            s += op.substr(2);
            cout << s << endl;
        }else if(op[0] == '2'){
            int a, b;
            sscanf(op.c_str(), "2 %d %d", &a, &b);
            s = s.substr(a, b);
            cout << s << endl;
        }else if(op[0] == '3'){
            int a;sscanf(op.c_str(), "3 %d", &a);
            string t = op.substr(2 + to_string(a).length() + 1);
            s.insert(a, t);
            cout << s << endl;
        }else if(op[0] == '4'){
            string t = op.substr(2);
            size_t pos = s.find(t);
            if(pos != string::npos){
                cout << pos << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}