#include <iostream>
using namespace std;

int n, m, i, j, k;
int sum;
#define N 110
int a[N], b[N];
#define M 110
unsigned __int64 c1[M], c2[M];
int main() {
	while (cin >> n >> m) {
		for (i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
		}
		for (i = 0; i <= m; i++) {
			c1[i] = c2[i] = 0;
		}
		for (i = a[1]; i <= b[1]; i++) {
			c1[i] = 1;
		}

		for (i = 2; i <= n; i++) {
			for (j = 0; j <= m; j++) {
				for (k = a[i]; k <= b[i] && k + j < M; k++) {
					c2[k + j] += c1[j];
				}
			}
			for (j = 0; j <= m; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[m] << endl;
	}
	return 0;
}
