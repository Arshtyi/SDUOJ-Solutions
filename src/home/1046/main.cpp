#include <bits/stdc++.h>
using namespace std;
int n;string s;
int main(){
    cin >> n >> s;
    for(int i = 0;i <= s.length();i++){
        if(s[i] + n > 'z') s[i] = s[i] + n - 26;
        else s[i] = s[i] + n;
    }
    cout << s << endl;
    return 0;
}