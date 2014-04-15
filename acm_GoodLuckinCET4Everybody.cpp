#include <iostream>
using namespace std;
#define N  1002
char gm[N] = { 'N' };
void init() {
	int i = 0, j, k;
	for (i = 1; i < N; i <<= 1) {
		gm[i] = 'P';
	}
	for (i = 0; i < N; i++) {
		if (gm[i] == 'P' || gm[i] == 'N')
			continue;
		for (j = 0; (k = i - (1 << j)) >= 0; j++) {
			if (gm[k] == 'N') {
				gm[i] = 'P';
				goto label;
			}
		}
		gm[i] = 'N';
		label: ;
	}
}
int n;
int main() {
	init();
	while (cin >> n) {
		if (gm[n] == 'P') {
			cout << "Kiki" << endl;
		} else {
			cout << "Cici" << endl;
		}
	}
	return 0;
}
