#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAXN 1000
#define offset 10000
#define eps 1e-9
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
struct point {
	 __int64 x, y;
};
struct line {
	point a, b;
};
 __int64 xmult(point p0, point p1, point p2) {
	return (p2.x - p0.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p0.y);
}
int T, n, i, j;
point p0, p1, p2;
point tmp;
 __int64 s = 0;
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> p0.x >> p0.y;
		cin >> p1.x >> p1.y;
		tmp.x = tmp.y = 0;
		s = 0;
		for (i = 2; i < n; i++) {
			cin >> p2.x >> p2.y;
			s += xmult(p0, p1, p2);
			tmp.x += (p0.x + p1.x + p2.x) * xmult(p0, p1, p2);
			tmp.y += (p0.y + p1.y + p2.y) * xmult(p0, p1, p2);
			p1 = p2;
		}
		printf("%.2lf %.2lf\n", (double) ((long double) tmp.x / s / 3),
				(double) ((long double) tmp.y / s / 3));
	}
	return 0;
}
