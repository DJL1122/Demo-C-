#include<iostream>
#include <iomanip>
#define n 3   //物品数列
#define c 40  //背包容量
using namespace std;
int w[3] = { 10,20,30 };
float v[3] = { 70,80,150 };
float sortBest[4];  //v[i]/w[i] 
void C() {
    for (int i = 0; i < 4; i++) {
        sortBest[i] = v[i] / w[i];
        //cout<<sortBest[i]<<" ";
    }
    cout << endl;
}
void Sort() {
    for (int i = 0; i < 4; i++)
    {
        int temp;
        int wtemp;
        int vtemp;
        if (sortBest[i + 1] > sortBest[i])
        {
            temp = sortBest[i];
            sortBest[i] = sortBest[i + 1];
            sortBest[i + 1] = temp;
            wtemp = w[i];
            w[i] = w[i + 1];
            w[i + 1] = wtemp;
            vtemp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = vtemp;
        }
        //用来查看排序是否正确
        cout << "w[" << i << "]=" << w[i] << " ";
        cout << endl;
        cout << "v[" << i << "]=" << v[i] << " ";
        //cout << endl;
        //cout << "sortBest[" << i << "]=" << sortBest[i] << endl;
    }
    cout << endl;
}
void F() {
    int c1 = c;
    int result = 0;
    for (int i = 0; i < 4; i++) {
        if (w[i] <= c1)
            result = result + v[i];
        c1 = c1 - w[i];
    }
    cout << "最优值是：" << result;
}
int main()
{
    C();
    cout << "背包重量是：" << c << endl;
    Sort();
    F();
    return 0;
}