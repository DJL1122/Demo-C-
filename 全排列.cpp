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
//PrintAʱ�临�Ӷȣ�O(n)
void perm(int A[], int k, int n)
{
    if (k == 1)
        PrintA(n);
    else
    {
        for (int i = n - k + 1; i <= n; i++)//��ʼֵk=n,i=1,����A[1]��A[1],ִ��perm(A,n-1,n);
                                //i=2,����A[2]��A[1],ִ��perm(A,n-1,n);
                                //i=3,����A[3]��A[1],ִ��perm(A,n-1,n);
        {
            swap(A[i], A[n - k + 1]);
            perm(A, k - 1, n);
            swap(A[i], A[n - k + 1]);
        }
    }
}
//permʱ�临�Ӷȣ�O(n!)*O(n)
int main()//1 2 3
{
    int n;
    cin >> n;
    //����ֵ
    for (int i = 1; i <= n; i++)
        A[i] = i;
    perm(A, n, n);
    return 0;
}

