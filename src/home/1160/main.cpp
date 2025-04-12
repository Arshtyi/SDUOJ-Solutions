#include <bits/stdc++.h>
using namespace std;
#define LOCAL freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
#define notie ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const double PI = acos(-1.0);
// 提高精度到1e-10，因为角度计算可能需要更高精度
const double EPS = 1e-10;

// 判断两个浮点数是否相等
inline bool equal(double a, double b)
{
    return fabs(a - b) < EPS;
}

// 计算两点之间的距离
inline double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// 计算三点的外接圆圆心 - 使用更稳定的算法
inline pair<double, double> circumcenter(double x1, double y1, double x2, double y2, double x3, double y3)
{
    // 使用行列式法确保数值稳定性
    double D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    if (fabs(D) < EPS)
    {
        return {-1e18, -1e18}; // 共线情况
    }

    double Ux = ((x1 * x1 + y1 * y1) * (y2 - y3) +
                 (x2 * x2 + y2 * y2) * (y3 - y1) +
                 (x3 * x3 + y3 * y3) * (y1 - y2)) /
                D;

    double Uy = ((x1 * x1 + y1 * y1) * (x3 - x2) +
                 (x2 * x2 + y2 * y2) * (x1 - x3) +
                 (x3 * x3 + y3 * y3) * (x2 - x1)) /
                D;

    return {Ux, Uy};
}

// 使用atan2计算三个点相对于圆心的角度，并检查是否符合正多边形的条件
int isOnRegularPolygon(double x1, double y1, double x2, double y2, double x3, double y3)
{
    // 计算外接圆圆心
    pair<double, double> center = circumcenter(x1, y1, x2, y2, x3, y3);
    if (center.first <= -1e17)
        return -1; // 共线情况

    double xc = center.first, yc = center.second;

    // 计算三点到圆心的距离
    double d1 = dist(x1, y1, xc, yc);
    double d2 = dist(x2, y2, xc, yc);
    double d3 = dist(x3, y3, xc, yc);

    // 如果三点到圆心的距离不相等，则不可能在同一个正多边形上
    if (!equal(d1, d2) || !equal(d2, d3) || !equal(d1, d3))
        return -1;

    // 计算三点相对于圆心的极角
    double angle1 = atan2(y1 - yc, x1 - xc);
    double angle2 = atan2(y2 - yc, x2 - xc);
    double angle3 = atan2(y3 - yc, x3 - xc);

    // 将角度标准化到[0, 2π)
    if (angle1 < 0)
        angle1 += 2 * PI;
    if (angle2 < 0)
        angle2 += 2 * PI;
    if (angle3 < 0)
        angle3 += 2 * PI;

    // 计算角度差并取最小的圆弧
    vector<double> angles;
    angles.push_back(min(fabs(angle1 - angle2), 2 * PI - fabs(angle1 - angle2)));
    angles.push_back(min(fabs(angle2 - angle3), 2 * PI - fabs(angle2 - angle3)));
    angles.push_back(min(fabs(angle3 - angle1), 2 * PI - fabs(angle3 - angle1)));

    // 转换为度数
    for (int i = 0; i < 3; i++)
    {
        angles[i] = angles[i] * 180.0 / PI;
    }

    // 检查正三角形 (120度)
    bool isTriangle = false;
    for (double angle : angles)
    {
        if (equal(angle, 120.0) || equal(angle, 240.0) || equal(angle, 360.0))
            isTriangle = true;
    }
    if (isTriangle)
        return 3;

    // 检查正方形 (90度)
    bool isSquare = false;
    for (double angle : angles)
    {
        if (equal(angle, 90.0) || equal(angle, 180.0) || equal(angle, 270.0) || equal(angle, 360.0))
            isSquare = true;
    }
    if (isSquare)
        return 4;

    // 检查正五边形 (72度)
    bool isPentagon = false;
    for (double angle : angles)
    {
        if (equal(angle, 72.0) || equal(angle, 144.0) || equal(angle, 216.0) ||
            equal(angle, 288.0) || equal(angle, 360.0))
            isPentagon = true;
    }
    if (isPentagon)
        return 5;

    return -1; // 不属于正三角形、正方形或正五边形
}

signed main()
{
    // LOCAL;
    notie;
    int T;
    cin >> T;

    while (T--)
    {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        cout << isOnRegularPolygon(x1, y1, x2, y2, x3, y3) << endl;
    }

    return 0;
}