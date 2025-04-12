#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    while (cin >> n) {
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}