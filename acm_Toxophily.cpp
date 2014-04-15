#include <cstdio>
#include <cmath>


int T;
double x, y, v;
const double PI = acos(-1);
const double eps = 1e-11;
const double G = 9.8;
double mid_left, mid_right, mid;
double left, right;
double max_y;
double cal(double angle) {
	return x * (tan(angle) - x / 2 / G / v / v / cos(angle) / cos(angle));
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf", &x, &y, &v);
		left = 0;
		right = PI / 2 - eps;
		while (right - left > eps) {
			mid_left = (left * 2 + right) / 3;
			mid_right = (left + right * 2) / 3;
			if ((max_y = cal(mid_left)) > cal(mid_right)) {
				right = mid_right;
			} else {
				left = mid_left;
			}
		}
		if (max_y < y) {
			printf("-1\n");
			continue;
		}
		printf("\n%.10lf************\n", max_y);
		left = 0;
		while (right - left > eps) {
			mid = (left + right) / 2;
			if (cal(mid) > y) {
				right = mid;
			} else {
				left = mid;
			}
		}
		printf("%.6lf\n", mid);

	}
	return 0;
}
