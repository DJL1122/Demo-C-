#include<iostream>

using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int flag[100] = { 0 };
        int k = 2;
        int i = 0;
        while (num >= k) {
            //��2��ʼ�ֽ⣬���ηֽ�Ϊ2��3��4��5...������Ԫ��
            flag[i++] = k;
            num -= k;
            k++;
        }
        if (num > 0) {
            //˵����ʣ���
            if (num == flag[i - 1]) {
                //˵����ʱ��ʣ��������ñ����е�Ԫ�ظ�����1������Ҫ�ȸ����һ��Ԫ�ؼ�1
                flag[i - 1]++;
                num--;
            }
            for (int j = i - 1; j >= 0 && num > 0; j--) {
                flag[j] ++;
                num--;
            }

        }
        int result = 1;
        cout << "�ֽ�����";
        for (int j = 0; j < i; j++) {
            cout << flag[j] << " ";
            result *= flag[j];
        }
        cout << endl;
        cout<<"���˻���" << result << endl;
    }//while
    return 0;
}