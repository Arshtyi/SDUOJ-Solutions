#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct vec
{
    int x,y;
    vec (int x = 0,int y = 0):x(x),y(y) {}
};

bool less_cmp(const vec &a,const vec &b){
    return a.x + a.y < b.x + b.y;
}

 main(){
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int T,n;cin >> T;
    vector<vec> VEC[T];
    for (int i = 0;i < T;i ++)
    {   
        cin >> n;int a,b;
        for(int j = 0;j < n;j ++){
            cin >> a >> b;
            VEC[i].push_back(vec(a,b));
        }
        stable_sort(VEC[i].begin(),VEC[i].end(),less_cmp);
    }
    for(const auto &SO:VEC){
        for(const auto &so : SO){
            cout << so.x << " " << so.y << endl;
        }
    }
    
    return 0;
}