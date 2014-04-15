#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 501
int ll[N], mm[N], nn[N], ln[N * N];
int ok = 0;
int n, m, l, s, x;
int i, j, k;
int tmp1;
int tmp2;
int ss;
int cases = 1;
int binSearch(const int *Array, int start, int end, int key) {
	int left, right;
	int mid;
	left = start;
	right = end;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key < Array[mid]) {
			right = mid - 1;
		} else if (key > Array[mid]) {
			left = mid + 1;
		} else
			return mid;
	}
	return -1;
}
int main() {
	while (scanf("%d%d%d", &l, &n, &m) == 3) {
		for (i = 0; i < l; i++) {
			scanf("%d", ll + i);
		}
		for (i = 0; i < n; i++) {
			scanf("%d", nn + i);
		}
		for (i = 0; i < m; i++) {
			scanf("%d", mm + i);
		}
		k = 0;
		for (i = 0; i < l; i++) {
			for (j = 0; j < n; j++) {
				ln[k++] = ll[i] + nn[j];
			}
		}
		sort(ln, ln + k);
		sort(mm, mm + m);
		scanf("%d", &s);
		printf("Case %d:\n", cases++);
		while (s--) {
			scanf("%d", &x);
			ok = 0;
			for (i = 0; i <m; i++) {
				tmp1 = x - mm[i];
				if (binSearch(ln, 0, k - 1, tmp1) != -1) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
