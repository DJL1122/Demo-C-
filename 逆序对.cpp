#include<iostream>

using namespace std;

int main()
{
	int n,count, *a;
	cout << "��������Ԫ�ظ�����";
	cin >> n;
	count = 0;
	a = new int[n];
	cout << "������������Ԫ�أ�"<<endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])  count++;
	
	cout <<"�������"<< count <<"��" << endl;
	
}