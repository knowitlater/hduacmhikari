#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	int v1, v2; //dingdian
	double weight;
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
int cnt;
//return if they are in the same set
int join(int aa, int bb) {
	int fa = find(aa);
	int fb = find(bb);
	if (fa != fb) {
		ds[fa] = fb;
		cnt--;
		return 1;
	} else {
		return 0;
	}
}
int n, a, b, i, j, k, m;
int edgeN;
int cmp(const void* x, const void* y) {
	return ((Edge*) x)->weight > ((Edge*) y)->weight ? 1 : -1;
}
double totalweight;
typedef struct {
	int x, y;
} Point;
Point points[N];
int T;
int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		dsInit(n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &points[i].x, &points[i].y);
		}
		m = 0;
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				edges[m].v1 = i;
				edges[m].v2 = j;
				edges[m].weight = hypot(points[i].x - points[j].x,
						points[i].y - points[j].y);
				m++;
			}
		}
		qsort(edges, m, sizeof(edges[0]), cmp);
		totalweight = 0;
		cnt = n;
		for (i = 0; i < m; i++) {
			if (edges[i].weight >= 10 && edges[i].weight <= 1000
					&& join(edges[i].v1, edges[i].v2)) {
				totalweight += edges[i].weight;
			}
		}
		if (cnt > 1) {
			printf("oh!\n");
		} else {
			printf("%.1lf\n", totalweight * 100);
		}
	}
	return EXIT_SUCCESS;
}
