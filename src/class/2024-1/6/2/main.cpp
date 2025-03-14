#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct inf
{
    int ID,math1,math2,math;
};
int main(){
    int n,s;scanf("%d %d",&n,&s);struct inf inp[n];
    for(int i = 0;i < n;i ++){
        scanf("%d %d %d",&inp[i].ID,&inp[i].math1,&inp[i].math2);
        inp[i].math = inp[i].math1 + inp[i].math2;
    }
    if(n <= s){
        for(int i = 0;i < n - 1;i ++){
            for(int j = 0;j < n - i - 1;j ++){
                if(inp[j].ID > inp[j + 1].ID){
                    struct inf temp;
                    temp = inp[j];
                    inp[j] = inp[j + 1];
                    inp[j + 1] = temp;
                }
            }
        }
        for(int i = 0;i < n;i ++)printf("%d\n",inp[i].ID);
    }else{
        for(int i = 0;i < n - 1;i ++){
            for(int j = 0;j < n - i - 1;j ++){
                if(inp[j].math < inp[j + 1].math){
                    struct inf temp;
                    temp = inp[j];
                    inp[j] = inp[j + 1];
                    inp[j + 1] = temp;
                }else if (inp[j].math == inp[j + 1].math && inp[j].math1 < inp[j + 1].math1)
                {
                    struct inf temp;
                    temp = inp[j];
                    inp[j] = inp[j + 1];
                    inp[j + 1] = temp;
                }else if(inp[j].math == inp[j + 1].math && inp[j].math1 == inp[j + 1].math1 && inp[j].ID > inp[j + 1].ID){
                    struct inf temp;
                    temp = inp[j];
                    inp[j] = inp[j + 1];
                    inp[j + 1] = temp;
                }
            }
        }
        for(int i = 0;i < s - 1;i ++){
            for(int j = 0;j < s - i - 1;j ++){
                if(inp[j].ID > inp[j + 1].ID){
                    struct inf temp;
                    temp = inp[j];
                    inp[j] = inp[j + 1];
                    inp[j + 1] = temp;
                }
            }
        }
        for(int i = 0;i < s;i ++)printf("%d\n",inp[i].ID);
    }
    return 0;
}