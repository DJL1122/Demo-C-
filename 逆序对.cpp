#include<iostream>

using namespace std;

int main()
{
	int n,count, *a;
	cout << "输入数组元素个数：";
	cin >> n;
	count = 0;
	a = new int[n];
	cout << "依次输入数组元素："<<endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])  count++;
	
	cout <<"逆序对有"<< count <<"个" << endl;
	
}