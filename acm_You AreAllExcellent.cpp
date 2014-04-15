#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	double x, y;
	double c;
} Point;
#define N 200
Point points[N];
int n, i, j, k;
double x, y;
int cmp(const void* a, const void* b) {
	return ((Point*) a)->c < ((Point*) b)->c ? 1 : -1;//请格外注意double  应该是 1 和-1
}
int main() {
	while (scanf("%d", &n) != EOF && n > 0) {
		for (i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			points[i].c = x / sqrt(x * x + y * y);//请不要在cmp中比较大小，因为会被重复调用
			points[i].x = x;
			points[i].y = y;
		}
		qsort(points, n, sizeof(points[0]), cmp);
		for (i = 0; i < n - 1; i++) {
			printf("%.1lf %.1lf ", points[i].x, points[i].y);
		}
		printf("%.1lf %.1lf\n", points[i].x, points[i].y);
	}
	return 0;
}
