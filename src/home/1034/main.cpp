#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin >> n >> m;
    vector<double> v;
    priority_queue<double,vector<double>,less<double> > pq;
    while (n--)
    {
        v.clear();
        for(int i = 0;i < m;i++){
            double x;cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        v.erase(v.begin());v.erase(v.end()-1);
        pq.push(accumulate(v.begin(),v.end(),0.0)/v.size());
    }
    cout << fixed << setprecision(2) << pq.top() << endl;
    return 0;
}