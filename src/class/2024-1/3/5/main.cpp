#include <stdio.h>
int main() {
    int n ,k=0;float a,b,c,C;float sum_w = 0, sum_v = 0;scanf("%d %f", &n, &C);
    struct good {int No;float weight;float value;float pw;}object[n];
    for (int i = 0; i <= n - 1; i++) {
        scanf("%f %f", &object[i].weight, &object[i].value);
    }
    for (int i = 0; i <= n - 1; i++) object[i].pw = (float)((object[i].value) / (object[i].weight));
    for (int j = 0; j <= n - 1; j++) {
        for (int i = 0; i <= n - k - 2; i++) {
            if (object[i].pw > object[i + 1].pw) {
                a = object[i].weight;object[i].weight = object[i + 1].weight;object[i + 1].weight = a;
                b = object[i].value;object[i].value = object[i + 1].value;object[i + 1].value = b;
                c = object[i].pw;object[i].pw = object[i + 1].pw;object[i + 1].pw = c;
            }
        }
        k++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (C > sum_w && object[i].weight <= C - sum_w) {
            sum_w = sum_w + object[i].weight;
            sum_v = sum_v + object[i].value;
        }else break;
    }
    printf("%d\n%d", (int)sum_w, (int)sum_v);
    return 0;
}