#include <iostream>
#include <stdlib.h>
using namespace std;


struct Line {
    int start;
    int ending;
};
void bubble(Line l[], int n) {    //将线段按照起始点进行排序 起点小的在前面 如果起点相同则终点小的在前面
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (l[j].start > l[j + 1].start) {  //比较起点
                Line temp;
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }
            if (l[j].start == l[j + 1].start && l[j].ending > l[j + 1].ending) { //起点相同时把终点小的排在前面
                int temp1;
                temp1 = l[j].ending;
                l[j].ending = l[j + 1].ending;
                l[j + 1].ending = temp1;
            }
        }
    }
}
int lineCover(Line l[], int n, int Length) { //贪心算法求得线段覆盖长度
    int length = Length;
    if (n == 1) {  //n为1的时候 总覆盖长度为这一条线段的长度
        return length;
    }
    for (int i = 1; i < n; i++) {
        if (l[i].start >= l[i - 1].start && l[i].start <= l[i - 1].ending && l[i].ending > l[i - 1].ending) { //当前线段起点大于等于前一个线段的起点小于等于前一个线段的终点并且终点大于前一个线段的终点
            length += l[i].ending - l[i - 1].ending; //总覆盖长度增加两线段终点只差
        }
        else if (l[i].start >= l[i - 1].ending) { //当前线段的起点大于等于前一线段的终点
            length += l[i].ending - l[i].start;//总覆盖长度增加此线段的长度
        }
        else if (l[i].start >= l[i - 1].start && l[i].ending < l[i - 1].ending) { //当前线段在前一条线段的区间内
            l[i].ending = l[i - 1].ending; //将当前线段的终点改为前一线段的终点
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
    cout <<"覆盖长度：" << Length << endl;

    system("pause");
    return 0;
}