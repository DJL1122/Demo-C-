#include<iostream>
#include<cstring>
#include<queue>
#define INF 1e7
#define N 10
using namespace std;
struct node
{
    int cl;//��ǰ�߹���·������
    int id;//����ĵڼ�������
    int x[N];//��¼��ǰ·��
    node() {}
    node(int c, int i)
    {
        cl = c;
        id = i;
        memset(x, 0, sizeof(x));
    }
};

int m[N][N];//�ڽӾ���洢�����Ȩͼ
int bestx[N];//���Ž�·��
int bestl;//���Žⳤ��
int n, M;//������Ŀ,·����Ŀ
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
    bool operator() (node n1, node n2)//��ǰ·�����ȶ̵����ȼ���
    {
        return n1.cl > n2.cl;//��С��
    }
};
void bfs()
{
    priority_queue<node, vector<node>, cmp> q;
    node temp(0, 2);//����Ѿ�ȷ�����ӵ�2�����㿪ʼ
    int t;
    for (int i = 1; i <= n; ++i)
        temp.x[i] = i;//��ʼ��������
    q.push(temp);
    node live;//����
    while (!q.empty())
    {
        live = q.top();
        q.pop();
        t = live.id;
        if (t == n)//���������ڶ�������
        {
            if (m[live.x[t - 1]][live.x[t]] != INF && m[live.x[t]][1] != INF)//����Լ����������·��
            {
                if (live.cl + m[live.x[t - 1]][live.x[t]] + m[live.x[t]][1] < bestl)//�������Ž�
                {
                    bestl = live.cl + m[live.x[t - 1]][live.x[t]] + m[live.x[t]][1];
                    for (int i = 1; i <= n; ++i)
                        bestx[i] = live.x[i];
                }
            }
            continue;
        }
        if (live.cl >= bestl)//�������޽�����
            continue;
        for (int j = t; j <= n; ++j) //������,j���ܶ���Ϊ���������ľֲ�������ѭ�������л���ֻ���
        {
            if (m[live.x[t - 1]][live.x[j]] != INF && live.cl + m[live.x[t - 1]][live.x[j]] < bestl)//����Լ���������޽�����
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
    cout << "���·������Ϊ��" << bestl << endl;
    cout << "���·��Ϊ��";
    for (int i = 1; i <= n; ++i)
        cout << bestx[i] << "-->";
    cout << bestx[1] << endl;
}
int main()
{
    init();
    cout << "�����������Ŀ��";
    cin >> n;
    cout << "������·����Ŀ��";
    cin >> M;
    cout << "��������м��·����";
    int i, a, b, c;
    for (i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        if (c < m[a][b])
        {
            m[a][b] = c;//ע���ɶԳ���
            m[b][a] = c;
        }
    }
    bfs();
    output();
    return 0;
}
