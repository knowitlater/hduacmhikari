#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10001
int T, n, m, i;
int F;
int kk[N];
double left, right, x;
int y;
double PI = acos(-1);
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &F);
		F++;
		right = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", kk + i);
			kk[i] *= kk[i];
			right += kk[i];
		}
		right /= F;
		left = 1e-7;
		x = right / 2 + left / 2;
		while (right - left > 1e-6) {
			y = 0;
			for (i = 0; i < n; i++) {
				y += (int) (kk[i] / x);
			}
			if (y >= F) {
				left = x;
			} else {
				right = x;
			}
			x = right / 2 + left / 2;
		}
		printf("%.4lf\n", PI * x);
	}
	return 0;
}
