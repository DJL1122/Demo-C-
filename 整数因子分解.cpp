#include <iostream>
using namespace std;


void solve(int n,int &counts)
{
    
    int i;
    if (n == 1)//����Ϊ1ʱ��Ϊ�Ѿ����һ�ηֽ��ۼ�+1
        counts++;
    for (i = 2; i <= n; i++)//ÿ�������б���
    {
        if (n % i == 0)//modΪ0 ��Ϊ�ɷֽ����
            solve(n / i,counts);//���зֽ�
    }
}
int main()
{
    int n;
    cout << "����һ����������";
    cin>> n;
    
    int count = 0;
    solve(n,count);
    cout << "����" << count << "�ֲ�ͬ�ķֽ�ʽ"<<endl;
   
    return 0;
}
