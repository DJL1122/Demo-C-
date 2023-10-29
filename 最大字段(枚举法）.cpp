#include<iostream> 
using namespace std;


int maxSum(int n, int a[], int& besti, int& bestj) {

	int sum = 0;
	for (int i = 0; i < n; i++) {

		int thisSum = 0;
		for (int j = i; j < n; j++) {

			thisSum += a[j];
			if (thisSum > sum) {

				sum = thisSum;
				besti = i;
				bestj = j;
			}
		}

	}
	return sum;
}

int main() {

	int a[] = { -2,11,-4,13,-5,-2, };

	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}

	int besti, bestj;

	cout << endl;
	cout << "（枚举法）数组a的最大连续子段和为：" << besti << "—" << bestj << ":  " << maxSum(6, a, besti, bestj) << endl;

	return 0;
}
