#include <iostream>
using namespace std;

#define N 10
int w[N];//����
int v[N];//��ֵ
int x[N];//1����뱳����0������
int n, c;//n����Ʒ���� c���������������

int cw = 0;//��ǰ��Ʒ����
int cv = 0;//��ǰ��Ʒ�ܼ�ֵ

int bestp = 0;//��ǰ����ֵ
int bestx[N];//���Ž�

//���ݺ��� k��ʾ��ǰ���ڵڼ�����ѡ��k=1ʱ��ʾ�����Ƿ񽫵�һ����Ʒ���뱳��
void backtrack(int k)
{//Ҷ�ӽڵ㣬������
    if (k > n) {//�ҵ�һ�����ŵĽ�
        if (cv > bestp) {//������ŵ�ֵ�ͽ�
            bestp = cv;
            for (int i = 1; i <= n; i++)
                bestx[i] = x[i];
        }
    }
    else {//������ǰ�ڵ���ӽڵ�
        for (int i = 0; i <= 1; i++) {
            x[k] = i;
            if (i == 0) {
                backtrack(k + 1);
            }
            else {//Լ����������ǰ��Ʒ�Ƿ�ŵ���
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

    cout << "��������Ʒ�ĸ�����";
    cin >> n;
    cout << "������ÿ����Ʒ����������ֵ:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << "�����뱳��������������";
    cin >> c;
    backtrack(1);
    cout << "����ֵ��:" << bestp << endl;
    cout << "(";
    for (int i = 1; i <= n; i++)
        cout << bestx[i] << " ";
    cout << ")";
    return 0;
}