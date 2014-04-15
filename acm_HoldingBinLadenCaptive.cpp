#include <iostream>
using namespace std;
#define N    100001
unsigned int c1[N + 1], c2[N + 1];
int ele[3] = { 1, 2, 5 };
int num[3];
int tmp1, tmp2;
void init() {
	int i, j, k;
	for (i = 0; i < N; i++) {
		c1[i] = 0;
		c2[i] = 0;
	}
	for (i = 0; i <= num[0]; i++) {
		c1[i] = 1;
	}
	tmp1 = num[0] * ele[0] + num[1] * ele[1] + num[2] * ele[2];
	for (i = 2; i <= 3; i++) {
		for (j = 0; j <= tmp1; j++) {
			tmp2 = num[i - 1] * ele[i - 1];
			for (k = 0; k <= tmp2; k += ele[i - 1]) {
				c2[j + k] += c1[j];
			}
		}
		for (j = 0; j < N; j++) {
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
}
int main() {
	init();
	int n, i;
	while (cin >> num[0] >> num[1] >> num[2] && num[0] + num[1] + num[2] > 0) {
		init();
		for (i = 1; i < N; i++) {
			if (c1[i] == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
