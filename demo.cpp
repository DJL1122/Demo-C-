#include <string>
#include <iostream>

#include <sstream>
#include <vector>
using namespace std;

int main()
{
    //int N;
    //int nArr[100];
    //cin >> N;   //�����C���ԣ��������scanf("%d",&N)
    //for (int i = 0; i < N; i++)
    //{
    //    cin >> nArr[i]; //ÿ�����ո����һ����int����,�����C���ԣ��������scanf("%d",nArr+i)
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