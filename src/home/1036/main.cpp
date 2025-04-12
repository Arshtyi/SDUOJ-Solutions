#include <bits/stdc++.h>
using namespace std;
void pardon(int *st,int x,int y);
int main(){
    int n;cin>>n;int t = (int)pow(2,n);int mat[t][t];
    for(int i = 0;i < t;i ++)for(int j = 0;j < t;j ++)mat[i][j]=1;
    pardon(&mat[0][0],t,t);
    for(int i = 0;i < t;i ++){
        for(int j = 0;j < t;j ++)cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
void pardon(int *st,int x,int y){
    int *p,k,row; 
	if(x > 0)
	{
		for(p = st,row = 0;row < x  / 2;p += y,row ++)for(k = 0;k < x / 2;k ++)*(p+k) = 0;
		pardon(st+x/2,x/2,y),pardon(st+y*x/2,x/2,y),pardon(st+(y+1)*x/2,x/2,y);
	}	
}