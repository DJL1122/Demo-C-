#include<iostream>
using namespace std;
#define rand(a,b) (rand()%(b-a+1)+a)


int main() {

	srand((int)time(0));  // �����������  ��0����NULLҲ��
	int x = rand(1, 9);
	int i;
	cin >> i;
	while (i != x) {
		if (i < x) cout << "С��" << endl;
		if (i > x) cout << "����" << endl;
		cin >> i;
	}
	cout << "���ˣ���" << endl;


	system("pause");

	return 0;
}