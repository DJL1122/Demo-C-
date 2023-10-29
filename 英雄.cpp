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
		{"Áõ±¸",23,"ÄĞ"},
		{"¹ØÓğ",22,"ÄĞ"},
		{"ÕÅ·É",20,"ÄĞ"},
		{"ÕÔÔÆ",21,"ÄĞ"},
		{"õõ²õ",19,"Å®"},
	};

	int len = sizeof(arr) / sizeof(hero);

	sort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i].name << " " << arr[i].age << " " << arr[i].sex << endl;
	}


	system("pause");

	return 0;
}