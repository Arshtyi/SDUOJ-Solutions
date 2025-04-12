#include <stdio.h>
int main()
{
    int a, b;scanf("%d%d",&a,&b);
    int m[a];for(int i=0;i<a;i++)scanf("%d",&m[i]);
    int left = 0, right = a - 1,mid, flag = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (m[mid] == b) {printf("%d", mid);return 0;} 
        else if (m[mid] < b) left = mid + 1; 
        else if (m[mid] > b) right = mid - 1;
    }
    printf("-1");return 0;
}