#include <iostream>
using namespace std;

#define N 10
int w[N];//重量
int v[N];//价值
int x[N];//1表放入背包，0表不放入
int n, c;//n：物品个数 c：背包的最大容量

int cw = 0;//当前物品总重
int cv = 0;//当前物品总价值

int bestp = 0;//当前最大价值
int bestx[N];//最优解

//回溯函数 k表示当前处在第几层做选择，k=1时表示决定是否将第一个物品放入背包
void backtrack(int k)
{//叶子节点，输出结果
    if (k > n) {//找到一个更优的解
        if (cv > bestp) {//保存更优的值和解
            bestp = cv;
            for (int i = 1; i <= n; i++)
                bestx[i] = x[i];
        }
    }
    else {//遍历当前节点的子节点
        for (int i = 0; i <= 1; i++) {
            x[k] = i;
            if (i == 0) {
                backtrack(k + 1);
            }
            else {//约束条件：当前物品是否放的下
                if ((cw + w[k]) <= c) {
                    cw += w[k];
                    cv += v[k];
                    backtrack(k + 1);
                    cw -= w[k];
                    cv -= v[k];
                }
            }
        }
    }
}

int main()
{

    cout << "请输入物品的个数：";
    cin >> n;
    cout << "请输入每个物品的重量及价值:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << "请输入背包的限制容量：";
    cin >> c;
    backtrack(1);
    cout << "最优值是:" << bestp << endl;
    cout << "(";
    for (int i = 1; i <= n; i++)
        cout << bestx[i] << " ";
    cout << ")";
    return 0;
}