#include<iostream>
using namespace std;

int maxSum(int a[], int n) {

	int sum = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {

		if (b > 0)
			b += a[i];
		else
			b = a[i];

		if (b > sum)
			sum = b;
	}
	return sum;
}

int main() {

	int a[] = { 2,-11,4,-13,-5,2,6 };

	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "(��̬�滮)����a����������Ӷκ�Ϊ��" << maxSum(a, 7) << endl;
	return 0;
}
