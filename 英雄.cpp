#include<iostream>
using namespace std;

struct hero {
	string name;
	int age;
	string sex;
};

void sort(hero *arr, int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j].age > arr[j + 1].age) {
				hero temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {

	struct hero arr[5]{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};

	int len = sizeof(arr) / sizeof(hero);

	sort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i].name << " " << arr[i].age << " " << arr[i].sex << endl;
	}


	system("pause");

	return 0;
}