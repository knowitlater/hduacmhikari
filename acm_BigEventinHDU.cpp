#include <iostream>
using namespace std;
#define N 500
int n, m;
unsigned int value[N], num[N];
unsigned sum;
#define M 250001
unsigned int c1[M], c2[M];
int i, j, k;
unsigned int tmp1, tmp2;
int main() {
	while (cin >> n && n > 0) {
		sum = 0;
		for (i = 0; i < n; i++) {
			cin >> value[i] >> num[i];
			sum += value[i] * num[i];
		}
		for (i = 0; i < M; i++) {
			c1[i] = 0;
			c2[i] = 0;
		}
		for (i = 0; i <= num[0]; i++) {
			c1[i * value[0]] = 1;
		}
		tmp1 = 0;
		for (i = 2; i <= n; i++) {
			tmp1 += num[i - 2] * value[i - 2];
			tmp2 = num[i - 1] * value[i - 1];
			for (j = 0; j <= tmp1 && j < M; j++) {
				for (k = 0; k <= tmp2 && j + k < M; k += value[i - 1]) {
					c2[j + k] += c1[j];
				}
			}
			for (j = 0; j < M; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		for (i = sum / 2; i >=0; i--) {
			if (c1[i] > 0) {
				cout << sum - i << " " << i << endl;
				break;
			}
		}
	}
	return 0;
}
