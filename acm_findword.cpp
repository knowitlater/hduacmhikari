
#include <iostream>
using namespace std;

int n, i, j, k;
int num[27];
unsigned int sum;
unsigned int c1[420], c2[420];
int main() {
	cin >> n;

	while (n--) {
		sum = 0;
		for (i = 1; i <= 26; i++) {
			cin >> num[i];
			sum += i * num[i];
		}
		for (i = 0; i <= 50; i++) {
			c1[i] = c2[i] = 0;
		}
		for (i = 0; i <= num[1]; i++) {
			c1[i] = 1;
		}
		for (i = 2; i <= 26; i++) {
			for (j = 0; j <= 50; j++) {
				for (k = 0; k <= i * num[i]; k += i) {
					c2[j + k] += c1[j];
				}
			}
			for (j = 0; j <= 50; j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		unsigned int cnt = 0;
		for (i = 1; i <= 50; i++) {
			cnt += c1[i];
		}
		cout << cnt << endl;
	}
	return 0;
}
