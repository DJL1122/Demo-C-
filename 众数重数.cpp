#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, i, m = 0, s, max = 0, t, * a;
	cout << "输入数组元素个数：";
	cin >> n;
	a = new int[n];
	cout << "依次输入数组元素：" << endl;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	
	for (i = 0; i < n; i++)
	{
		if (m != a[i])
			s = 1;
		else
			s++;
		m = a[i];
		if (s > max)
		{
			t = m;
			max = s;
		}
	}


	cout << " 众数=  " << t << " 重数=    " << max << endl;
	return 0;
}