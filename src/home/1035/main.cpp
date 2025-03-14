#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mul (int n){
    if(n == 1)return 1;
    return n * mul(n-1);
}
int main(){
    int n;cin>>n;cout<<mul(n);
    return 0;
}