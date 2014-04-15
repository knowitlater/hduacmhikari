#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct {
	unsigned int javaBean, catFood;
	double rate;
} Room;
#define N 10000
Room r[N];
int n, i, j, k;
int m;
double sum;
int cmp(const void* a, const void* b) {
	return ((Room*) a)->rate > ((Room*) b)->rate ? -1 : 1;
}
int main() {
	while (cin >> m >> n && m != -1 && n != -1) {
		for (i = 0; i < n; i++) {
			cin >> r[i].javaBean >> r[i].catFood;
			r[i].rate = (double) r[i].javaBean / r[i].catFood;
		}
		qsort(r, n, sizeof(r[0]), cmp);
		for (sum = 0, i = 0; i < n; i++) {
			if (r[i].catFood <= m) {
				sum += r[i].javaBean;
				m -= r[i].catFood;
			} else {
				sum += (double) r[i].javaBean * m / r[i].catFood;
				m = 0;
			}
		}
		printf("%.3lf\n", sum);
	}
}
