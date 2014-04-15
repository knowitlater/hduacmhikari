#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int T, i, j, k, m;
double x1, x2, y;
double right, left;
double tmp;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lf", &y);
		right = 100;
		left = 0;
		x1 = 33;
		x2 = 66;
		while (x2 - x1 > 1e-12) {
			tmp = x1 * (x1 * (5 + x1 * (7 + x1 * x1 * x1 * (8 + x1 * 6))) - y);
			if (tmp
					< x2
							* (x2 * (5 + x2 * (7 + x2 * x2 * x2 * (8 + x2 * 6)))
									- y)) {
				right = x2;
			} else {
				left = x1;
			}
			x1 = (2 * left + right) / 3;
			x2 = (left + 2 * right) / 3;
		}
		printf("%.4lf\n", tmp);
	}

	return 0;
}
