#include <bits/stdc++.h>
using namespace std;
struct Letter
{
    string s;
}temp[5],letters[11]={
    {".***..*.*..*.*..*.*..***."},
    {"...*....*....*....*....*."},
    {".***....*..***..*....***."},
    {".***....*..***....*..***."},
    {".*.*..*.*..***....*....*."},
    {".***..*....***....*..***."},
    {".***..*....***..*.*..***."},
    {".***....*....*....*....*."},
    {".***..*.*..***..*.*..***."},
    {".***..*.*..***....*..***."},
    {".......*...***...*......."},
};//0-9,+//=一定在末尾，不管
char getLetter(string s){
    for(int i = 0;i < 10;i++){
        if(s == letters[i].s)return i + '0';
    }
    return '+';
}
int main(){
    string t;cin >> t;
    int n = t.length() / 5 - 1;//=不管
    for(int i = 0;i < 5;i++){
        cin >> temp[i].s;
    }
    cin >> t;
    string res = "";
    for(int i = 1;i <= n;i ++){
        string s = "";
        for(int j = 0;j < 5;j++){
            s += temp[j].s.substr((i - 1) * 5,5);
        }
        res += getLetter(s);
    }
    int a,b;
    sscanf(res.c_str(),"%d+%d",&a,&b);
    cout << a + b << endl;
    return 0;
}