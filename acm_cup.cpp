#include <cstdio>
#include <cmath>

int T;
double r, R, H, V;
double left, right, mid;
const double PI = acos(-1);
double cal(double h) {
	return h * PI / 3
			* (r * r + (r + (R - r) / H * h) * (2 * r + (R - r) / H * h));
}
const double eps = 1e-9;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf%lf", &r, &R, &H, &V);
		left = 0;
		right = H;
		while (right - left > eps) {
			mid = (left + right) / 2;
			if (cal(mid) > V) {
				right = mid;
			} else {
				left = mid;
			}
		}
		printf("%6lf\n", mid);
	}
	return 0;
}
