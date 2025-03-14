//简单素数判断
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n);
int main(){
  cout<<1<<endl;
    int x;cin >> x;
    while (cin >> x)if(isPrime(x)) cout << x << " " ;
    return 0;
}
bool isPrime(int n){
    if(n == 1 || n == 4)return false;
    if(n == 2 || n == 3)return true;
    if(n % 6 != 1 && n % 6 != 5)return false;
    int tmp = sqrt(n);
    for(int i = 5; i <= tmp; i += 6){
        if(n % i == 0 || n % (i + 2) == 0)return false;
    }
    return true;
}
