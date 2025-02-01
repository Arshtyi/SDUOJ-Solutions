#include <iostream>
using namespace std;
void input(int &x, int &y);
void output(int x, int y);
int main() {
    int n, x, y;
    cin >> n;
    while(n--) {
        input(x, y);
        output(x, y);
    }
}
// 你的 solution 会被放置在这
void input(int &x, int &y) {
    // TODO: 请填写代码
    cin >> x >> y;
}
void output(int x, int y) {
    // TODO: 请填写代码
    cout << x + y << endl;
}