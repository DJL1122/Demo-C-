#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, i, m = 0, s, max = 0, t, * a;
	cout << "��������Ԫ�ظ�����";
	cin >> n;
	a = new int[n];
	cout << "������������Ԫ�أ�" << endl;
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


	cout << " ����=  " << t << " ����=    " << max << endl;
	return 0;
}