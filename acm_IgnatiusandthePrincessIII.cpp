#include <iostream>
using namespace std;
#define N    301
unsigned int c1[N + 1], c2[N + 1];
void init() {
	int i, j, k;
	for (i = 0; i < N; i++) {
		c1[i] = 1;
		c2[i] = 0;
	}
	for (i = 2; i <=N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k + j < N; k += i) {
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
	int n;
	while (cin >> n && n!=0) {
		cout << c1[n] << endl;
	}
	return 0;
}
