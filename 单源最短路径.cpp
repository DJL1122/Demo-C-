#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include <time.h>
using namespace std;
#define INF 0x3f3f3f3f  //��ʾ��
#define MAXN 51
//�����ʾ
int dingdian;		 //ͼ�������
int a[MAXN][MAXN];	//ͼ���ڽӾ���
int v;			//Դ��
int b;
//�������ʾ
int dist[MAXN];	//dist[i]Դ�㵽����i�����·������
int prev_one[MAXN]; //prev[i]��ʾԴ�㵽j�����·���ж���j��ǰ������

struct NodeType	//���н������
{
	int vno;		//������
	int length;		//·������
};

void bfs(int v)			//����㷨
{
	NodeType e, e1;
	queue<NodeType> pqu;
	e.vno = v;				//����Դ����e������㣩
	e.length = 0;
	pqu.push(e);			//Դ����e����
	dist[v] = 0;
	while (!pqu.empty())		//���в���ѭ��
	{
		e = pqu.front(); pqu.pop();	//�����н��e
		for (int j = 0; j < dingdian; j++)
		{
			if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])
			{	//��֦��e.vno������j�б߲���·�����ȸ���
				dist[j] = e.length + a[e.vno][j];
				prev_one[j] = e.vno;
				e1.vno = j;		//�������ڶ���j�Ľ��e1
				e1.length = dist[j];
				pqu.push(e1);		//���e1����
			}
		}
	}
}

void addEdge(int i, int j, int w)     //ͼ�����һ����
{
	cout << "�������бߵ���㡢�յ�ͱ߳����ÿո������:" << endl;
	for (int q = 0; q < b; q++)
	{
		cin >> i >> j >> w;
		if (i >= dingdian || j >= dingdian)
		{
			cout << "���ʧ�ܣ�����ı�" << endl;
			cout << "�㻹����������" << b - q << "����" << endl;
			q = q - 1;
		}
		a[i][j] = w;
	}
}

void dispapath(int v, int i)                  //�����V��I�����·��
{
	vector<int>path;
	if (v == i)return;
	if (dist[i] == INF)
		cout << "��Դ��" << v << "������" << i << "û��·��" << endl;
	else {
		int k = prev_one[i];
		path.push_back(i);           //���Ŀ�궥��
		while (k != v)              //����м䶥��
		{
			path.push_back(k);
			k = prev_one[k];
		}
		path.push_back(v);                    //���Դ��
		printf("��Դ��%d������%d�����·������:%d,·��:", v, i, dist[i]);
		for (int j = path.size() - 1; j >= 0; j--)      //���������������·��
			cout << path[j] << " ";
		printf("\n");
	}
}
void dispallpath(int v)            //�����Դ��v�������������·��
{
	for (int i = 0; i < dingdian; i++)
		dispapath(v, i);
}

int main()
{
	memset(dist, INF, sizeof(dist));        //��ʼ��Ϊ��
	memset(a, INF, sizeof(a));         //��ʼ��Ϊ��
	cout << "���붥������ͱ�����";
	cin >> dingdian >> b;                      //����ͼ�Ķ������
	cout << "��������Ϊ��";
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
	cout << "�������Դ�㣺";
	cin >> v;
	bfs(v);
	printf("�����\n");
	dispallpath(v);
	return 0;
}