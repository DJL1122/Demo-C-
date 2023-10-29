#include <iostream>
#include <stdlib.h>
using namespace std;


struct Line {
    int start;
    int ending;
};
void bubble(Line l[], int n) {    //���߶ΰ�����ʼ��������� ���С����ǰ�� ��������ͬ���յ�С����ǰ��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (l[j].start > l[j + 1].start) {  //�Ƚ����
                Line temp;
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
            if (l[j].start == l[j + 1].start && l[j].ending > l[j + 1].ending) { //�����ͬʱ���յ�С������ǰ��
                int temp1;
                temp1 = l[j].ending;
                l[j].ending = l[j + 1].ending;
                l[j + 1].ending = temp1;
            }
        }
    }
}
int lineCover(Line l[], int n, int Length) { //̰���㷨����߶θ��ǳ���
    int length = Length;
    if (n == 1) {  //nΪ1��ʱ�� �ܸ��ǳ���Ϊ��һ���߶εĳ���
        return length;
    }
    for (int i = 1; i < n; i++) {
        if (l[i].start >= l[i - 1].start && l[i].start <= l[i - 1].ending && l[i].ending > l[i - 1].ending) { //��ǰ�߶������ڵ���ǰһ���߶ε����С�ڵ���ǰһ���߶ε��յ㲢���յ����ǰһ���߶ε��յ�
            length += l[i].ending - l[i - 1].ending; //�ܸ��ǳ����������߶��յ�ֻ��
        }
        else if (l[i].start >= l[i - 1].ending) { //��ǰ�߶ε������ڵ���ǰһ�߶ε��յ�
            length += l[i].ending - l[i].start;//�ܸ��ǳ������Ӵ��߶εĳ���
        }
        else if (l[i].start >= l[i - 1].start && l[i].ending < l[i - 1].ending) { //��ǰ�߶���ǰһ���߶ε�������
            l[i].ending = l[i - 1].ending; //����ǰ�߶ε��յ��Ϊǰһ�߶ε��յ�
        }
    }
    return length;
}

int main()
{
    int n;
    cin >> n;
    Line l[100];
    for (int i = 0; i < n; i++) {
        cin >> l[i].start >> l[i].ending;
    }
    bubble(l, n);
    int la = l[0].ending - l[0].start;
    int Length = lineCover(l, n, la);
    cout <<"���ǳ��ȣ�" << Length << endl;

    system("pause");
    return 0;
}