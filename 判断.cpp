#include <iostream>
using namespace std;
int main()
{
	int A;
	int B;
	int C;
	int t;
	char temp;
	cout << "A的体重：" << endl;
	cin >> A;
	cout << "B的体重：" << endl;
	cin >> B;
	cout << "C的体重：" << endl;
	cin >> C;

	if (A > B) {
		t = A;
		temp = 'A';
	}
	else {
		t = B;
		temp = 'B';
	}

	if (t > C) cout << temp << "的体重最重" << endl;
	else {
		temp = 'C';
		cout << temp << "的体重最重" << endl;
	}
		


	system("pause");
	return 0;
}