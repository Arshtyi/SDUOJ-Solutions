#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    int V,N;scanf("%d %d",&V,&N);int v[N],w[N];
    for (int i = 0; i < N; i++)scanf("%d",&v[i]);for (int i = 0; i < N; i++)scanf("%d",&w[i]);
    int Y[N],X[N];memset(Y,0,sizeof(Y));memset(X,0,sizeof(X));
    int weight = 0,value = 0,NT = pow(2,N);
    for(int i = 1;i < NT - 1;i++){
        int Cweight = 0,Cvalue = 0;
        int tn = N - 1;
        int j = i;
        do{Y[tn] = j & 1;tn --;}while(j >>= 1);
        for(j = 0;j < N;j++){Cweight += Y[j] * v[j];Cvalue += Y[j] * w[j];}
        if(Cweight <= V && Cvalue > value){
            weight = Cweight;value = Cvalue;
            for(int k = 0;k < N;k++)X[k] = Y[k];
        }
    }
    for(int i = 0;i < N;i++ ){if(X[i])printf("%d ",i + 1);}printf("%d %d",weight,value);
    return 0;
}