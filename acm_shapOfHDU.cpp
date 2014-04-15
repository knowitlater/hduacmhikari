//============================================================================
// Name        : acm_shapOfHDU.cpp
// Author      : Hikari Vanish
// Version     :
// Copyright   : dszjs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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
int is_convex(int n, point* p) {
	int i, s[3] = { 1, 1, 1 };
	for (i = 0; i < n && s[1] | s[2]; i++)
		s[_sign(xmult(p[(i + 1) % n], p[(i + 2) % n], p[i]))] = 0;
	return s[1] | s[2];
}
#define N 10001
point points[N];
int n, i, j;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
		}
		if(is_convex(n,points)){
			cout << "convex"<< endl;
		}else{
			cout << "concave"<< endl;
		}
	}
	return 0;
}
