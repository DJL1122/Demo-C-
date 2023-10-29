#include<iostream>
using namespace std;
#define rand(a,b) (rand()%(b-a+1)+a)


int main() {

	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	int x = rand(1, 9);
	int i;
	cin >> i;
	while (i != x) {
		if (i < x) cout << "小了" << endl;
		if (i > x) cout << "大了" << endl;
		cin >> i;
	}
	cout << "对了！！" << endl;


	system("pause");

	return 0;
}