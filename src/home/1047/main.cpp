#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    cin >> s;
    for(int i = 0;i < s.length();i++)if(islower(s[i])) s[i] = toupper(s[i]);
    cout << s << endl;
    return 0;
}