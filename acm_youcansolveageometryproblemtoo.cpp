#include <iostream>
#include <cmath>
using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point {
	double x, y;
};
double xmult(point p1, point p2, point p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int dots_inline(point p1, point p2, point p3) {
	return zero(xmult(p1, p2, p3));
}
int same_side(point p1, point p2, point l1, point l2) {
	return xmult(l1, p1, l2) * xmult(l1, p2, l2) > eps;
}
int dot_online_in(point p, point l1, point l2) {
	return zero(xmult(p, l1, l2)) && (l1.x - p.x) * (l2.x - p.x) < eps
			&& (l1.y - p.y) * (l2.y - p.y) < eps;
}
int intersect_in(point u1, point u2, point v1, point v2) {
	if (!dots_inline(u1, u2, v1) || !dots_inline(u1, u2, v2))
		return !same_side(u1, u2, v1, v2) && !same_side(v1, v2, u1, u2);
	return dot_online_in(u1, v1, v2) || dot_online_in(u2, v1, v2)
			|| dot_online_in(v1, u1, u2) || dot_online_in(v2, u1, u2);
}
typedef struct {
	point p1, p2;
} Segment;
#define N 100
Segment segments[N];
int n, i, j, sum;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> segments[i].p1.x >> segments[i].p1.y >> segments[i].p2.x
					>> segments[i].p2.y;
		}
		sum = 0;
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				if (intersect_in(segments[i].p1, segments[i].p2, segments[j].p1,
						segments[j].p2)) {
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
