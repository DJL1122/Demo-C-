
#include <vector>
#include <algorithm>

#include <iostream>
#include <string>

using namespace std;


int main() {

	int n, temp,num,f,t;
	float k;
	cin >> n >> k;

	int* a = new int[n];


	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		a[i] = temp;
	}

	cout << a[0];


	for (int b = n-1; b >= 1; --b) {
		
		for (int i = 0; i < n-b + 1; ++i)
		{
			num = 0;
			t = i;
			f = 0;
			while (f < b) {
				num = num + a[t];
				t++;
				f++;
			}
			if (k == float(num) / b) {
				cout << b;
				return 0;
			}


		}


	}

	cout << -1;

	delete[] a;


	return 0;
}