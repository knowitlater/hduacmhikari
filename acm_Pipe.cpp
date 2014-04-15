//============================================================================
// Name        : acm_Pipe.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MAXN 1000
#define offset 10000
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
struct point {
	double x, y;
};
struct line {
	point a, b;
};

double xmult(point p1, point p2, point p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double xmult(double x1, double y1, double x2, double y2, double x0, double y0) {
	return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
int dots_inline(point p1, point p2, point p3) {
	return zero(xmult(p1, p2, p3));
}
int dot_online_in(point p, line l) {
	return zero(xmult(p, l.a, l.b)) && (l.a.x - p.x) * (l.b.x - p.x) < eps
			&& (l.a.y - p.y) * (l.b.y - p.y) < eps;
}
int dot_online_in(point p, point l1, point l2) {
	return zero(xmult(p, l1, l2)) && (l1.x - p.x) * (l2.x - p.x) < eps
			&& (l1.y - p.y) * (l2.y - p.y) < eps;
}
int dot_online_in(double x, double y, double x1, double y1, double x2,
		double y2) {
	return zero(xmult(x, y, x1, y1, x2, y2)) && (x1 - x) * (x2 - x) < eps
			&& (y1 - y) * (y2 - y) < eps;
}
int same_side(point p1, point p2, line l) {
	return xmult(l.a, p1, l.b) * xmult(l.a, p2, l.b) > eps;
}
int same_side(point p1, point p2, point l1, point l2) {
	return xmult(l1, p1, l2) * xmult(l1, p2, l2) > eps;
}
int intersect_in(line u, line v) {
	if (!dots_inline(u.a, u.b, v.a) || !dots_inline(u.a, u.b, v.b))
		return !same_side(u.a, u.b, v) && !same_side(v.a, v.b, u);
	return dot_online_in(u.a, v) || dot_online_in(u.b, v)
			|| dot_online_in(v.a, u) || dot_online_in(v.b, u);
}
int intersect_in(point u1, point u2, point v1, point v2) {
	if (!dots_inline(u1, u2, v1) || !dots_inline(u1, u2, v2))
		return !same_side(u1, u2, v1, v2) && !same_side(v1, v2, u1, u2);
	return dot_online_in(u1, v1, v2) || dot_online_in(u2, v1, v2)
			|| dot_online_in(v1, u1, u2) || dot_online_in(v2, u1, u2);
}
#define K 100
typedef point Pipe[K];
#define N 30
Pipe pipes[N];
int k[N];
int n, i, j, m, a, b;
int main() {
	while (cin >> n) {
		for (i = 0; i < n; i++) {
			cin >> k[i];
			for (j = 0; j < k[i]; j++) {
				cin >> pipes[i][j].x >> pipes[i][j].y;
			}
		}
		for (i = 0; i < n - 1; i++) {
			for (m = i + 1; m < n; m++) {
				for (a = 0; a < k[i] - 1; a++) {
					for (b = 0; b < k[m] - 1; b++) {
						if (intersect_in(pipes[i][a], pipes[i][a + 1],
								pipes[m][b], pipes[m][b + 1])) {
							cout << "Yes" << endl;
							goto label;
						}
					}
				}
			}
		}
		cout << "No" << endl;
		label: ;
	}
	return 0;
}
