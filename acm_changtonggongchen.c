#include <stdio.h>
#include <stdlib.h>

#define N 1001
int ds[N];
int i, n, m, n, j, k;
int a, b, aa, bb;
int tmp1, tmp2;
int dsCount;
void dsInit() {
	for (i = 0; i < n; i++) {
		ds[i] = i;
	}
}
int find(int x) {
	tmp1 = x;
	while (x != ds[x]) {
		x = ds[x];
	}
	while (tmp1 != x) {
		tmp2 = tmp1;
		tmp1 = ds[tmp1];
		ds[tmp2] = x;
	}
	return x;
}
int main(void) {
	while (scanf("%d%d", &n, &m) == 2) {
		if (n == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			ds[i] = i;
		}
		while (m--) {
			scanf("%d%d", &a, &b);
			aa = find(a - 1);
			bb = find(b - 1);
			if (aa != bb) {
				ds[aa] = bb;
			}
		}
		dsCount = 0;
		for (i = 0; i < n; i++) {
			if (ds[i] == i) {
				dsCount++;
			}
		}
		printf("%d\n", dsCount - 1);
	}
	return EXIT_SUCCESS;
}
