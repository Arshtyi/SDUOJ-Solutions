#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    while (n--)
    {
        double x,y,area = 0;cin >> x >> y;
        if(y < 0){
            cout << "inf" << endl;
            continue;
        }
        int i ;
        for(i = 1;i < 730;i ++){
            area += 100;
            if(M_PI*(x*x + y*y) < area){
                cout << i << endl;
                break;
            }
        }
        if(i == 730) cout << "inf" << endl;
    }
    
    return 0;
}