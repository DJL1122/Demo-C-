#include<iostream>
using namespace std;
int main()
{
	int sum = 0, a[7], max = 0, i = 0, j, first, last;
	cout << "������7������" << endl;
	for (int b = 0; b < 7; b++)
	{
		cin >> a[b];
	}

	for (i = 0; i < 7; i++)
	{
		for (j = i; j < 7; j++)
		{
			if (a[j + 1] > a[j])
			{
				sum += 1;
			}
			else
			{
				sum = 0;
			}
			if (sum > max)
			{
				max = sum;
				first = j + 1 - max;
				last = j + 1;
			}
		}
	}
	cout << "�������������г�Ϊ��" << max + 1 << endl;
	cout << "��ʼ��" << first << "��ֹ��" << last << endl;   //�������д�0��ʼ

}