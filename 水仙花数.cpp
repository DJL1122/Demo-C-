#include<iostream>
using namespace std;

int main() {
	 
	int i = 100;
	do {
		int sum = 0;
		int x = i;
		while (x > 0) {
			int j = x % 10;
			sum += j * j * j;
			x = x / 10;
		}
		if (sum == i) cout << i << "��ˮ�ɻ���" << endl;
		i++;
	} while (i < 1000);



	system("pause");
	return 0;
}