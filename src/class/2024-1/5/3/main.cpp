#include <stdio.h>
#include <limits.h>
struct num
{
    int rooster,hen,chick,total,methods;
}chickenCounts = {
    0,0,0,0,0,
},min_num = {
    0,0,0,INT_MAX,0,
};
int main (){
    int money;scanf("%d",&money);
    for(int i = 1;money - 5 * i > 0;i ++){
        chickenCounts.rooster = i;
        chickenCounts.hen = 0;
        chickenCounts.chick = 0;
        for(int j = 1;money - 5 * i - 3 * j > 0;j ++){
            chickenCounts.hen = j;
            chickenCounts.chick =3 *( money - 5 * i - 3 * j);
            chickenCounts.methods ++;
            chickenCounts.total = chickenCounts.rooster + chickenCounts.hen + chickenCounts.chick;
            if(chickenCounts.total < min_num.total)min_num = chickenCounts;
        }
    }
    min_num.methods = chickenCounts.methods; 
    printf("%d\n%d %d %d %d",min_num.methods,min_num.total,min_num.rooster,min_num.hen,min_num.chick);
    return 0;
}