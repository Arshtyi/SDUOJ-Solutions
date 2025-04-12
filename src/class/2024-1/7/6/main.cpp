#define LOCAL
#include <bits/stdc++.h>
using namespace std;
bool isWho(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    return false;
}
bool isNum(char c){
    if(c >= '0' && c <= '9') return true;
    return false;
}
bool isLower(char c){
    if(c >= 'a' && c <= 'z') return true;
    return false;
}
bool isUpper(char c){
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}
char s[10005] = {0};
int letter[27] = {0};
int main(){
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    int n;scanf("%d",&n);scanf("%s",s);n = strlen(s);
    int st,ed;
    for(int i = 0; i < n;i ++){
        for(int j = i + 1;j < n;j ++){
            if(j == n - 1){
                st = i;
                ed = j;
                break;
            }
            if(isWho(s[i]) == isWho(s[j])){
                ;
            }else{
                st = i;
                ed = j - 1;
                break;
            }
        }//找到类型相同的一节
        if(ed == st) {
            continue;//如果只有一个，跳出
        }
        if(isNum(s[st])){
            for(int j = st;j <= ed;j ++){
                for(int k = j + 1;k <= ed;k ++){
                    if(s[k] < s[k - 1]){
                        char temp = s[k];
                        s[k] = s[k - 1];
                        s[k - 1] = temp;
                    }
                }
            }
        }else if(isWho(s[st])){
            memset(letter,0,sizeof(letter));
            for(int j = st;j <= ed;j ++){
                if(isLower(s[j])){
                    letter[s[j] - 'a' + 1] ++;
                    s[j] = 'A' + s[j] - 'a';
                }
            }//小写转大写方便排序
            for(int j = st;j <= ed;j ++){
                for(int k = st + 1;k <= ed - j;k ++){
                    if(s[k] < s[k - 1]){
                        char temp = s[k];
                        s[k] = s[k - 1];
                        s[k - 1] = temp;
                    }
                }
            }//排序,下面是还原操作
            for(int j = st;j <= ed;){
                int k = s[j] - 'A' + 1;
                if(letter[k]){
                    int cnt = letter[k];
                    for(int m = 1;m <= cnt;m ++){
                        s[j] = 'a' + k - 1 ;
                        j ++;
                    }
                    while (s[j] - 'A' + 1 == k)
                    {
                       j ++;
                    }
                    continue;
                }
                j ++;
            }
        }
        i = ed;
    }
    printf("%s\n",s);
    return 0;
}