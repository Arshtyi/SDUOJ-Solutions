// 不开long long一场空--2025/2/15
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    long long x,y;
    Node (long long x = 0,long long y = 0):x(x),y(y) {}
};
void solve(){
    long long n;cin >> n;
    vector<Node> v;
    for(long long i = 1;i<=n;i++){
        long long x,y;cin >> x>> y;
        v.push_back(Node(x,y));
    }
    stable_sort(v.begin(), v.end(), [](const Node &a, const Node &b) {
        return (a.x + a.y) < (b.x + b.y);
    });
    for(auto h : v){
        cout << h.x << " " << h.y << endl;
    }
}
signed main(){
    long long T; cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}