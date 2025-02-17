#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bool directions[N];
int locations[N];
int main(){
    int T;cin >> T;
    while (T--)
    {
        int n;cin >> n;
        for(int i = 1;i <= n;i ++){
            char c;cin >> c;
            directions[i] = (c == 'L') ? 0 : 1;//左零右一
        }
        for(int i = 1;i <= n;i ++){
            cin >> locations[i];
        }
        int gap = 0;
        for(int i = 1;i < n;i ++){
            if(directions[i] != directions[i + 1]){
                gap ++;
            }
        }
        if(gap == 0 || gap == 1){
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        bool flag = 0;
        while (1)
        {
            cnt++;
            for(int i = 1;i <= n;i ++){
                locations[i] += (directions[i] ? 1 : -1);
            }
            for(int i = 1;i < n;i ++){
                if(locations[i] == locations[i + 1]){
                    cout << cnt << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    return 0;
}