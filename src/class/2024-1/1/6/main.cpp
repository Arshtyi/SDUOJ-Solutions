#include <stdio.h>
int main(){
    short x;scanf("%hd",&x);printf("%hd\n",x);
    int y;scanf("%d",&y);printf("%u\n",y);
    long z;scanf("%ld",&z);printf("%o\n",z);
    long long m;scanf("%lld",&m);printf("%X\n",m);
    unsigned n;scanf("%u",&n);printf("%X\n",n);
    return 0;
}