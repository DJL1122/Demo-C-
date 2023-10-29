#include <string>
#include <iostream>

#include <sstream>
#include <vector>
using namespace std;

int main()
{
    //int N;
    //int nArr[100];
    //cin >> N;   //如果是C语言，这里就是scanf("%d",&N)
    //for (int i = 0; i < N; i++)
    //{
    //    cin >> nArr[i]; //每遇到空格读入一个流int数据,如果是C语言，这里就是scanf("%d",nArr+i)
    //}
    //for (int i = 0; i < N; i++)
    //{
    //    cout << nArr[i];
    //}
    string s = "This,is,a,test";
    stringstream sa(s);
    vector<string> v;
    string temp;
    int word;
    while (getline(sa, temp, ','))
    {
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }



}