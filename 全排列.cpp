#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int A[101];
void PrintA(int n)
{
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;
}
//PrintA时间复杂度：O(n)
void perm(int A[], int k, int n)
{
    if (k == 1)
        PrintA(n);
    else
    {
        for (int i = n - k + 1; i <= n; i++)//初始值k=n,i=1,交换A[1]和A[1],执行perm(A,n-1,n);
                                //i=2,交换A[2]和A[1],执行perm(A,n-1,n);
                                //i=3,交换A[3]和A[1],执行perm(A,n-1,n);
        {
            swap(A[i], A[n - k + 1]);
            perm(A, k - 1, n);
            swap(A[i], A[n - k + 1]);
        }
    }
}
//perm时间复杂度：O(n!)*O(n)
int main()//1 2 3
{
    int n;
    cin >> n;
    //赋初值
    for (int i = 1; i <= n; i++)
        A[i] = i;
    perm(A, n, n);
    return 0;
}

