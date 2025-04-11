#include <bits/stdc++.h>
using namespace std;
int main(){
    int mother=0,son=0,pre;
    for(int i = 1;i <= 12;i ++){
        son += 300;cin >> pre;
        if(son < pre){
            cout << "-" << i;
            return 0;
        }
        son -= pre;
        mother += son / 100 * 100;
        son %= 100;
    }
    cout << mother * 1.2 + son;
    return 0;
}