#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 1005;   // 最大存储器数量
const int MAXM = 1005;   // 每个存储器最大位数
const int MAXQ = 100005; // 最大操作次数

// 操作类型
enum OpType
{
    INIT = 0,     // 初始状态
    SET_ONE = 1,  // 置1
    SET_ZERO = 2, // 置0
    FLIP = 3,     // 翻转
    SWAP = 4,     // 交换
    REVERT = 5    // 回到之前状态
};

// 操作结构体
struct Operation
{
    OpType type;
    int a, b;
    int parent; // 该操作的父操作索引
};

// 存储器结构体
struct Memory
{
    bitset<MAXM> bits; // 使用bitset来高效存储位信息
    bool flipped;      // 翻转标志
    int oneCount;      // 1的数量

    Memory() : bits(), flipped(false), oneCount(0) {}
};

vector<Operation> operations; // 操作历史
vector<int> oneCountResults;  // 每次操作后的1的总数

// 执行单个操作
void executeOperation(vector<Memory> &memories, const Operation &op, int n, int m)
{
    if (op.type == SET_ONE)
    { // 操作1：将第a块存储器的第b位置1
        int a = op.a, b = op.b;
        if (a < 1 || a > n || b < 1 || b > m)
            return;

        Memory &mem = memories[a];
        bool currentVal = mem.bits[b] ^ mem.flipped; // 计算实际值

        if (!currentVal)
        {                                  // 如果当前位是0
            mem.bits.set(b, !mem.flipped); // 设置为与flipped相反的值
            mem.oneCount++;                // 1的数量+1
        }
    }
    else if (op.type == SET_ZERO)
    { // 操作2：将第a块存储器的第b位置0
        int a = op.a, b = op.b;
        if (a < 1 || a > n || b < 1 || b > m)
            return;

        Memory &mem = memories[a];
        bool currentVal = mem.bits[b] ^ mem.flipped; // 计算实际值

        if (currentVal)
        {                                 // 如果当前位是1
            mem.bits.set(b, mem.flipped); // 设置为与flipped相同的值
            mem.oneCount--;               // 1的数量-1
        }
    }
    else if (op.type == FLIP)
    { // 操作3：翻转第a块存储器
        int a = op.a;
        if (a < 1 || a > n)
            return;

        Memory &mem = memories[a];
        mem.flipped = !mem.flipped;      // 翻转标志取反
        mem.oneCount = m - mem.oneCount; // 1的数量变为m减去原来1的数量
    }
    else if (op.type == SWAP)
    { // 操作4：交换第a,b块存储器
        int a = op.a, b = op.b;
        if (a < 1 || a > n || b < 1 || b > n)
            return;

        swap(memories[a], memories[b]); // 直接交换两个存储器
    }
}

// 计算所有存储器中1的总数
int countTotalOnes(const vector<Memory> &memories, int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += memories[i].oneCount;
    }
    return total;
}

// 从操作历史中恢复到特定操作后的状态
void recoverState(vector<Memory> &memories, int opIndex, int n, int m)
{
    // 初始化所有存储器
    for (int i = 1; i <= n; i++)
    {
        memories[i].bits.reset(); // 所有位设为0
        memories[i].flipped = false;
        memories[i].oneCount = 0;
    }

    // 从初始状态开始，一步步重放操作
    int currOpIndex = opIndex;
    vector<int> opPath; // 存储操作路径

    // 从当前操作回溯到根操作
    while (currOpIndex > 0)
    {
        opPath.push_back(currOpIndex);
        currOpIndex = operations[currOpIndex].parent;
    }

    // 从根操作开始重放
    for (int i = opPath.size() - 1; i >= 0; i--)
    {
        executeOperation(memories, operations[opPath[i]], n, m);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("data.in", "r", stdin), freopen("data.out", "w", stdout); // 重定向输入输出
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int n, m, q;
        cin >> n >> m >> q;

        // 初始化
        operations.clear();
        operations.push_back({INIT, 0, 0, -1}); // 添加一个初始状态，索引为0
        oneCountResults.clear();

        vector<Memory> currentMemories(n + 1); // 当前存储器状态
        int currentParent = 0;                 // 当前操作的父操作索引

        for (int i = 1; i <= q; i++)
        {
            int type, a = 0, b = 0;
            cin >> type;

            if (type == 1 || type == 2 || type == 4)
            {
                cin >> a >> b;
            }
            else
            {
                cin >> a;
            }

            Operation op;
            op.type = static_cast<OpType>(type);
            op.a = a;
            op.b = b;

            if (type == 5)
            { // 如果是操作5（回到之前状态）
                if (a >= 0 && a < i)
                { // 检查a是否有效
                    // 恢复到操作a之后的状态
                    recoverState(currentMemories, a, n, m);
                    op.parent = a; // 父操作设为a
                }
                else
                {
                    op.parent = currentParent; // 无效操作，父操作不变
                }
            }
            else
            {                                                // 操作1-4
                op.parent = currentParent;                   // 父操作为当前父操作
                executeOperation(currentMemories, op, n, m); // 执行操作
            }

            operations.push_back(op); // 添加到操作历史
            currentParent = i;        // 更新当前父操作索引

            // 记录当前操作后1的总数
            oneCountResults.push_back(countTotalOnes(currentMemories, n));
        }

        // 输出结果
        for (int result : oneCountResults)
        {
            cout << result << endl;
        }
    }

    return 0;
}