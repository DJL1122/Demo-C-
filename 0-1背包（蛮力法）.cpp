#include<stdio.h>
#define n 3
void possible_solution(int x[n]) {
	int i;
	for (i = 0; i < 3; i++)
		if (x[i] != 1) { x[i] = 1; return; }
		else   x[i] = 0;
	return;
}
int main() {
	int w[n] = { 10,20,30 }, v[n] = { 70,80,150 };
	int x[n] = { 0,0,0 }, y[n] = { 0,0,0 };
	int tw, tv, tv1 = 0, limit = 40;
	int j;
	for (j = 1; j <= 8; j++) {
		possible_solution(x);
		tw = x[0] * w[0] + x[1] * w[1] + x[2] * w[2];
		tv = x[0] * v[0] + x[1] * v[1] + x[2] * v[2];
		if (tw <= limit && tv > tv1) {
			tv1 = tv; y[0] = x[0]; y[1] = x[1]; y[2] = x[2];
		}
	}
	printf("0-1背包问题的最优解 y=(%d,%d,%d)\n", y[0], y[1], y[2]);
	printf("总价值为：%d", tv1);
}