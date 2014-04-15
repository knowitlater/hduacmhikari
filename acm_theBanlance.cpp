
#include <iostream>
#include <cmath>
using namespace std;
#define N 103
int n;
int i, j, k;
int w[N];
int sum;
#define M 10004
int c1[M], c2[M];
int cnt, cc[M];
int main() {
	while (cin >> n) {
		sum = 0;
		for (i = 1; i <= n; i++) {
			cin >> w[i];
			sum += w[i];
		}
		for (i = 0; i <= sum; i++)
			c1[i] = c2[i] = 0;
		for (i = 0; i <= 1; i++) {
			c1[i * w[1]] = 1;
		}
		for (i = 2; i <= n; i++) {
			for (j = 0; j <= sum; j++) {
				for (k = 0; k <= w[i]; k += w[i]) {
					c2[k + j] += c1[j];
					c2[(int)abs(k - j)] += c1[j];
				}
			}
			for (j = 0; j <= sum; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cnt = 0;
		for (i = 1; i < sum; i++) {
			if (c1[i] == 0) {
				cc[cnt++] = i;
			}
		}
		cout << cnt << endl;
		for (i = 0; i < cnt; i++) {
			if (i < cnt - 1) {
				cout << cc[i] << " ";
			} else {
				cout << cc[i] << endl;
			}

		}

	}
	return 0;
}
