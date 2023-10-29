#include<iostream>
#include<cstring>
#include<queue>
#define INF 1e7
#define N 10
using namespace std;
struct node
{
    int cl;//当前走过的路径长度
    int id;//处理的第几个景点
    int x[N];//记录当前路径
    node() {}
    node(int c, int i)
    {
        cl = c;
        id = i;
        memset(x, 0, sizeof(x));
    }
};

int m[N][N];//邻接矩阵存储无向带权图
int bestx[N];//最优解路径
int bestl;//最优解长度
int n, M;//景点数目,路径数目
void init()
{
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            m[i][j] = INF;
    memset(bestx, 0, sizeof(bestx));
    bestl = INF;
}
struct cmp
{
    bool operator() (node n1, node n2)//当前路径长度短的优先级高
    {
        return n1.cl > n2.cl;//最小堆
    }
};
void bfs()
{
    priority_queue<node, vector<node>, cmp> q;
    node temp(0, 2);//起点已经确定，从第2个景点开始
    int t;
    for (int i = 1; i <= n; ++i)
        temp.x[i] = i;//初始化解向量
    q.push(temp);
    node live;//活结点
    while (!q.empty())
    {
        live = q.top();
        q.pop();
        t = live.id;
        if (t == n)//处理到倒数第二个景点
        {
            if (m[live.x[t - 1]][live.x[t]] != INF && m[live.x[t]][1] != INF)//满足约束条件，有路径
            {
                if (live.cl + m[live.x[t - 1]][live.x[t]] + m[live.x[t]][1] < bestl)//更新最优解
                {
                    bestl = live.cl + m[live.x[t - 1]][live.x[t]] + m[live.x[t]][1];
                    for (int i = 1; i <= n; ++i)
                        bestx[i] = live.x[i];
                }
            }
            continue;
        }
        if (live.cl >= bestl)//不满足限界条件
            continue;
        for (int j = t; j <= n; ++j) //排列树,j不能定义为整个函数的局部变量，循环过程中会出现混乱
        {
            if (m[live.x[t - 1]][live.x[j]] != INF && live.cl + m[live.x[t - 1]][live.x[j]] < bestl)//满足约束条件和限界条件
            {
                temp = node(live.cl + m[live.x[t - 1]][live.x[j]], t + 1);
                for (int k = 1; k <= n; ++k)
                    temp.x[k] = live.x[k];
                swap(temp.x[t], temp.x[j]);
                q.push(temp);
            }
        }
    }
}
void output()
{
    cout << "最短路径长度为：" << bestl << endl;
    cout << "最短路径为：";
    for (int i = 1; i <= n; ++i)
        cout << bestx[i] << "-->";
    cout << bestx[1] << endl;
}
int main()
{
    init();
    cout << "请输入城市数目：";
    cin >> n;
    cout << "请输入路径数目：";
    cin >> M;
    cout << "请输入城市间的路径：";
    int i, a, b, c;
    for (i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        if (c < m[a][b])
        {
            m[a][b] = c;//注意存成对称阵
            m[b][a] = c;
        }
    }
    bfs();
    output();
    return 0;
}
