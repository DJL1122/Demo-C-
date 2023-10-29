#include<iostream>

using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int flag[100] = { 0 };
        int k = 2;
        int i = 0;
        while (num >= k) {
            //从2开始分解，依次分解为2，3，4，5...连续的元素
            flag[i++] = k;
            num -= k;
            k++;
        }
        if (num > 0) {
            //说明有剩余的
            if (num == flag[i - 1]) {
                //说明这时候剩余的数正好比已有的元素个数多1，所以要先给最后一个元素加1
                flag[i - 1]++;
                num--;
            }
            for (int j = i - 1; j >= 0 && num > 0; j--) {
                flag[j] ++;
                num--;
            }

        }
        int result = 1;
        cout << "分解结果：";
        for (int j = 0; j < i; j++) {
            cout << flag[j] << " ";
            result *= flag[j];
        }
        cout << endl;
        cout<<"最大乘积：" << result << endl;
    }//while
    return 0;
}