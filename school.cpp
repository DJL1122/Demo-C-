#include<iostream>
using namespace std;

struct student
{
	//��Ա�б�
	string name;  //����
	int score;    //����
};

struct teacher
{
	string name;
	struct student sarr[5];
};

void allocate(teacher *tarr, int len) {
	string name;
	int score;
	for (int i = 0; i < len; i++) {
		cout << "������ʦ������";
		cin >> name;
		tarr[i].name = name;
		for (int j = 0; j < 5; j++) {
			cout << "����ѧ������:";
			cin >> name;
			cout << "����ѧ���ɼ�:";
			cin >> score;
			tarr[i].sarr[j].name = name;
			tarr[i].sarr[j].score = score;
		}
	}
}

void printts(teacher* tarr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			cout <<i + 1<< tarr[i].sarr[j].name<<"--";
			cout <<tarr[i].sarr[j].score;
			cout << endl;
		}
		cout << endl;
	}
}

int main() {

	struct teacher tarr[3];
	int len = sizeof(tarr) / sizeof(teacher);
	allocate(tarr, len);
	printts(tarr, len);
	system("pause");

	return 0;
}