#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin >> n;
    while (n--)
    {
        double R,r;cin >> R >> r;
        double possiblity = (pow(r / (R - r),2) > 1) ? 1 : pow(r / (R - r),2);
        cout << fixed << setprecision(6) << possiblity << endl;
        cout << "YES" << endl;
    }
    
    return 0;
}