#include <stdio.h>
#define N 1001
int ds[N];
int T, n, m, i, j, k, a, b;
void dsInit() {
	for (i = 0; i < N; i++) {
		ds[i] = i;
	}
}

int findHead(int kk) {
	while (kk != ds[kk]) {
		kk = ds[kk];
	}
	return kk;
}
int ok = 1;
int inMaze[N];
void inMazeInit() {
	for (i = 0; i < N; i++) {
		inMaze[i] = 0;
	}
}
int cc = 1;
int countt;
int aa, bb;
int main() {
	ok = 1;
	dsInit();
	inMazeInit();
	while (1) {
		scanf("%d%d", &a, &b);
		if (a < 0 && b < 0) {
			return 0;
		}
		if (a == 0 && b == 0) {
			countt = 0;
			for (i = 0; i < N; i++) {
				if (ds[i] == i && inMaze[i]) {
					countt++;
				}
			}
			if (countt > 1) {
				ok = 0;
			}
			if (ok) {
				printf("Case %d is a tree.\n", cc++);
			} else {
				printf("Case %d is not a tree.\n", cc++);
			}
			ok = 1;
			dsInit();
			inMazeInit();
			continue;
		}
		if (ok) {
			if (b - 1 != ds[b - 1] || findHead(a - 1) == b - 1) {
				ok = 0;
			} else {
				ds[b - 1] = a - 1;
				inMaze[a - 1] = inMaze[b - 1] = 1;
			}
		}

	}
	return 0;
}
