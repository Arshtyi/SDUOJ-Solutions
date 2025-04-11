#include <bits/stdc++.h>
using namespace std;

signed main (){
    int N;cin >> N;
    int sum = N / 10;
    while (N >= 50)
    {
        N -= 50;
        sum += 2;
    }

    while (N >= 30)
    {
        N -= 30;
        sum ++;
    }
    cout << sum << endl;
    return 0;
}