#include <iostream>
using namespace std;
const int max_ = 0x3f3f3f;   //����һ�����ֵ
const int NoEdge = -1;      //������֮��û�б�
int citynum;                //������
int edgenum;                //����
int currentcost;            //��¼��ǰ��·��
int bestcost;               //��¼��С��·��(����)
int Graph[100][100];        //ͼ�ı߾��¼
int x[100];                 //��¼����˳��
int bestx[100];             //��¼��������˳��

void InPut()
{
    int pos1, pos2, len;     //��1 ��2 ����

    cout << "������������ͱ���(c e)��";
    cin >> citynum >> edgenum;

    memset(Graph, NoEdge, sizeof(Graph));

    cout << "��������������֮��ľ���(p1 p2 l)��" << endl;
    for (int i = 1; i <= edgenum; ++i)
    {
        cin >> pos1 >> pos2 >> len;
        Graph[pos1][pos2] = Graph[pos2][pos1] = len;
    }
}

//��ʼ��
void Initilize()
{
    currentcost = 0;
    bestcost = max_;
    for (int i = 1; i <= citynum; ++i)
    {
        x[i] = i;
    }
}


void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void BackTrack(int i) //�����i�����i��ȥ�ĳ��ж����Ǵ���Ϊi�ĳ���
{
    if (i == citynum)
    {
        //����һϵ���жϣ�ע����ǽ���˲���Ĳ���Ӧ��Ҷ�ӽڵ�ĸ��ڵ㣬������Ҷ�ӽڵ�
        if (Graph[x[i - 1]][x[i]] != NoEdge && Graph[x[i]][x[1]] != NoEdge && (currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]] < bestcost || bestcost == max_))
        {
            //��С(��)����=��ǰ�ľ���+��ǰ���е�Ҷ�ӳ��еľ���+Ҷ�ӳ��е���ʼ���еľ���
            bestcost = currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]];
            for (int j = 1; j <= citynum; ++j)
                bestx[j] = x[j];
        }
    }
    else
    {
        for (int j = i; j <= citynum; ++j)
        {
            if (Graph[x[i - 1]][x[j]] != NoEdge && (currentcost + Graph[x[i - 1]][x[j]] < bestcost || bestcost == max_))
            {
                Swap(x[i], x[j]);  //����i �� j��λ�ý�����, �����������currentcost += Graph[x[i - 1]][x[i]];
                currentcost += Graph[x[i - 1]][x[i]];
                BackTrack(i + 1);   //�ݹ������һ������
                currentcost -= Graph[x[i - 1]][x[i]];
                Swap(x[i], x[j]);
            }
        }
    }
}

void OutPut()
{
    cout << "���·��Ϊ��" << bestcost << endl;
    cout << "·��Ϊ:" << endl;
    for (int i = 1; i <= citynum; ++i)
        cout << bestx[i] << " ";
    cout << "1" << endl;
}


int main()
{
    InPut();
    Initilize();
    BackTrack(2);
    OutPut();
}

