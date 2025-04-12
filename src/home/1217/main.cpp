#include <bits/stdc++.h>
using namespace std;
struct Window
{
    int x1, y1, x2, y2; // 窗口的位置坐标
    int num;            // 窗口编号
    Window(int x1, int y1, int x2, int y2, int num) : x1(x1), y1(y1), x2(x2), y2(y2), num(num) {};
};
// 处理点击了(x,y)之后窗口次序的变化
void Click(int x, int y, vector<Window> &wins)
{
    for (int i = wins.size() - 1; i >= 0; i--)
    {                                           // 从最外层的窗口开始遍历，判断(x,y)是否在自己的窗口范围内
        if (x >= wins[i].x1 && x <= wins[i].x2) // x在x1和x2之间
            if (y >= wins[i].y1 && y <= wins[i].y2)
            {                                // y在y1和y2之间
                cout << wins[i].num << endl; // 输出窗口的编号
                wins.push_back(wins[i]);     // 将被点击的窗口复制一份放在最外层
                auto it = wins.begin() + i;
                wins.erase(it); // 将被点击的窗口从原来的位置删除
                return;
            }
    }
    cout << "IGNORED" << endl;
}
int main()
{
    int N, M;
    int x1, y1, x2, y2, x, y;
    vector<Window> wins; // 存放输入的所有窗口
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        Window win(x1, y1, x2, y2, i);
        wins.push_back(win);
    }
    while (M--)
    {
        cin >> x >> y; // 点击的位置
        Click(x, y, wins);
    }
}