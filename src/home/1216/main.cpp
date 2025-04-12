#include <bits/stdc++.h>
using namespace std;
signed main(){
    int N;cin >> N;
    vector<int> v;
    for(int i = 0;i < N;++i){
        int a;cin >> a;
        v.push_back(a);
    }
    int cnt = 0;
    for(int i = 0;i < v.size();++i){
        if(v[i] == 0)continue;
        if(find(v.begin(), v.end(), -v[i]) != v.end()){
            cnt++;
        }
        v[find(v.begin(), v.end(), -v[i]) - v.begin()] = 0;
        v[i] = 0;
    }
    cout << cnt << endl;
    return 0;
}