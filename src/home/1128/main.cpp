#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int main(){
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    cin >> n >> m;
    int board[n][m],ref[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];ref[i][j] = board[i][j];
        }
    }
    for(int i = 0;i < n; i++){
        for(int j = 0;j + 2 < m;j ++){
            int cnt = 1;
            for(int k = j + 1; k < m; k++){
                if(ref[i][j] == ref[i][k])cnt++;
                else break;
            }
            if(cnt >= 3){
                for(int k = j; k < j + cnt; k++){
                    board[i][k] = 0;
                }
            }
        }
    }
    for(int i = 0;i < m; i++){
        for(int j = 0;j + 2 < n;j ++){
            int cnt = 1;
            for(int k = j + 1; k < n; k++){
                if(ref[j][i] == ref[k][i])cnt++;
                else break;
            }
            if(cnt >= 3){
                for(int k = j; k < j + cnt; k++){
                    board[k][i] = 0;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}