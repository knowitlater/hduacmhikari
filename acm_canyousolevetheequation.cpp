#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int T, i, j, k, m;
double x, y;
double right, left;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lf", &y);
		if (y < 6 || y > 807020306) {
			printf("No solution!\n");
			continue;
		}
		right = 100;
		left = 0;
		x = sqrt(sqrt(y)) / 8;
		while (right - left > 1e-10) {
			if ((6 + x * (3 + x * (2 + x * (7 + x * 8)))) < y) {
				left = x;
			} else {
				right = x;
			}
			x = (left + right) / 2;
		}
		printf("%.4lf\n", x);
	}

	return 0;
}
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//int T, i, j, k, m;
//double x, y;
//double right, left;
//int main() {
//	x = 100;
//	y = ((6 + x * (3 + x * (2 + x * (7 + x * 8)))));
//	printf("%.10lf\n", y);
//	return 0;
//}
