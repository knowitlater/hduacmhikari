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
int n, a, b, i, j, k, m, q;
int edgeN;
int cmp(const void* x, const void* y) {
	return ((Edge*) x)->weight - ((Edge*) y)->weight;
}
int totalweight;
int main(void) {
	while(scanf("%d", &n)!=EOF){
	dsInit(n);
	m = 0;
	edgeN = n * (n - 1) / 2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &k);
			if (j > i) {
				edges[m].v1 = i;
				edges[m].v2 = j;
				edges[m].weight = k;
				m++;
			}
		}

	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &a, &b);
		join(a - 1, b - 1);
	}
	qsort(edges, edgeN, sizeof(edges[0]), cmp);
	totalweight = 0;
	for (i = 0; i < edgeN; i++) {
		if (join(edges[i].v1, edges[i].v2)) {
			totalweight += edges[i].weight;
		}
	}
	printf("%d\n", totalweight);
	}
	return EXIT_SUCCESS;
}
