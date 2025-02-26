#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> diff(n);
    for(int i = 0; i < n; i++){
        if(i == 0) diff[i] = v[i];
        else diff[i] = abs(v[i] - v[i-1]);
    }
    cout << *min_element(diff.begin() + 1, diff.end()) << endl;//注意+1是因为diff[0]可能是0，但这不是差值
    return 0;
}