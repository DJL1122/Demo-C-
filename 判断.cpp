#include <iostream>
using namespace std;
int main()
{
	int A;
	int B;
	int C;
	int t;
	char temp;
	cout << "A�����أ�" << endl;
	cin >> A;
	cout << "B�����أ�" << endl;
	cin >> B;
	cout << "C�����أ�" << endl;
	cin >> C;

	if (A > B) {
		t = A;
		temp = 'A';
	}
	else {
		t = B;
		temp = 'B';
	}

	if (t > C) cout << temp << "����������" << endl;
	else {
		temp = 'C';
		cout << temp << "����������" << endl;
	}
		


	system("pause");
	return 0;
}