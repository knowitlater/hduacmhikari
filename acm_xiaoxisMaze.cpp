#include <iostream>
using namespace std;
#define N 100001
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
bool ok = true;
bool inMaze[N];
void inMazeInit() {
	int i;
	for (i = 0; i < N; i++) {
		inMaze[i] = false;
	}
}
int main() {
	ok = true;
	dsInit();
	inMazeInit();
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) {
			return 0;
		}
		if (a == 0 && b == 0) {
			int count = 0;
			for (i = 0; i < N; i++) {
				if (ds[i] == i && inMaze[i]) {
					count++;
				}
			}
			if (count > 1) {
				ok = false;
			}
			if (ok) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
			ok = true;
			dsInit();
			inMazeInit();
			continue;
		}
		if (ok) {
			if (findHead(a - 1) == findHead(b - 1)) {
				ok = false;
			} else {
				join(a - 1, b - 1);
				inMaze[a - 1] = inMaze[b - 1] = true;
			}
		}

	}
	return 0;
}
