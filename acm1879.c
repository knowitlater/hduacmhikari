#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int v1, v2; //dingdian
	int weight;
} Edge;
#define N 101
Edge edges[N * (N - 1) / 2];
int ds[N];
void dsInit(int n) {
	int i;
	for (i = 0; i < n; i++) {
		ds[i] = i;
	}
}
int find(int x) {
	int tmp1, tmp2 = x;
	while (x != ds[x]) {
		x = ds[x];
	}
	while (tmp2 != x) {
		tmp1 = tmp2;
		tmp2 = ds[tmp2];
		ds[tmp1] = x;
	}
	return x;
}
//return if they are in the same set
int join(int aa, int bb) {
	int fa = find(aa);
	int fb = find(bb);
	if (fa != fb) {
		ds[fa] = fb;
		return 1;
	} else {
		return 0;
	}
}
int n, a, b, i, j, k, m;
int edgeN;
int cmp(const void* x, const void* y) {
	return ((Edge*) x)->weight - ((Edge*) y)->weight;
}
int totalweight;
int isBuilt;
int main(void) {
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		dsInit(n);
		edgeN = n * (n - 1) / 2;
		for (i = 0; i < edgeN; i++) {
			scanf("%d%d%d%d", &edges[i].v1, &edges[i].v2, &edges[i].weight,
					&isBuilt);
			if (isBuilt)
				join(edges[i].v1 - 1, edges[i].v2 - 1);
		}
		qsort(edges, edgeN, sizeof(edges[0]), cmp);
		totalweight = 0;
		for (i = 0; i < edgeN; i++) {
			if (join(edges[i].v1 - 1, edges[i].v2 - 1)) {
				totalweight += edges[i].weight;
			}
		}
		printf("%d\n", totalweight);
	}
	return EXIT_SUCCESS;
}
