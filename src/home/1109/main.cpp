#include <bits/stdc++.h>
using namespace std;
const int l = 8;
struct Node
{
    int s,c,x;bool t;
    Node(int s,int c,int x,bool t):s(s),c(c),x(x),t(t){}
};
struct cmp
{
    bool operator()(Node a,Node b){
        if (a.t && b.t)if(a.c == b.c)return a.x > b.x;else return a.c < b.c;
        if(a.t && !b.t)return 0;
        if(!a.t && b.t)return 1;
        return 1;//0
    }
};
priority_queue<Node,vector<Node>,cmp> q;
int main(){
    for(int i = 1;i <= 7;i ++){int a,b;cin >> a >> b;q.push(Node(a+b,a+b-l,i,a+b>l));}
    if (q.top().t)cout << q.top().x << endl;else cout << 0 << endl;
    return 0;
}
