#include <iostream>
using namespace std;
#define N 1001
int ds[N];
void dsInit() {
	int i = 0;
	for (i = 0; i < N; i++) {
		ds[i] = i;
	}
}
int T, n, m, i, j, k, a, b;
int findHead(int kk) {
	while (kk != ds[kk]) {
		kk = ds[kk];
	}
	return kk;
}
void join(int aa, int bb) {
	ds[findHead(aa)] = findHead(bb);
}
int dsCount() {
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		if (ds[i] == i) {
			sum++;
		}
	}
	return sum;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		dsInit();
		while (m--) {
			cin >> a >> b;
			join(a - 1, b - 1);
		}
		cout << dsCount() << endl;

	}
	return 0;
}
