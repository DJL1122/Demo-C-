#include <iostream>
using namespace std;


void solve(int n,int &counts)
{
    
    int i;
    if (n == 1)//当商为1时即为已经算出一次分解累计+1
        counts++;
    for (i = 2; i <= n; i++)//每个数进行遍历
    {
        if (n % i == 0)//mod为0 即为可分解的数
            solve(n / i,counts);//进行分解
    }
}
int main()
{
    int n;
    cout << "给定一个正整数：";
    cin>> n;
    
    int count = 0;
    solve(n,count);
    cout << "共有" << count << "种不同的分解式"<<endl;
   
    return 0;
}
