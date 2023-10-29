#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include <time.h>
using namespace std;
#define INF 0x3f3f3f3f  //表示∞
#define MAXN 51
//问题表示
int dingdian;		 //图顶点个数
int a[MAXN][MAXN];	//图的邻接矩阵
int v;			//源点
int b;
//求解结果表示
int dist[MAXN];	//dist[i]源点到顶点i的最短路径长度
int prev_one[MAXN]; //prev[i]表示源点到j的最短路径中顶点j的前驱顶点

struct NodeType	//队列结点类型
{
	int vno;		//顶点编号
	int length;		//路径长度
};

void bfs(int v)			//求解算法
{
	NodeType e, e1;
	queue<NodeType> pqu;
	e.vno = v;				//建立源点结点e（根结点）
	e.length = 0;
	pqu.push(e);			//源点结点e进队
	dist[v] = 0;
	while (!pqu.empty())		//队列不空循环
	{
		e = pqu.front(); pqu.pop();	//出队列结点e
		for (int j = 0; j < dingdian; j++)
		{
			if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])
			{	//剪枝：e.vno到顶点j有边并且路径长度更短
				dist[j] = e.length + a[e.vno][j];
				prev_one[j] = e.vno;
				e1.vno = j;		//建立相邻顶点j的结点e1
				e1.length = dist[j];
				pqu.push(e1);		//结点e1进队
			}
		}
	}
}

void addEdge(int i, int j, int w)     //图中添加一条边
{
	cout << "输入所有边的起点、终点和边长（用空格隔开）:" << endl;
	for (int q = 0; q < b; q++)
	{
		cin >> i >> j >> w;
		if (i >= dingdian || j >= dingdian)
		{
			cout << "添加失败，错误的边" << endl;
			cout << "你还可以再输入" << b - q << "条边" << endl;
			q = q - 1;
		}
		a[i][j] = w;
	}
}

void dispapath(int v, int i)                  //输出从V到I的最短路径
{
	vector<int>path;
	if (v == i)return;
	if (dist[i] == INF)
		cout << "从源点" << v << "到顶点" << i << "没有路径" << endl;
	else {
		int k = prev_one[i];
		path.push_back(i);           //添加目标顶点
		while (k != v)              //添加中间顶点
		{
			path.push_back(k);
			k = prev_one[k];
		}
		path.push_back(v);                    //添加源点
		printf("从源点%d到顶点%d的最短路径长度:%d,路径:", v, i, dist[i]);
		for (int j = path.size() - 1; j >= 0; j--)      //反向输出构成正向路径
			cout << path[j] << " ";
		printf("\n");
	}
}
void dispallpath(int v)            //输出从源点v出发的所有最短路径
{
	for (int i = 0; i < dingdian; i++)
		dispapath(v, i);
}

int main()
{
	memset(dist, INF, sizeof(dist));        //初始化为∞
	memset(a, INF, sizeof(a));         //初始化为∞
	cout << "输入顶点个数和边数：";
	cin >> dingdian >> b;                      //有向图的顶点个数
	cout << "顶点名称为：";
	for (int i = 0; i < dingdian; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < dingdian; i++)
		a[i][i] = 0;
	int m = 0;
	int n = 0;
	int w = 0;
	addEdge(m, n, w);
	cout << "输入出发源点：";
	cin >> v;
	bfs(v);
	printf("求解结果\n");
	dispallpath(v);
	return 0;
}