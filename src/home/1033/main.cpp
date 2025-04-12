#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0,st,ed;cin >> st >> ed;
    vector<int> v;
    for(int i = st;i <= ed;i++){
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
            v.push_back(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    for(auto i : v) cout << i << " ";
    return 0;
}